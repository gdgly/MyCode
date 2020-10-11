

#include "bsp_oled.h"

#include "stm32f1xx_hal.h"

void WriteCmd(unsigned char I2C_Command)//写命令
{
    HAL_I2C_Mem_Write(&hi2c2, OLED0561_ADD, 0x00, I2C_MEMADD_SIZE_8BIT, &I2C_Command, 1, 100);
}

void WriteDat(unsigned char I2C_Data)//写数据
{
    HAL_I2C_Mem_Write(&hi2c2, OLED0561_ADD, 0x40, I2C_MEMADD_SIZE_8BIT, &I2C_Data, 1, 100);
}

void OLED_Init(void)
{
    HAL_Delay(100); //这里的延时很重要

    WriteCmd(0xAE); //display off
    WriteCmd(0x20);        //Set Memory Addressing Mode
    WriteCmd(0x10);        //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
    WriteCmd(0xb0);        //Set Page Start Address for Page Addressing Mode,0-7
    WriteCmd(0xc8);        //Set COM Output Scan Direction
    WriteCmd(0x00); //---set low column address
    WriteCmd(0x10); //---set high column address
    WriteCmd(0x40); //--set start line address
    WriteCmd(0x81); //--set contrast control register
    WriteCmd(0xff); //亮度调节 0x00~0xff
    WriteCmd(0xa1); //--set segment re-map 0 to 127
    WriteCmd(0xa6); //--set normal display
    WriteCmd(0xa8); //--set multiplex ratio(1 to 64)
    WriteCmd(0x3F); //
    WriteCmd(0xa4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
    WriteCmd(0xd3); //-set display offset
    WriteCmd(0x00); //-not offset
    WriteCmd(0xd5); //--set display clock divide ratio/oscillator frequency
    WriteCmd(0xf0); //--set divide ratio
    WriteCmd(0xd9); //--set pre-charge period
    WriteCmd(0x22); //
    WriteCmd(0xda); //--set com pins hardware configuration
    WriteCmd(0x12);
    WriteCmd(0xdb); //--set vcomh
    WriteCmd(0x20); //0x20,0.77xVcc
    WriteCmd(0x8d); //--set DC-DC enable
    WriteCmd(0x14); //
    WriteCmd(0xaf); //--turn on oled panel
}

void OLED_SetPos(unsigned char x, unsigned char y) //设置起始点坐标
{
    WriteCmd(0xb0 + y);
    WriteCmd(((x & 0xf0) >> 4) | 0x10);
    WriteCmd((x & 0x0f) | 0x01);
}

void OLED_Fill(unsigned char fill_Data)//全屏填充
{
    unsigned char m, n;
    for(m = 0; m < 8; m++)
    {
        WriteCmd(0xb0 + m);              //page0-page1
        WriteCmd(0x00);                //low column start address
        WriteCmd(0x10);                //high column start address
        for(n = 0; n < 128; n++)
        {
            WriteDat(fill_Data);
        }
    }
}


void OLED_CLS(void)//清屏
{
    OLED_Fill(0x00);
}

void OLED_ON(void)
{
    WriteCmd(0X8D);  //设置电荷泵
    WriteCmd(0X14);  //开启电荷泵
    WriteCmd(0XAF);  //OLED唤醒
}

void OLED_OFF(void)
{
    WriteCmd(0X8D);  //设置电荷泵
    WriteCmd(0X10);  //关闭电荷泵
    WriteCmd(0XAE);  //OLED休眠
}


//// Parameters     : x,y -- 起始点坐标(x:0~127, y:0~7); ch[] -- 要显示的字符串; TextSize -- 字符大小(1:6*8 ; 2:8*16)
//// Description    : 显示codetab.h中的ASCII字符,有6*8和8*16可选择
//void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize)
//{
//    unsigned char c = 0, i = 0, j = 0;
//    switch(TextSize)
//    {
//    case 1:
//    {
//        while(ch[j] != '\0')
//        {
//            c = ch[j] - 32;
//            if(x > 126)
//            {
//                x = 0;
//                y++;
//            }
//            OLED_SetPos(x, y);
//            for(i = 0; i < 6; i++)
//                WriteDat(F6x8[c][i]);
//            x += 6;
//            j++;
//        }
//    }
//    break;
//    case 2:
//    {
//        while(ch[j] != '\0')
//        {
//            c = ch[j] - 32;
//            if(x > 120)
//            {
//                x = 0;
//                y++;
//            }
//            OLED_SetPos(x, y);
//            for(i = 0; i < 8; i++)
//                WriteDat(F8X16[c * 16 + i]);
//            OLED_SetPos(x, y + 1);
//            for(i = 0; i < 8; i++)
//                WriteDat(F8X16[c * 16 + i + 8]);
//            x += 8;
//            j++;
//        }
//    }
//    break;
//    }
//}


//// Parameters     : x,y -- 起始点坐标(x:0~127, y:0~7); N:汉字在.h中的索引
//// Description    : 显示ASCII_8x16.h中的汉字,16*16点阵
//void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N)
//{
//    unsigned char wm = 0;
//    unsigned int  adder = 32 * N;
//    OLED_SetPos(x , y);
//    for(wm = 0; wm < 16; wm++)
//    {
//        WriteDat(F16x16[adder]);
//        adder += 1;
//    }
//    OLED_SetPos(x, y + 1);
//    for(wm = 0; wm < 16; wm++)
//    {
//        WriteDat(F16x16[adder]);
//        adder += 1;
//    }
//}



// Parameters     : x0,y0 -- 起始点坐标(x0:0~127, y0:0~7); x1,y1 -- 起点对角线(结束点)的坐标(x1:1~128,y1:1~8)
// Description    : 显示BMP位图
void OLED_DrawBMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char BMP[])
{
    unsigned int j = 0;
    unsigned char x, y;

    if(y1 % 8 == 0)
        y = y1 / 8;
    else
        y = y1 / 8 + 1;
    for(y = y0; y < y1; y++)
    {
        OLED_SetPos(x0, y);
        for(x = x0; x < x1; x++)
        {
            WriteDat(BMP[j++]);
        }
    }
}






