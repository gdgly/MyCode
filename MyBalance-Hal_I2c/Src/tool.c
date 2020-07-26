
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
typedef enum
{
	RETURN_DOUBLE,
	RETURN_FLOAT,
	RETURN_U32,
	RETURN_U16,
	RETURN_U8,
}AVERAGUE_RETURN_TYPE;


uint32_t get_average_uint(uint32_t * buff, uint16_t len)
{
    uint32_t sum = 0.0;
    uint16_t i = 0;
    uint16_t temp = len - 2 * RM_NUM;

	if(temp == 0)
    {
        return 0.0;
    }
	
    sort_uint(buff, len);

    for(i = RM_NUM; i < len - RM_NUM; i++)
    {
		sum += buff[i];
    }

    sum = sum / temp;

    return sum;
}


//double get_average_uint(uint32_t * buff, uint16_t len)
//{
//    double sum = 0.0;
//    uint16_t i = 0;
//    uint16_t temp = len - 2 * RM_NUM;

//	if(temp == 0)
//    {
//        return 0.0;
//    }
//	
//    sort_uint(buff, len);

//    for(i = RM_NUM; i < len - RM_NUM; i++)
//    {
//		sum += buff[i];
//    }

//    sum = sum / temp;

//    return sum;
//}




