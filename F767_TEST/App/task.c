#include "key.h"
#include "led.h"
#include "task.h"

#include "main.h"
#include "eth.h"
#include "tim.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"


void SystemClock_Config(void);

void sys_init(void)
{
    HAL_Init();
    SystemClock_Config();
//    
//    MX_GPIO_Init();
//    MX_TIM4_Init();
//    MX_USART3_UART_Init();

//    led_init();
//    user_key_init();

//    HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);


//    led_init();
    user_key_init();
//    

//    HAL_TIM_Base_Start_IT(&htim4);
//    HAL_TIM_Base_Start(&htim4);

//    memset(&key, 0, sizeof(key));

}


void sys_into_stop(void)
{
    HAL_Delay(100);
    GPIO_InitTypeDef GPIO_InitStruct;

    SysTick->CTRL = 0x00;//关闭定时器
    SysTick->VAL = 0x00;//清空val,清空定时器


    __HAL_RCC_GPIOC_CLK_ENABLE();           //开启GPIOC时钟
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

    //进入stop
    __HAL_RCC_PWR_CLK_ENABLE();
    //HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_UNDERDRIVE_ON, PWR_STOPENTRY_WFI | PWR_STOPENTRY_WFE);
    HAL_PWR_EnterSTANDBYMode();

}



const uint64_t bit_buf[] =
{
    0x0000000000000001,
    0x0000000000000002,
    0x0000000000000004,
    0x0000000000000008,
    0x0000000000000010,
    0x0000000000000020,
    0x0000000000000040,
    0x0000000000000080,
    0x0000000000000100,
    0x0000000000000200,
    0x0000000000000400,
    0x0000000000000800,
    0x0000000000001000,
    0x0000000000002000,
    0x0000000000004000,
    0x0000000000008000,
    0x0000000000010000,
    0x0000000000020000,
    0x0000000000040000,
    0x0000000000080000,
    0x0000000000100000,
    0x0000000000200000,
    0x0000000000400000,
    0x0000000000800000,
    0x0000000001000000,
    0x0000000002000000,
    0x0000000004000000,
    0x0000000008000000,
    0x0000000010000000,
    0x0000000020000000,
    0x0000000040000000,
    0x0000000080000000,
    0x0000000100000000,
    0x0000000200000000,
    0x0000000400000000,
    0x0000000800000000,
    0x0000001000000000,
    0x0000002000000000,
    0x0000004000000000,
    0x0000008000000000,
    0x0000010000000000,
    0x0000020000000000,
    0x0000040000000000,
    0x0000080000000000,
    0x0000100000000000,
    0x0000200000000000,
    0x0000400000000000,
    0x0000800000000000,
    0x0001000000000000,
    0x0002000000000000,
    0x0004000000000000,
    0x0008000000000000,
    0x0010000000000000,
    0x0020000000000000,
    0x0040000000000000,
    0x0080000000000000,
    0x0100000000000000,
    0x0200000000000000,
    0x0400000000000000,
    0x0800000000000000,
    0x1000000000000000,
    0x2000000000000000,
    0x4000000000000000,
    0x8000000000000000,

};


uint8_t my_set_bit(void * data, uint8_t bit_index, uint8_t num_bool)
{
    if(data == NULL)
    {
        return 0;
    }
    if((num_bool > 1) || (bit_index > 64))
    {
        return 0;
    }


    if(num_bool == 0)
    {
        *(uint64_t*)data &= ~ bit_buf[bit_index];
    }
    else if(num_bool == 1)
    {
        *(uint64_t*)data |= bit_buf[bit_index];
    }

    return 1;
}


void test_left_move(void)
{
    uint16_t result = 0;

    uint16_t * p = &result;

    my_set_bit(p, 4, 1);

    printf("result = %04X", result);
    while(1);
}

uint16_t test_add_num = 0;
void test_add(void)
{
    uint16_t num1 = 65535;
    
    uint16_t num2 = 10;
    
    test_add_num = num1 - num2;
   
    
}


void test_buff(uint8_t i)
{
    uint8_t buff[i];
    
    
}


void test_app(void)
{
//    test_left_move();
    test_add();
    test_buff(10);
    
    
}



