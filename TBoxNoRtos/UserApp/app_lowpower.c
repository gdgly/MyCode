

#include "app_lowpower.h"
#include "bsp_can.h"


void SystemClock_Config(void);


void ec25_enter_low_power(void)
{
    HAL_GPIO_WritePin(EC25_DTR_GPIO_Port, EC25_DTR_Pin, GPIO_PIN_SET);
}

void ec25_exit_low_power(void)
{
    HAL_GPIO_WritePin(EC25_DTR_GPIO_Port, EC25_DTR_Pin, GPIO_PIN_RESET);
}

void ec25_receive_enable(void)
{
    HAL_GPIO_WritePin(EC25_AP_READY_GPIO_Port, EC25_AP_READY_Pin, GPIO_PIN_SET);
}

void ec25_receive_disable(void)
{
    HAL_GPIO_WritePin(EC25_AP_READY_GPIO_Port, EC25_AP_READY_Pin, GPIO_PIN_RESET);
}



void sys_exit_stop(void)
{
    SET_BIT(SysTick->CTRL, (uint32_t)SysTick_CTRL_TICKINT_Msk);

    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();
    MX_USART2_UART_Init();
    MX_ADC1_Init();
    MX_SDIO_SD_Init();
    MX_SPI1_Init();
    MX_USART1_UART_Init();
    MX_USART3_UART_Init();
    MX_USART6_UART_Init();
    MX_RTC_Init();

    //gpio
    HAL_GPIO_WritePin(LEVEL_EN_GPIO_Port, LEVEL_EN_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(CAN1_STB_GPIO_Port, CAN1_STB_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(CAN2_STB_GPIO_Port, CAN2_STB_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(CAN3_STB_GPIO_Port, CAN3_STB_Pin, GPIO_PIN_RESET);


    HAL_GPIO_WritePin(ADC_EN_GPIO_Port, ADC_EN_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(GPS_EN_GPIO_Port, GPS_EN_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(EC25_EN_GPIO_Port, EC25_EN_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(EC25_POWERKEY_GPIO_Port, EC25_POWERKEY_Pin, GPIO_PIN_SET);


    //can
    hw_can_init();


    ec25_exit_low_power();
    ec25_receive_enable();

    __enable_irq();
}

uint16_t enter_times = 0;

//进入stop
void sys_into_stop(void)
{
    __disable_irq();


    ec25_receive_disable();
    ec25_enter_low_power();


    HAL_GPIO_WritePin(LEVEL_EN_GPIO_Port, LEVEL_EN_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(CAN1_STB_GPIO_Port, CAN1_STB_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(CAN2_STB_GPIO_Port, CAN2_STB_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(CAN3_STB_GPIO_Port, CAN3_STB_Pin, GPIO_PIN_SET);


    HAL_GPIO_WritePin(ADC_EN_GPIO_Port, ADC_EN_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(GPS_EN_GPIO_Port, GPS_EN_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(EC25_EN_GPIO_Port, EC25_EN_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(EC25_POWERKEY_GPIO_Port, EC25_POWERKEY_Pin, GPIO_PIN_SET);
    
    
    HAL_UART_DeInit(&huart1);
    HAL_UART_DeInit(&huart2);
    HAL_UART_DeInit(&huart3);
    HAL_UART_DeInit(&huart6);


    HAL_NVIC_ClearPendingIRQ(EXTI1_IRQn);
    HAL_NVIC_ClearPendingIRQ(USART1_IRQn);
    HAL_NVIC_ClearPendingIRQ(USART2_IRQn);
    HAL_NVIC_ClearPendingIRQ(USART3_IRQn);
    HAL_NVIC_ClearPendingIRQ(USART6_IRQn);

    HAL_NVIC_ClearPendingIRQ(CAN1_RX0_IRQn);
    HAL_NVIC_ClearPendingIRQ(CAN1_RX1_IRQn);
    HAL_NVIC_ClearPendingIRQ(CAN2_RX0_IRQn);
    HAL_NVIC_ClearPendingIRQ(CAN2_RX1_IRQn);
    HAL_NVIC_ClearPendingIRQ(CAN3_RX0_IRQn);
    HAL_NVIC_ClearPendingIRQ(CAN3_RX1_IRQn);

    HAL_NVIC_ClearPendingIRQ(SDIO_IRQn);

    HAL_NVIC_ClearPendingIRQ(SPI1_IRQn);




    //GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3| adc不能DeInit
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_All & ~(GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14));
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_All & ~(GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14));
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_All & ~(GPIO_PIN_4));
    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_All & ~(GPIO_PIN_0 | GPIO_PIN_8 | GPIO_PIN_10));
    HAL_GPIO_DeInit(GPIOE, GPIO_PIN_All & ~(GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_9 | GPIO_PIN_11));

    HAL_ADC_DeInit(&hadc1);

    HAL_CAN_DeInit(&hcan1);
    HAL_CAN_DeInit(&hcan2);
    HAL_CAN_DeInit(&hcan3);

    EXTI->PR = 0xFFFFFFFF;
    CLEAR_BIT(SysTick->CTRL, (uint32_t)SysTick_CTRL_TICKINT_Msk);

    if ((SCB->ICSR & SCB_ICSR_PENDSTSET_Msk) != 0U)
    {
        SCB->ICSR = SCB_ICSR_PENDSTCLR_Msk;
    }


    //进入stop
    __HAL_RCC_PWR_CLK_ENABLE();
    HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_STOPENTRY_WFI);

}





