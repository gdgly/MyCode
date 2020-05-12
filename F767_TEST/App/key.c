#include "key.h"
#include "led.h"
#include "task.h"


KEY_TYPE key = {0};


//支持F767
//按键处理函数
void user_key_init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOC_CLK_ENABLE();           //开启GPIOC时钟

    GPIO_Initure.Pin = GPIO_PIN_13;          //PC13
    GPIO_Initure.Mode = GPIO_MODE_INPUT;    //输入
    GPIO_Initure.Pull = GPIO_NOPULL;      //下拉
    GPIO_Initure.Speed = GPIO_SPEED_LOW;   //高速
    HAL_GPIO_Init(GPIOC, &GPIO_Initure);

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_13)
    {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_13);
        EXTI->IMR   &= ~(1<<13);
        EXTI->FTSR  &= ~(1<<13);
        EXTI->PR    &= ~(1<<13);
        sys_init();

    }
}

//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;

#if 0
uint8_t user_key_scan(uint8_t mode)
{
    static uint8_t key_up = 1;  //按键松开标志
    if(mode == 1)
    {
        key_up = 1;    //支持连按
    }

    if(key_up && (READ_WKUP_PIN == 1))
    {
        key_up = 0;
        return KEY_WKUP;
    }
    else if(READ_WKUP_PIN == 0)
    {
        key_up = 1;
    }
    return 0;   //无按键按下
}

#else

uint8_t user_key_scan(uint8_t mode)
{
    mode = mode;

    if(READ_WKUP_PIN == 1)
    {
        key.wake_up.cnt_0++;
        
        if(key.wake_up.cnt_0 >= 5)
        {
            key.wake_up.val |= KEY_PRESS_0;
        }
    }
    else
    {
        if(key.wake_up.cnt_0 >= 5)
        {
            key.wake_up.val |= KEY_CLICK;
        }
        key.wake_up.cnt_0 = 0;
    }
    
    return 0;
}


uint8_t is_key(KEY_NUM_TYPE *p_key, uint8_t stat)
{
    if((p_key->val & stat) == stat)
    {
        p_key->val = (p_key->val & (~stat));
        return 1;

    }
    else
    {
        return 0;
    }
}


#endif

