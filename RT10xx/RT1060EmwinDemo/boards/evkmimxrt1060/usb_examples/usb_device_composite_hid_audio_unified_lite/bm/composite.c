/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 - 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "usb_device_config.h"
#include "usb.h"
#include "usb_device.h"

#include "usb_device_hid.h"
#include "usb_device_audio.h"
#include "usb_device_ch9.h"
#include "usb_device_descriptor.h"

#include "composite.h"

#include "fsl_device_registers.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"

#include <stdio.h>
#include <stdlib.h>
#if (defined(FSL_FEATURE_SOC_SYSMPU_COUNT) && (FSL_FEATURE_SOC_SYSMPU_COUNT > 0U))
#include "fsl_sysmpu.h"
#endif /* FSL_FEATURE_SOC_SYSMPU_COUNT */
#if ((defined FSL_FEATURE_SOC_USBPHY_COUNT) && (FSL_FEATURE_SOC_USBPHY_COUNT > 0U))
#include "usb_phy.h"
#endif


#include "fsl_wm8960.h"
#include "pin_mux.h"
#include "fsl_sai.h"
#include "fsl_dmamux.h"
#include "fsl_sai_edma.h"
#include "fsl_codec_common.h"
#include "fsl_codec_adapter.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define OVER_SAMPLE_RATE   (256U)
#define BOARD_DEMO_SAI     SAI1
#define DEMO_SAI_IRQ_TX    SAI1_IRQn
#define DEMO_SAI_IRQ_RX    SAI1_IRQn
#define SAI_UserIRQHandler SAI1_IRQHandler

/* Select Audio/Video PLL (786.48 MHz) as sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_SELECT (2U)
/* Clock pre divider for sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER (0U)
/* Clock divider for sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_DIVIDER (63U)
/* Get frequency of sai1 clock */
#define DEMO_SAI_CLK_FREQ                                                        \
    (CLOCK_GetFreq(kCLOCK_AudioPllClk) / (DEMO_SAI1_CLOCK_SOURCE_DIVIDER + 1U) / \
     (DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER + 1U))

#define BOARD_DEMO_I2C LPI2C1

/* Select USB1 PLL (480 MHz) as master lpi2c clock source */
#define DEMO_LPI2C_CLOCK_SOURCE_SELECT (0U)
/* Clock divider for master lpi2c clock source */
#define DEMO_LPI2C_CLOCK_SOURCE_DIVIDER (5U)
/* Get frequency of lpi2c clock */
#define BOARD_DEMO_I2C_FREQ ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (DEMO_LPI2C_CLOCK_SOURCE_DIVIDER + 1U))

/* DMA */
#define EXAMPLE_DMAMUX        DMAMUX
#define EXAMPLE_DMA           DMA0
#define EXAMPLE_TX_CHANNEL    (0U)
#define EXAMPLE_RX_CHANNEL    (1U)
#define EXAMPLE_SAI_TX_SOURCE kDmaRequestMuxSai1Tx
#define EXAMPLE_SAI_RX_SOURCE kDmaRequestMuxSai1Rx

#define BOARD_SW_GPIO        BOARD_USER_BUTTON_GPIO
#define BOARD_SW_GPIO_PIN    BOARD_USER_BUTTON_GPIO_PIN
#define BOARD_SW_IRQ         BOARD_USER_BUTTON_IRQ
#define BOARD_SW_IRQ_HANDLER BOARD_USER_BUTTON_IRQ_HANDLER
#define BOARD_SW_NAME        BOARD_USER_BUTTON_NAME

/* demo audio data channel */
#define DEMO_AUDIO_DATA_CHANNEL (2U)
/* demo audio bit width */
#define DEMO_AUDIO_BIT_WIDTH kSAI_WordWidth16bits
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void BOARD_InitHardware(void);
void USB_DeviceClockInit(void);
void USB_DeviceIsrEnable(void);
#if USB_DEVICE_CONFIG_USE_TASK
void USB_DeviceTaskFn(void *deviceHandle);
#endif

usb_status_t USB_DeviceCallback(usb_device_handle handle, uint32_t event, void *param);
extern void Init_Board_Audio(void);
extern usb_status_t USB_DeviceHidKeyboardAction(void);
extern char *SW_GetName(void);
extern void USB_AudioCodecTask(void);
extern void USB_DeviceAudioSpeakerStatusReset(void);
extern void USB_DeviceAudioRecorderStatusReset(void);
extern usb_status_t USB_DeviceAudioRecorderSetInterface(usb_device_handle handle,
                                                        uint8_t interface,
                                                        uint8_t alternateSetting);
extern usb_status_t USB_DeviceAudioSpeakerSetInterface(usb_device_handle handle,
                                                       uint8_t interface,
                                                       uint8_t alternateSetting);
