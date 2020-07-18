/*
 * struct_size_test.c
 *
 *  Created on: 2020年7月7日
 *      Author: yufei.fan
 */

#include "main.h"




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

