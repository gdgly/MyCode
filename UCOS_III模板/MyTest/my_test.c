

#include "my_test.h"
#include "usart.h"
#include "stdio.h"

#include "task.h"


#define DBG_INFO(fmt,...) printf("%s [%d] -<%s>:"fmt,__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__);


uint8_t	buff[100] = {"test_debug"};
void test_debug(void)
{
    DBG_INFO("mq_receive data : %s \r\n", buff);

}

#pragma pack(1)

typedef struct
{
    uint8_t	b1 : 1;
    uint8_t	b2 : 1;
    uint8_t	b3 : 1;
    uint8_t	b4 : 1;

} ERROR_TYPEE;



typedef struct
{
    uint32_t	d1 : 8;
    uint32_t	d2 : 8;
    uint32_t	d3 : 8;

    uint32_t	c1 : 1;
    uint32_t	c2 : 1;
    uint32_t	c3 : 1;
    uint32_t	c4 : 1;
    uint32_t	b1 : 1;
    uint32_t	b2 : 1;
    uint32_t	b3 : 1;
    uint32_t	b4 : 1;

} TBOX_TYPE0;

typedef struct
{
    uint32_t	d1 : 8;
    uint32_t	d2 : 8;
    uint32_t	d3 : 8;

    uint32_t	c1 : 1;
    uint32_t	c2 : 1;
    uint32_t	c3 : 1;
    uint32_t	c4 : 1;

    ERROR_TYPEE	err;

} TBOX_TYPE1;

#pragma pack()
TBOX_TYPE0 tbox0 = {0};
TBOX_TYPE1 tbox1 = {0};

void test_bit(void)
{
    uint32_t temp = 0xaaaabbbb;

    memcpy(&tbox0, &temp, 4);
    memcpy(&tbox1, &temp, 4);

    DBG_INFO("%d\r\n", sizeof(tbox0));
    DBG_INFO("%d\r\n", sizeof(tbox1));

}

uint8_t sort_buff(uint16_t *buff, uint16_t size, uint8_t flag)
{
    int i, j, temp1 = 0;

    //先排序
    if(flag == 0)
    {
        for(j = 0; j < size - 1; j++)
        {
            for(i = 0; i < size - j - 1; i++)
            {
                if(buff[i] > buff[i + 1])
                {
                    temp1 = buff[i];
                    buff[i] = buff[i + 1];
                    buff[i + 1] = temp1;
                }
            }
        }
    }
    else if(flag == 1)
    {
        for(j = 0; j < size - 1; j++)
        {
            for(i = size - 2; i >= 0; i--)
            {
                if(buff[i] < buff[i + 1])
                {
                    temp1 = buff[i];
                    buff[i] = buff[i + 1];
                    buff[i + 1] = temp1;
                }
            }
        }
    }

    return 0;
}

uint8_t data_buff[20] = {0};
void test_sort(void)
{
    for(uint8_t i = 0; i < 20; i++)
    {
        data_buff[i] = i;
    }

    sort_buff((uint16_t *)data_buff, 20, 1);

}
const uint64_t bit_buf[] =
{
		0x0000000000000001,
		0x0000000000000002,
		0x0000000000000004,
		0x0000000000000008,
		0x0000000000000010,
		0x0000000000000020,
		0x0000000000000040,
		0x0000000000000080,
		0x0000000000000100,
		0x0000000000000200,
		0x0000000000000400,
		0x0000000000000800,
		0x0000000000001000,
		0x0000000000002000,
		0x0000000000004000,
		0x0000000000008000,
		0x0000000000010000,
		0x0000000000020000,
		0x0000000000040000,
		0x0000000000080000,
		0x0000000000100000,
		0x0000000000200000,
		0x0000000000400000,
		0x0000000000800000,
		0x0000000001000000,
		0x0000000002000000,
		0x0000000004000000,
		0x0000000008000000,
		0x0000000010000000,
		0x0000000020000000,
		0x0000000040000000,
		0x0000000080000000,
		0x0000000100000000,
		0x0000000200000000,
		0x0000000400000000,
		0x0000000800000000,
		0x0000001000000000,
		0x0000002000000000,
		0x0000004000000000,
		0x0000008000000000,
		0x0000010000000000,
		0x0000020000000000,
		0x0000040000000000,
		0x0000080000000000,
		0x0000100000000000,
		0x0000200000000000,
		0x0000400000000000,
		0x0000800000000000,
		0x0001000000000000,
		0x0002000000000000,
		0x0004000000000000,
		0x0008000000000000,
		0x0010000000000000,
		0x0020000000000000,
		0x0040000000000000,
		0x0080000000000000,
		0x0100000000000000,
		0x0200000000000000,
		0x0400000000000000,
		0x0800000000000000,
		0x1000000000000000,
		0x2000000000000000,
		0x4000000000000000,
		0x8000000000000000,

};
uint8_t my_set_bit(uint64_t * data, uint8_t bit_index, uint8_t num_bool)
{
    if(data == NULL)
    {
        return 0;
    }
    if((num_bool > 1) || (bit_index > 64))
    {
        return 0;
    }


    if(num_bool == 0)
    {
        *data &= ~ bit_buf[bit_index];
    }
    else if(num_bool == 1)
    {
        *data |= bit_buf[bit_index];
    }

    return 1;
}

uint8_t my_get_bit(uint64_t data, uint8_t bit_index)
{
	if(bit_index > 64)
	{
		return 0;
	}
	
    if((data & bit_buf[bit_index]) == 0)
    {
		return 0;
    }
	else
	{
		return 1;
	}

}

uint64_t num_u64 = 0;
void test_left_move(void)
{
    num_u64 |= bit_buf[60];
    printf("%lld", num_u64);
    
}

void test_app(void)
{
//	test_sort();
//	test_debug();
//	test_bit();

    test_left_move();
    
    OSTaskSuspend((OS_TCB*)&task3_task,NULL);
}


