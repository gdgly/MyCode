

#include "printf.h"

struct __FILE
{
    int handle;
};

FILE __stdout;

int fputc(int ch, FILE *f)
{
    while((USART3->ISR & 0X40)==0);
    USART3->TDR = (uint8_t) ch;
    return ch;
}

int my_putc(int ch)
{
    while((USART3->ISR & 0X40)==0);
    USART3->TDR = (uint8_t) ch;
    return ch;
}

void my_printf(uint8_t * buff, uint16_t len)
{
    uint16_t i = 0;

    while(i < len)
    {
        my_putc(buff[i++]);
    }
}