extern void USB_AudioSpeakerResetTask(void);
extern usb_status_t USB_DeviceAudioProcessTerminalRequest(uint32_t audioCommand, uint32_t *length, uint8_t **buffer, uint8_t entityOrEndpoint);
/*******************************************************************************
 * Variables
 ******************************************************************************/
extern usb_device_composite_struct_t g_composite;
extern uint8_t audioPlayDataBuff[AUDIO_SPEAKER_DATA_WHOLE_BUFFER_LENGTH * FS_ISO_OUT_ENDP_PACKET_SIZE];
extern uint8_t audioRecDataBuff[AUDIO_RECORDER_DATA_WHOLE_BUFFER_LENGTH * FS_ISO_IN_ENDP_PACKET_SIZE];

volatile bool g_ButtonPress = false;

sai_edma_handle_t txHandle = {0};
edma_handle_t dmaTxHandle  = {0};
sai_edma_handle_t rxHandle = {0};
edma_handle_t dmaRxHandle  = {0};
USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
static uint8_t audioPlayDMATempBuff[FS_ISO_OUT_ENDP_PACKET_SIZE];
USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
static uint8_t audioRecDMATempBuff[FS_ISO_IN_ENDP_PACKET_SIZE];
uint32_t masterClockHz = 0U;
codec_handle_t codecHandle;

wm8960_config_t wm8960Config = {
    .i2cConfig = {.codecI2CInstance = BOARD_CODEC_I2C_INSTANCE, .codecI2CSourceClock = BOARD_CODEC_I2C_CLOCK_FREQ},
    .route     = kWM8960_RoutePlaybackandRecord,
    .rightInputSource = kWM8960_InputDifferentialMicInput2,
    .playSource       = kWM8960_PlaySourceDAC,
    .slaveAddress     = WM8960_I2C_ADDR,
    .bus              = kWM8960_BusI2S,
    .format           = {.mclk_HZ    = 12288000U,
               .sampleRate = kWM8960_AudioSampleRate48KHz,
               .bitWidth   = kWM8960_AudioBitWidth16bit},
    .master_slave     = false,
};
codec_config_t boardCodecConfig = {.codecDevType = kCODEC_WM8960, .codecDevConfig = &wm8960Config};
/* Composite device structure. */
USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
usb_device_composite_struct_t g_composite;
extern volatile bool g_ButtonPress;
extern usb_device_composite_struct_t *g_UsbDeviceComposite;
extern usb_device_composite_struct_t *g_deviceComposite;
extern uint8_t g_UsbDeviceInterface[USB_COMPOSITE_INTERFACE_COUNT];
extern uint32_t totalCount;
USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE) static uint8_t s_SetupOutBuffer[8];
/*******************************************************************************
 * Code
 ******************************************************************************/
/*
 * AUDIO PLL setting: Frequency = Fref * (DIV_SELECT + NUM / DENOM)
 *                              = 24 * (32 + 77/100)
 *                              = 786.48 MHz
 */
const clock_audio_pll_config_t audioPllConfig = {
    .loopDivider = 32,  /* PLL loop divider. Valid range for DIV_SELECT divider value: 27~54. */
    .postDivider = 1,   /* Divider after the PLL, should only be 1, 2, 4, 8, 16. */
    .numerator   = 77,  /* 30 bit numerator of fractional loop divider. */
    .denominator = 100, /* 30 bit denominator of fractional loop divider */
};
extern void WM8960_USB_Audio_Init(void *I2CBase, void *i2cHandle);
extern void WM8960_Config_Audio_Formats(uint32_t samplingRate);

void BOARD_EnableSaiMclkOutput(bool enable)
{
    if (enable)
    {
        IOMUXC_GPR->GPR1 |= IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK;
    }
    else
    {
        IOMUXC_GPR->GPR1 &= (~IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK);
    }
}

void BOARD_SW_IRQ_HANDLER(void)
{
    /* Clear external interrupt flag. */
    GPIO_PortClearInterruptFlags(BOARD_SW_GPIO, 1U << BOARD_SW_GPIO_PIN);
    /* Change state of button. */
    g_ButtonPress = true;
    SDK_ISR_EXIT_BARRIER;
}

void BOARD_USB_AUDIO_KEYBOARD_Init(void)
{
    /* Define the init structure for the input switch pin */
    gpio_pin_config_t sw_config = {
        kGPIO_DigitalInput,
        0,
        kGPIO_IntRisingEdge,
    };

    /* Init input switch GPIO. */
    EnableIRQ(BOARD_SW_IRQ);
    GPIO_PinInit(BOARD_SW_GPIO, BOARD_SW_GPIO_PIN, &sw_config);
    /* Enable GPIO pin interrupt */
    GPIO_PortEnableInterrupts(BOARD_SW_GPIO, 1U << BOARD_SW_GPIO_PIN);
}

char *SW_GetName(void)
{
    return BOARD_SW_NAME;
}


void BOARD_Codec_Init()
{
    CODEC_Init(&codecHandle, &boardCodecConfig);
}

