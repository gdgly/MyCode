

#include "bsp_one_line.h"
#include "app_one_line.h"


void OneLineTest(void)
{
    if(gOneLine.rx_ok == 1)
    {
        gOneLine.rx_ok = 0;
        one_line_send(gOneLine.rx_data, gOneLine.rx_len);
    }
}
