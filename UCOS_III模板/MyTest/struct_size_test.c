/*
 * struct_size_test.c
 *
 *  Created on: 2020年7月7日
 *      Author: yufei.fan
 */

#include "main.h"

#include "my_test.h"


typedef struct
{
	int		a;
	char	b;
	char	c;
	float	d;
	char	e;
	double	f;

}PN_TYPE;

typedef struct
{
	char a;
	char b;
	double c;
	float g;
	PN_TYPE	pn;
	int i;
	char d;
	char e;
	float f;
	short h;


}TBOX_TYPE;
TBOX_TYPE tbox = {0};
void pn_size_test(void)
{
	int size_pn = sizeof(tbox.pn);
	printf("size_pn = %d\n", size_pn);
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

void test_struct_pack(void)
{
    uint32_t temp = 0xaaaabbbb;

    memcpy(&tbox0, &temp, 4);
    memcpy(&tbox1, &temp, 4);

    DBG_INFO("%d\r\n", sizeof(tbox0));
    DBG_INFO("%d\r\n", sizeof(tbox1));

}