void BOARD_SetCodecMuteUnmute(bool mute)
{
    CODEC_SetMute(&codecHandle, kCODEC_PlayChannelHeadphoneLeft | kCODEC_PlayChannelHeadphoneRight, mute);
}

static void txCallback(I2S_Type *base, sai_edma_handle_t *handle, status_t status, void *userData)
{
    sai_transfer_t xfer = {0};
    if ((g_composite.audioUnified.audioSendTimes >= g_composite.audioUnified.usbRecvTimes) &&
        (g_composite.audioUnified.startPlayHalfFull == 1))
    {
        g_composite.audioUnified.startPlayHalfFull      = 0;
        g_composite.audioUnified.speakerDetachOrNoInput = 1;
    }
    if (g_composite.audioUnified.startPlayHalfFull)
    {
        xfer.dataSize = FS_ISO_OUT_ENDP_PACKET_SIZE;
        xfer.data     = audioPlayDataBuff + g_composite.audioUnified.tdWriteNumberPlay;
        g_composite.audioUnified.audioSendCount += FS_ISO_OUT_ENDP_PACKET_SIZE;
        g_composite.audioUnified.audioSendTimes++;
        g_composite.audioUnified.tdWriteNumberPlay += FS_ISO_OUT_ENDP_PACKET_SIZE;
        if (g_composite.audioUnified.tdWriteNumberPlay >=
            AUDIO_SPEAKER_DATA_WHOLE_BUFFER_LENGTH * FS_ISO_OUT_ENDP_PACKET_SIZE)
        {
            g_composite.audioUnified.tdWriteNumberPlay = 0;
        }
    }
    else
    {
        xfer.dataSize = FS_ISO_OUT_ENDP_PACKET_SIZE;
        xfer.data     = audioPlayDMATempBuff;
    }
    SAI_TransferSendEDMA(base, handle, &xfer);
}

static void rxCallback(I2S_Type *base, sai_edma_handle_t *handle, status_t status, void *userData)
{
    sai_transfer_t xfer = {0};

    if (g_composite.audioUnified.startRec)
    {
        xfer.dataSize = FS_ISO_IN_ENDP_PACKET_SIZE;
        xfer.data     = audioRecDataBuff + g_composite.audioUnified.tdReadNumberRec;
        g_composite.audioUnified.tdReadNumberRec += FS_ISO_IN_ENDP_PACKET_SIZE;
        if (g_composite.audioUnified.tdReadNumberRec >=
            AUDIO_RECORDER_DATA_WHOLE_BUFFER_LENGTH * FS_ISO_IN_ENDP_PACKET_SIZE)
        {
            g_composite.audioUnified.tdReadNumberRec = 0;
        }
    }
    else
    {
        xfer.dataSize = FS_ISO_IN_ENDP_PACKET_SIZE;
        xfer.data     = audioRecDMATempBuff;
    }
    SAI_TransferReceiveEDMA(base, handle, &xfer);
}
void BOARD_USB_Audio_TxRxInit(uint32_t samplingRate)
{
    sai_transceiver_t config;
    SAI_Init(BOARD_DEMO_SAI);
    SAI_TransferTxCreateHandleEDMA(BOARD_DEMO_SAI, &txHandle, txCallback, NULL, &dmaTxHandle);
    SAI_TransferRxCreateHandleEDMA(BOARD_DEMO_SAI, &rxHandle, rxCallback, NULL, &dmaRxHandle);
    /* I2S mode configurations */
    SAI_GetClassicI2SConfig(&config, DEMO_AUDIO_BIT_WIDTH, kSAI_Stereo, kSAI_Channel0Mask);
    SAI_TransferTxSetConfigEDMA(BOARD_DEMO_SAI, &txHandle, &config);
    config.syncMode = kSAI_ModeSync;
    SAI_TransferRxSetConfigEDMA(BOARD_DEMO_SAI, &rxHandle, &config);

#if (defined FSL_FEATURE_SAI_HAS_MCLKDIV_REGISTER && FSL_FEATURE_SAI_HAS_MCLKDIV_REGISTER) || \
    (defined FSL_FEATURE_PCC_HAS_SAI_DIVIDER && FSL_FEATURE_PCC_HAS_SAI_DIVIDER)
    masterClockHz = OVER_SAMPLE_RATE * sampleRate_Hz;
#else
    masterClockHz = DEMO_SAI_CLK_FREQ;
#endif
    /* set bit clock divider */
    SAI_TxSetBitClockRate(BOARD_DEMO_SAI, masterClockHz, samplingRate, DEMO_AUDIO_BIT_WIDTH, DEMO_AUDIO_DATA_CHANNEL);
    SAI_RxSetBitClockRate(BOARD_DEMO_SAI, masterClockHz, samplingRate, DEMO_AUDIO_BIT_WIDTH, DEMO_AUDIO_DATA_CHANNEL);
}
void BOARD_DMA_EDMA_Config()
{
    edma_config_t dmaConfig = {0};
    EDMA_GetDefaultConfig(&dmaConfig);
    EDMA_Init(EXAMPLE_DMA, &dmaConfig);
    EDMA_CreateHandle(&dmaTxHandle, EXAMPLE_DMA, EXAMPLE_TX_CHANNEL);
    EDMA_CreateHandle(&dmaRxHandle, EXAMPLE_DMA, EXAMPLE_RX_CHANNEL);

    DMAMUX_Init(EXAMPLE_DMAMUX);
    DMAMUX_SetSource(EXAMPLE_DMAMUX, EXAMPLE_TX_CHANNEL, (uint8_t)EXAMPLE_SAI_TX_SOURCE);
    DMAMUX_EnableChannel(EXAMPLE_DMAMUX, EXAMPLE_TX_CHANNEL);
    DMAMUX_SetSource(EXAMPLE_DMAMUX, EXAMPLE_RX_CHANNEL, (uint8_t)EXAMPLE_SAI_RX_SOURCE);
    DMAMUX_EnableChannel(EXAMPLE_DMAMUX, EXAMPLE_RX_CHANNEL);
}

