
#ifndef BSP_OLED_H_
#define BSP_OLED_H_



#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "i2c.h"

#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"
#include "string.h"

#define OLED0561_ADD    0x78


void OLED_Init(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLS(void);

#endif


