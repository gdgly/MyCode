
#include "led.h"
#include "gpio.h"


//LED IO初始化
void led_init(void)
{

    GPIO_InitTypeDef GPIO_InitStruct;
    __HAL_RCC_GPIOB_CLK_ENABLE();			//开启GPIOB时钟

    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_14 | GPIO_PIN_7; //PB0,1
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; //推挽输出
    GPIO_InitStruct.Pull = GPIO_PULLUP;        //上拉
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;   //高速
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);	//PB1置0
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);	//PB1置1
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);	//PB1置1
}



uint8_t led_flag = 0;
#if 0
void led_display(void)
{
    led_flag++;
    if(led_flag == 1)
    {
        LED0(1);
    }
    else if(led_flag == 2)
    {
        LED1(1);
    }
    else if(led_flag == 3)
    {
        LED2(1);
    }
    else if(led_flag == 4)
    {
        LED0(0);
    }
    else if(led_flag == 5)
    {
        LED1(0);
    }
    else if(led_flag == 6)
    {
        LED2(0);
        led_flag = 0;
    }

}


#else

void led_display(void)
{
    led_flag++;
    if(led_flag == 1)
    {
        LED0(1);
    }
    else if(led_flag == 2)
    {
        LED1(1);
    }
    else if(led_flag == 3)
    {
        LED0(0);
    }
    else if(led_flag == 4)
    {
        LED1(0);
        led_flag = 0;
    }


}

#endif