//void OLED_ShowChar(u8 x, u8 y, u8 chr, u8 Char_Size)
//{
//    unsigned char c = 0, i = 0;
//    c = chr - ' '; //得到偏移后的值
//    if(x > 128 - 1) {
//        x = 0;
//        y = y + 2;
//    }
//    if(Char_Size == 16)
//    {
//        OLED_SetPos(x, y);
//        for(i = 0; i < 8; i++)
//            WriteDat(F8X16[c * 16 + i]);
//        OLED_SetPos(x, y + 1);
//        for(i = 0; i < 8; i++)
//            WriteDat(F8X16[c * 16 + i + 8]);
//    }
//    else {
//        OLED_SetPos(x, y);
//        for(i = 0; i < 6; i++)
//            WriteDat(F6x8[c][i]);

//    }
//}


unsigned char qt_image[1024]={
0,0,0,0,0,0,0,0,0,0,0,0,192,224,240,248,248,252,252,252,254,254,254,254,254,254,254,254,254,254,254,254,255,254,255,255,255,254,254,254,254,254,254,254,254,254,254,254,254,254,252,252,252,252,252,252,252,252,252,252,252,252,248,248,248,248,248,248,248,248,248,248,248,248,240,240,240,240,240,240,240,240,240,240,240,240,224,224,224,224,224,224,224,224,224,224,224,224,192,192,192,192,192,192,192,192,192,192,192,192,192,128,128,128,128,128,128,128,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,127,63,63,63,31,31,31,31,15,15,15,15,15,15,15,15,15,15,15,15,31,31,31,31,31,63,63,63,127,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,63,63,63,63,127,127,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,63,15,7,3,1,0,0,0,0,0,0,0,0,0,0,224,240,248,252,252,254,254,254,254,254,254,252,252,248,240,224,0,0,0,0,0,0,0,1,1,3,7,31,255,255,255,15,15,15,31,31,7,1,0,0,0,0,0,0,0,0,31,31,31,31,31,31,31,31,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,248,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,0,0,0,0,0,0,0,0,0,0,0,0,15,255,254,254,254,254,0,0,0,0,0,0,0,0,0,0,0,254,254,254,254,254,254,254,254,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,252,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,7,0,0,0,0,0,0,0,0,0,0,0,224,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,248,248,240,224,192,192,192,128,128,128,0,0,0,0,3,3,7,7,15,15,15,15,7,7,7,3,1,0,128,128,128,192,192,224,224,240,248,252,254,255,255,255,255,255,255,255,255,248,240,224,224,192,192,192,192,192,192,192,193,195,195,195,195,227,227,225,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,252,248,240,224,192,192,128,128,128,128,128,128,128,131,131,135,135,135,135,135,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,127,63,31,15,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,31,31,63,63,63,127,127,255,255,255,255,255,255,255,255,255,255,255,127,127,127,127,127,127,127,127,127,127,127,127,63,63,63,63,63,63,63,63,63,63,63,63,31,31,31,31,31,31,31,31,31,31,31,31,15,15,15,15,15,15,15,15,15,15,15,15,7,7,7,7,7,7,7,7,7,7,7,7,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};


unsigned char nvidia_image[1024]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,192,192,192,192,224,96,96,96,96,48,48,48,48,48,48,24,24,24,24,24,24,24,24,24,227,195,195,195,195,195,195,195,195,195,195,195,195,195,195,131,135,135,135,7,7,15,15,15,15,15,31,31,31,31,63,63,63,127,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,
0,0,0,0,0,0,0,32,96,240,240,248,248,252,252,252,254,222,30,15,15,7,7,3,3,1,1,1,65,192,224,224,240,240,240,248,56,56,24,28,28,12,12,12,12,6,6,6,6,6,240,240,240,224,224,224,224,192,192,129,1,1,1,1,1,3,3,3,7,7,135,143,207,222,254,252,252,252,248,248,112,48,32,0,0,0,0,0,1,1,1,3,7,135,135,207,223,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,1,3,7,7,15,31,63,63,127,126,254,248,248,240,224,224,192,128,128,0,1,3,7,15,15,31,31,62,60,120,120,112,96,224,224,192,192,192,128,128,63,63,63,127,127,127,127,127,63,63,63,62,60,60,28,30,30,30,15,15,15,7,7,131,131,131,193,193,192,224,224,224,240,240,240,120,120,124,124,62,62,30,31,31,15,15,7,7,7,3,3,1,1,3,3,3,7,7,7,15,15,15,143,159,159,223,255,255,255,255,255,255,255,255,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,3,7,7,7,7,15,14,14,30,28,28,24,56,56,56,48,48,48,112,112,112,96,96,97,97,12,12,12,12,12,12,12,12,12,12,12,14,14,14,14,14,6,134,134,135,135,135,135,131,131,131,131,195,193,193,193,193,192,192,224,224,224,224,224,224,224,240,240,240,240,240,248,248,248,248,248,252,252,252,252,254,254,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
