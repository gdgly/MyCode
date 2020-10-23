// Initialization
// Generated by CANopen Architect Professional 8.10.5839 on 5/5/2020 10:18:56 AM
// Generated from project
// e:\ESA_new\MicroCANopenPlus\trunk\MCO_CiA401_IMXRT_MCUX_SDK\Example-Config\EDS\CANopen_NXP_SDK_Device.cax Generated
// from EDS 'CANopen_NXP_SDK_CiA401' 04-20-2020 08:21PM by Pf Use with MicroCANopen Plus CANopen stack For more
// information visit www.esacademy.com and www.microcanopen.com

// Check for warnings below before using this file

#ifndef _STACKINITH_
#define _STACKINITH_

#define FILE_VERSION  1
#define FILE_REVISION 2
#define DESCRIPTION   "CANopen Library for NXP SDK - CiA 401 generic IO Example"

// CAN bitrate definitions as defined in CiA305
#ifndef CIA305_CAN_BITRATE_1000
#define CIA305_CAN_BITRATE_1000 0
#endif
#ifndef CIA305_CAN_BITRATE_800
#define CIA305_CAN_BITRATE_800 1
#endif
#ifndef CIA305_CAN_BITRATE_500
#define CIA305_CAN_BITRATE_500 2
#endif
#ifndef CIA305_CAN_BITRATE_250
#define CIA305_CAN_BITRATE_250 3
#endif
#ifndef CIA305_CAN_BITRATE_125
#define CIA305_CAN_BITRATE_125 4
#endif
#ifndef CIA305_CAN_BITRATE_50
#define CIA305_CAN_BITRATE_50 6
#endif
#ifndef CIA305_CAN_BITRATE_20
#define CIA305_CAN_BITRATE_20 7
#endif
#ifndef CIA305_CAN_BITRATE_10
#define CIA305_CAN_BITRATE_10 8
#endif
#ifndef CIA305_CAN_BITRATE_AUTO
#define CIA305_CAN_BITRATE_AUTO 9
#endif

// CAN bitrates supported by this device
#define CAN_BITRATE_SUPPORTED                                                                            \
    ((1U << CIA305_CAN_BITRATE_1000) | (1U << CIA305_CAN_BITRATE_500) | (1U << CIA305_CAN_BITRATE_250) | \
     (1U << CIA305_CAN_BITRATE_125))

// Default CAN bitrate (kbps)
#define CAN_BITRATE_DCF 500

#ifdef MCO_USE_HANDLE
#define INITPDOS_CALLS                                                                       \
    MCO_InitRPDO(handle, 1, NODEID + 0x200, 4, P620001_DigOutput8_1);                        \
    MCO_InitRPDO(handle, 2, NODEID + 0x300, 4, P641101_AnalogOutput16_1);                    \
    MCO_InitTPDOFull(handle, 1, NODEID + 0x40000180, 250, 100, 255, 4, P600001_DigInput8_1); \
    MCO_InitTPDOFull(handle, 2, NODEID + 0x40000280, 500, 200, 255, 4, P640101_AnalogInput16_1);

#else
#define INITPDOS_CALLS                                                               \
    MCO_InitRPDO(1, NODEID + 0x200, 4, P620001_DigOutput8_1);                        \
    MCO_InitRPDO(2, NODEID + 0x300, 4, P641101_AnalogOutput16_1);                    \
    MCO_InitTPDOFull(1, NODEID + 0x40000180, 250, 100, 255, 4, P600001_DigInput8_1); \
    MCO_InitTPDOFull(2, NODEID + 0x40000280, 500, 200, 255, 4, P640101_AnalogInput16_1);

#endif

#ifdef MCO_USE_HANDLE
#define INITHBCONSUMER_CALLS                    \
    MCOP_InitHBConsumer(handle, 1, 0x01, 1000); \
    MCOP_InitHBConsumer(handle, 2, 0x02, 0);    \
    MCOP_InitHBConsumer(handle, 3, 0x03, 0);

#else
#define INITHBCONSUMER_CALLS            \
    MCOP_InitHBConsumer(1, 0x01, 1000); \
    MCOP_InitHBConsumer(2, 0x02, 0);    \
    MCOP_InitHBConsumer(3, 0x03, 0);

#endif

#ifdef MCO_USE_HANDLE
#define INITEMCYCONSUMER_CALLS

#else
#define INITEMCYCONSUMER_CALLS

#endif

#endif // _STACKINITH_
