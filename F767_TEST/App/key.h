#ifndef _KEY_H
#define _KEY_H
#include "main.h"



#define READ_WKUP_PIN       HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)  //WKUP PC13

#define KEY_WKUP   4

#define KEY_PRESS_0     1   //短按、点击
#define KEY_PRESS_1     2   //长按、按压
#define KEY_PRESS_2     4   //长按、按压

#define KEY_CLICK       8
typedef struct
{
    uint8_t cnt_0;
    uint8_t cnt_1;
    uint8_t cnt_2;
    uint8_t val;
    
}KEY_NUM_TYPE;

typedef struct
{
    KEY_NUM_TYPE wake_up;
    
}KEY_TYPE;


extern KEY_TYPE key;
void user_key_init(void);

uint8_t user_key_scan(uint8_t mode);
uint8_t is_key(KEY_NUM_TYPE *p_key, uint8_t stat);

#endif