void BOARD_DMA_EDMA_Enable_Audio_Interrupts()
{
    /* Enable interrupt to handle FIFO error */
    SAI_TxEnableInterrupts(BOARD_DEMO_SAI, kSAI_FIFOErrorInterruptEnable);
    SAI_RxEnableInterrupts(BOARD_DEMO_SAI, kSAI_FIFOErrorInterruptEnable);
    EnableIRQ(DEMO_SAI_IRQ_TX);
    EnableIRQ(DEMO_SAI_IRQ_RX);
}

void BOARD_DMA_EDMA_Start()
{
    sai_transfer_t xfer = {0};
    memset(audioPlayDMATempBuff, 0, FS_ISO_OUT_ENDP_PACKET_SIZE);
    memset(audioRecDMATempBuff, 0, FS_ISO_IN_ENDP_PACKET_SIZE);
    xfer.dataSize = FS_ISO_OUT_ENDP_PACKET_SIZE;
    xfer.data     = audioPlayDMATempBuff;
    SAI_TransferSendEDMA(BOARD_DEMO_SAI, &txHandle, &xfer);
    xfer.dataSize = FS_ISO_IN_ENDP_PACKET_SIZE;
    xfer.data     = audioRecDMATempBuff;
    SAI_TransferReceiveEDMA(BOARD_DEMO_SAI, &rxHandle, &xfer);
}

/*Initialize audio interface and codec.*/
void Init_Board_Audio(void)
{
    usb_echo("Init Audio SAI and CODEC\r\n");

    BOARD_USB_AUDIO_KEYBOARD_Init();

    BOARD_DMA_EDMA_Config();
    BOARD_USB_Audio_TxRxInit(AUDIO_SAMPLING_RATE);
    BOARD_Codec_Init();
    BOARD_DMA_EDMA_Enable_Audio_Interrupts();
    BOARD_DMA_EDMA_Start();
}

void SAI_UserTxIRQHandler(void)
{
    /* Clear the FEF flag */
    SAI_TxClearStatusFlags(BOARD_DEMO_SAI, kSAI_FIFOErrorFlag);
    SAI_TxSoftwareReset(BOARD_DEMO_SAI, kSAI_ResetTypeFIFO);
    /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
        exception return operation might vector to incorrect interrupt */
    __DSB();
}

void SAI_UserRxIRQHandler(void)
{
    SAI_RxClearStatusFlags(BOARD_DEMO_SAI, kSAI_FIFOErrorFlag);
    SAI_RxSoftwareReset(BOARD_DEMO_SAI, kSAI_ResetTypeFIFO);
    /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
        exception return operation might vector to incorrect interrupt */
    __DSB();
}

void SAI_UserIRQHandler(void)
{
    if (BOARD_DEMO_SAI->TCSR & kSAI_FIFOErrorFlag)
    {
        SAI_UserTxIRQHandler();
    }

    if (BOARD_DEMO_SAI->RCSR & kSAI_FIFOErrorFlag)
    {
        SAI_UserRxIRQHandler();
    }
}

void USB_OTG1_IRQHandler(void)
{
    USB_DeviceEhciIsrFunction(g_composite.deviceHandle);
}

void USB_OTG2_IRQHandler(void)
{
    USB_DeviceEhciIsrFunction(g_composite.deviceHandle);
}

