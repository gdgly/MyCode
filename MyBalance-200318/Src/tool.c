
#include "test.h"
#include "tool.h"


void sort_uint(uint32_t *buff, uint16_t len)
{
    uint16_t i = 0;
    uint16_t j = 0;
    uint32_t temp = 0;

    for(i = 0; i < len; i++)
    {
        for(j = 0; j < len - i - 1; j++)
        {
            if(buff[j] > buff[j + 1])
            {
                temp = buff[j];
                buff[j] = buff[j + 1];
                buff[j + 1] = temp;
            }
        }
    }

}

#define RM_NUM	6

double get_average_uint(uint32_t * buff, uint16_t len)
{
    double sum = 0.0;
    uint16_t i = 0;
    uint16_t temp = len - 2 * RM_NUM;


    sort_uint(buff, len);

    for(i = RM_NUM; i < len - RM_NUM; i++)
    {
        if(buff[i] != 0)
        {
            sum += buff[i];
        }
        else
        {
            //temp--;
        }
    }

    if(temp == 0)
    {
        return 0.0;
    }

    sum = sum / temp;

    return sum;
}


