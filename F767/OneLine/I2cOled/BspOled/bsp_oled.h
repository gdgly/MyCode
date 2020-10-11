
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

extern unsigned char qt_image[1024];
extern unsigned char nvidia_image[1024];

void OLED_Init(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLS(void);

void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t Char_Size);
void OLED_DrawBMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char BMP[]);


#endif