void USB_DeviceClockInit(void)
{
    usb_phy_config_struct_t phyConfig = {
        BOARD_USB_PHY_D_CAL,
        BOARD_USB_PHY_TXCAL45DP,
        BOARD_USB_PHY_TXCAL45DM,
    };

    if (CONTROLLER_ID == kUSB_ControllerEhci0)
    {
        CLOCK_EnableUsbhs0PhyPllClock(kCLOCK_Usbphy480M, 480000000U);
        CLOCK_EnableUsbhs0Clock(kCLOCK_Usb480M, 480000000U);
    }
    else
    {
        CLOCK_EnableUsbhs1PhyPllClock(kCLOCK_Usbphy480M, 480000000U);
        CLOCK_EnableUsbhs1Clock(kCLOCK_Usb480M, 480000000U);
    }
    USB_EhciPhyInit(CONTROLLER_ID, BOARD_XTAL0_CLK_HZ, &phyConfig);
}
void USB_DeviceIsrEnable(void)
{
    uint8_t irqNumber;

    uint8_t usbDeviceEhciIrq[] = USBHS_IRQS;
    irqNumber                  = usbDeviceEhciIrq[CONTROLLER_ID - kUSB_ControllerEhci0];

    /* Install isr, set priority, and enable IRQ. */
    NVIC_SetPriority((IRQn_Type)irqNumber, USB_DEVICE_INTERRUPT_PRIORITY);
    EnableIRQ((IRQn_Type)irqNumber);
}
#if USB_DEVICE_CONFIG_USE_TASK
void USB_DeviceTaskFn(void *deviceHandle)
{
    USB_DeviceEhciTaskFunction(deviceHandle);
}
#endif

/*!
 * @brief USB device callback function.
 *
 * This function handles the usb device specific requests.
 *
 * @param handle		  The USB device handle.
 * @param event 		  The USB device event type.
 * @param param 		  The parameter of the device specific request.
 *
 * @return A USB error code or kStatus_USB_Success.
 */
usb_status_t USB_DeviceCallback(usb_device_handle handle, uint32_t event, void *param)
{
    usb_status_t error = kStatus_USB_Error;
    uint8_t *temp8     = (uint8_t *)param;
    uint8_t count      = 0U;

    switch (event)
    {
        case kUSB_DeviceEventBusReset:
        {
            /* USB bus reset signal detected */
            /* Initialize the control IN and OUT pipes */
            for (count = 0U; count < USB_DEVICE_INTERFACE_COUNT; count++)
            {
                g_composite.currentInterfaceAlternateSetting[count] = 0U;
            }
            USB_DeviceControlPipeInit(handle);
            g_composite.attach               = 0U;
            g_composite.currentConfiguration = 0U;
#if (defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)) || \
    (defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U))
            /* Get USB speed to configure the device, including max packet size and interval of the endpoints. */
            if (kStatus_USB_Success == USB_DeviceGetStatus(handle, kUSB_DeviceStatusSpeed, &g_composite.speed))
            {
                USB_DeviceSetSpeed(g_composite.speed);
            }
#endif
        }
        break;
        case kUSB_DeviceEventSetConfiguration:
            if (0U == (*temp8))
            {
                g_composite.attach               = 0U;
                g_composite.currentConfiguration = 0U;
            }
            else if (USB_COMPOSITE_CONFIGURE_INDEX == (*temp8))
            {
                g_composite.attach               = 1U;
                g_composite.currentConfiguration = *temp8;
                USB_DeviceAudioUnifiedSetConfigure(handle, *temp8);
                USB_DeviceHidKeyboardSetConfigure(handle, *temp8);
                error = kStatus_USB_Success;
            }
            else
            {
                error = kStatus_USB_InvalidRequest;
            }
            break;
        case kUSB_DeviceEventSetInterface:
            if (g_composite.attach)
            {
                uint8_t interface        = (uint8_t)(*temp8);
                uint8_t alternateSetting = (uint8_t)g_UsbDeviceInterface[interface];
                if (USB_AUDIO_RECORDER_STREAM_INTERFACE_INDEX == interface)
                {
                    if (g_composite.audioUnified.currentInterfaceAlternateSetting[interface] != alternateSetting)
                    {
                        if (g_composite.audioUnified.currentInterfaceAlternateSetting[interface] != alternateSetting)
                        {
                            if (g_composite.audioUnified.currentInterfaceAlternateSetting[interface])
                            {
                                USB_DeviceDeinitEndpoint(
                                    g_composite.deviceHandle,
                                    USB_AUDIO_RECORDER_STREAM_ENDPOINT |
                                        (USB_IN << USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_SHIFT));
                            }
                            else
                            {
                                USB_DeviceAudioRecorderStatusReset();
                                USB_DeviceAudioRecorderSetInterface(handle, interface, alternateSetting);
                            }
                            g_composite.audioUnified.currentInterfaceAlternateSetting[interface] = alternateSetting;
                        }
                    }
                }
                else if (USB_AUDIO_SPEAKER_STREAM_INTERFACE_INDEX == interface)
                {
                    if (g_composite.audioUnified.currentInterfaceAlternateSetting[interface] != alternateSetting)
                    {
                        if (g_composite.audioUnified.currentInterfaceAlternateSetting[interface])
                        {
                            USB_DeviceDeinitEndpoint(g_composite.deviceHandle,
                                                     USB_AUDIO_SPEAKER_STREAM_ENDPOINT |
                                                         (USB_OUT << USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_SHIFT));
                        }
                        else
                        {
                            USB_DeviceAudioSpeakerStatusReset();
                            USB_DeviceAudioSpeakerSetInterface(handle, interface, alternateSetting);
                        }
                        g_composite.audioUnified.currentInterfaceAlternateSetting[interface] = alternateSetting;
                    }
                }
                error = kStatus_USB_Success;
            }
            break;
        default:
            break;
    }

    return error;
}

/*!
 * @brief Get the setup packet buffer.
 *
 * This function provides the buffer for setup packet.
 *
 * @param handle The USB device handle.
 * @param setupBuffer The pointer to the address of setup packet buffer.
 *
 * @return A USB error code or kStatus_USB_Success.
 */
usb_status_t USB_DeviceGetSetupBuffer(usb_device_handle handle, usb_setup_struct_t **setupBuffer)
{
    static uint32_t compositeSetup[2];
    if (NULL == setupBuffer)
    {
        return kStatus_USB_InvalidParameter;
    }
    *setupBuffer = (usb_setup_struct_t *)&compositeSetup;
    return kStatus_USB_Success;
}

/*!
 * @brief Get the vendor request data buffer.
 *
 * This function gets the data buffer for vendor request.
 *
 * @param handle The USB device handle.
 * @param setup The pointer to the setup packet.
 * @param length The pointer to the length of the data buffer.
 * @param buffer The pointer to the address of setup packet data buffer.
 *
 * @return A USB error code or kStatus_USB_Success.
 */
usb_status_t USB_DeviceGetVendorReceiveBuffer(usb_device_handle handle,
                                              usb_setup_struct_t *setup,
                                              uint32_t *length,
                                              uint8_t **buffer)
{
    return kStatus_USB_Error;
}

/*!
 * @brief Audio vendor specific callback function.
 *
 * This function handles the CDC vendor specific requests.
 *
 * @param handle The USB device handle.
 * @param setup The pointer to the setup packet.
 * @param length The pointer to the length of the data buffer.
 * @param buffer The pointer to the address of setup packet data buffer.
 *
 * @return A USB error code or kStatus_USB_Success.
 */
usb_status_t USB_DeviceProcessVendorRequest(usb_device_handle handle,
                                            usb_setup_struct_t *setup,
                                            uint32_t *length,
                                            uint8_t **buffer)
{
    return kStatus_USB_InvalidRequest;
}

/*!
 * @brief Configure remote wakeup feature.
 *
 * This function configures the remote wakeup feature.
 *
 * @param handle The USB device handle.
 * @param enable 1: enable, 0: disable.
 *
 * @return A USB error code or kStatus_USB_Success.
 */
usb_status_t USB_DeviceConfigureRemoteWakeup(usb_device_handle handle, uint8_t enable)
{
    return kStatus_USB_InvalidRequest;
}

/*!
 * @brief USB configure endpoint function.
 *
 * This function configure endpoint status.
 *
 * @param handle The USB device handle.
 * @param ep Endpoint address.
 * @param status A flag to indicate whether to stall the endpoint. 1: stall, 0: unstall.
 *
 * @return A USB error code or kStatus_USB_Success.
 */
usb_status_t USB_DeviceConfigureEndpointStatus(usb_device_handle handle, uint8_t ep, uint8_t status)
{
    usb_status_t error = kStatus_USB_InvalidRequest;
    error              = USB_DeviceAudioUnifiedConfigureEndpointStatus(handle, ep, status);
    error              = USB_DeviceHidConfigureEndpointStatus(handle, ep, status);

    return error;
}

/*!
 * @brief Get the setup packet data buffer.
 *
 * This function gets the data buffer for setup packet.
 *
 * @param handle The USB device handle.
 * @param setup The pointer to the setup packet.
 * @param length The pointer to the length of the data buffer.
 * @param buffer The pointer to the address of setup packet data buffer.
 *
 * @return A USB error code or kStatus_USB_Success.
 */
usb_status_t USB_DeviceGetClassReceiveBuffer(usb_device_handle handle,
                                             usb_setup_struct_t *setup,
                                             uint32_t *length,
                                             uint8_t **buffer)
{
    if ((NULL == buffer) || ((*length) > sizeof(s_SetupOutBuffer)))
    {
        return kStatus_USB_InvalidRequest;
    }
    *buffer = s_SetupOutBuffer;
    return kStatus_USB_Success;
}

/*!
 * @brief Audio class specific callback function.
 *
 * This function handles the Audio class specific requests.
 *
 * @param handle The USB device handle.
 * @param setup The pointer to the setup packet.
 * @param length The pointer to the length of the data buffer.
 * @param buffer The pointer to the address of setup packet data buffer.
 *
 * @return A USB error code or kStatus_USB_Success.
 */
usb_status_t USB_DeviceProcessClassRequest(usb_device_handle handle,
                                           usb_setup_struct_t *setup,
                                           uint32_t *length,
                                           uint8_t **buffer)
{
    usb_status_t error = kStatus_USB_InvalidRequest;
#if (USB_DEVICE_CONFIG_AUDIO_CLASS_2_0)
    /* Handle the audio class specific request. */
    uint8_t entityId      = (uint8_t)(setup->wIndex >> 0x08);
    uint32_t audioCommand = 0;
    if ((((setup->bmRequestType & USB_REQUEST_TYPE_RECIPIENT_MASK) != USB_REQUEST_TYPE_RECIPIENT_INTERFACE)) ||
        ((((setup->bmRequestType & USB_REQUEST_TYPE_RECIPIENT_MASK) == USB_REQUEST_TYPE_RECIPIENT_INTERFACE)) &&
         (USB_AUDIO_CONTROL_INTERFACE_INDEX == (setup->wIndex & 0xFFU))))
    {
        switch (entityId)
        {
            case USB_AUDIO_RECORDER_CONTROL_OUTPUT_TERMINAL_ID:
            case USB_AUDIO_SPEAKER_CONTROL_OUTPUT_TERMINAL_ID:
                break;
            case USB_AUDIO_RECORDER_CONTROL_INPUT_TERMINAL_ID:
            case USB_AUDIO_SPEAKER_CONTROL_INPUT_TERMINAL_ID:
                break;
            case USB_AUDIO_CONTROL_CLOCK_SOURCE_ID:
                if (((setup->bmRequestType & USB_REQUEST_TYPE_DIR_MASK) == USB_REQUEST_TYPE_DIR_IN))
                {
                    switch (setup->wValue >> 8)
                    {
                        case USB_DEVICE_AUDIO_CS_SAM_FREQ_CONTROL:
                            if (setup->bRequest == USB_DEVICE_AUDIO_REQUEST_CUR)
                            {
                                audioCommand = USB_DEVICE_AUDIO_GET_CUR_SAM_FREQ_CONTROL;
                            }
                            else if (setup->bRequest == USB_DEVICE_AUDIO_REQUEST_RANGE)
                            {
                                audioCommand = USB_DEVICE_AUDIO_GET_RANGE_SAM_FREQ_CONTROL;
                            }
                            else
                            {
                            }
                            break;
                        case USB_DEVICE_AUDIO_CS_CLOCK_VALID_CONTROL:
                            audioCommand = USB_DEVICE_AUDIO_GET_CUR_CLOCK_VALID_CONTROL;
                            break;
                        default:
                            break;
                    }
                }
                else if (((setup->bmRequestType & USB_REQUEST_TYPE_DIR_MASK) == USB_REQUEST_TYPE_DIR_OUT))
                {
                    switch (setup->wValue >> 8)
                    {
                        case USB_DEVICE_AUDIO_CS_SAM_FREQ_CONTROL:
                            audioCommand = USB_DEVICE_AUDIO_SET_CUR_SAM_FREQ_CONTROL;
                            break;
                        case USB_DEVICE_AUDIO_CS_CLOCK_VALID_CONTROL:
                            audioCommand = USB_DEVICE_AUDIO_SET_CUR_CLOCK_VALID_CONTROL;
                            break;
                        default:
                            break;
                    }
                }
                else
                {
                }
                break;
            case USB_AUDIO_RECORDER_CONTROL_FEATURE_UNIT_ID:
            case USB_AUDIO_SPEAKER_CONTROL_FEATURE_UNIT_ID:
                if (((setup->bmRequestType & USB_REQUEST_TYPE_DIR_MASK) == USB_REQUEST_TYPE_DIR_IN))
                {
                    switch (setup->wValue >> 8)
                    {
                        case USB_DEVICE_AUDIO_FU_MUTE_CONTROL:
                            audioCommand = USB_DEVICE_AUDIO_GET_CUR_MUTE_CONTROL_AUDIO20;
                            break;
                        case USB_DEVICE_AUDIO_FU_VOLUME_CONTROL:
                            if (setup->bRequest == USB_DEVICE_AUDIO_REQUEST_CUR)
                            {
                                audioCommand = USB_DEVICE_AUDIO_GET_CUR_VOLUME_CONTROL_AUDIO20;
                            }
                            else if (setup->bRequest == USB_DEVICE_AUDIO_REQUEST_RANGE)
                            {
                                audioCommand = USB_DEVICE_AUDIO_GET_RANGE_VOLUME_CONTROL_AUDIO20;
                            }
                            else
                            {
                            }
                            break;
                        default:
                            break;
                    }
                }
                else if (((setup->bmRequestType & USB_REQUEST_TYPE_DIR_MASK) == USB_REQUEST_TYPE_DIR_OUT))
                {
                    switch (setup->wValue >> 8)
                    {
                        case USB_DEVICE_AUDIO_FU_MUTE_CONTROL:
                            audioCommand = USB_DEVICE_AUDIO_SET_CUR_MUTE_CONTROL_AUDIO20;
                            break;
                        case USB_DEVICE_AUDIO_FU_VOLUME_CONTROL:
                            if (setup->bRequest == USB_DEVICE_AUDIO_REQUEST_CUR)
                            {
                                audioCommand = USB_DEVICE_AUDIO_SET_CUR_VOLUME_CONTROL_AUDIO20;
                            }
                            break;
                        default:
                            break;
                    }
                }
                break;
            default:
            break;
        }
        error = USB_DeviceAudioProcessTerminalRequest(audioCommand, length, buffer, entityId);
    }
    else
    {
        if (USB_HID_KEYBOARD_INTERFACE_INDEX == (setup->wIndex & 0xFFU))
        {
            return USB_DeviceHidKeyboardClassRequest(handle, setup, buffer, length);
        }
        else
        {
            return error;
        }
    }

#else

    if ((setup->bmRequestType & USB_REQUEST_TYPE_RECIPIENT_MASK) != USB_REQUEST_TYPE_RECIPIENT_INTERFACE)
    {
        return USB_DeviceAudioUnifiedClassRequestEndpRecipient(handle, setup, length, buffer);
    }
    else
    {
        if (USB_AUDIO_CONTROL_INTERFACE_INDEX == (setup->wIndex & 0xFFU))
        {
            return USB_DeviceAudioUnifiedClassRequestIntfRecipient(handle, setup, length, buffer);
        }
        else if (USB_HID_KEYBOARD_INTERFACE_INDEX == (setup->wIndex & 0xFFU))
        {
            return USB_DeviceHidKeyboardClassRequest(handle, setup, buffer, length);
        }
        else
        {
        }
    }
#endif
    return error;
}

/*!
 * @brief Application initialization function.
 *
 * This function initializes the application.
 *
 * @return None.
 */
void APPInit(void)
{
    USB_DeviceClockInit();
#if (defined(FSL_FEATURE_SOC_SYSMPU_COUNT) && (FSL_FEATURE_SOC_SYSMPU_COUNT > 0U))
    SYSMPU_Enable(SYSMPU, 0);
#endif /* FSL_FEATURE_SOC_SYSMPU_COUNT */

    g_composite.speed        = USB_SPEED_FULL;
    g_composite.attach       = 0U;
    g_composite.deviceHandle = NULL;

    if (kStatus_USB_Success != USB_DeviceInit(CONTROLLER_ID, USB_DeviceCallback, &g_composite.deviceHandle))
    {
        usb_echo("USB device composite demo init failed\r\n");
        return;
    }
    else
    {
        usb_echo("USB device composite demo\r\n");
        usb_echo("Please Press  switch(%s) to mute/unmute device audio speaker.\r\n", SW_GetName());

        USB_DeviceAudioUnifiedInit(&g_composite);
        USB_DeviceHidKeyboardInit(&g_composite);
    }

    Init_Board_Audio();

    USB_DeviceIsrEnable();

    /*Add one delay here to make the DP pull down long enough to allow host to detect the previous disconnection.*/
    SDK_DelayAtLeastUs(5000, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    USB_DeviceRun(g_composite.deviceHandle);
}

#if defined(__CC_ARM) || (defined(__ARMCC_VERSION)) || defined(__GNUC__)
int main(void)
#else
void main(void)
#endif
{
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    CLOCK_InitAudioPll(&audioPllConfig);
    BOARD_InitDebugConsole();

    /*Clock setting for LPI2C*/
    CLOCK_SetMux(kCLOCK_Lpi2cMux, DEMO_LPI2C_CLOCK_SOURCE_SELECT);
    CLOCK_SetDiv(kCLOCK_Lpi2cDiv, DEMO_LPI2C_CLOCK_SOURCE_DIVIDER);

    /*Clock setting for SAI1*/
    CLOCK_SetMux(kCLOCK_Sai1Mux, DEMO_SAI1_CLOCK_SOURCE_SELECT);
    CLOCK_SetDiv(kCLOCK_Sai1PreDiv, DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER);
    CLOCK_SetDiv(kCLOCK_Sai1Div, DEMO_SAI1_CLOCK_SOURCE_DIVIDER);

    /*Enable MCLK clock*/
    BOARD_EnableSaiMclkOutput(true);

    APPInit();

    while (1)
    {
        USB_DeviceHidKeyboardAction();

        USB_AudioCodecTask();

        USB_AudioSpeakerResetTask();

#if USB_DEVICE_CONFIG_USE_TASK
        USB_DeviceTaskFn(g_composite.deviceHandle);
#endif
    }
}
