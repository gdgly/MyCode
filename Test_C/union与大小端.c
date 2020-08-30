#include <stdio.h>


union uni_cba
{
	char	c;
	short	b;
	int		a;
};

int main(void)
{
	union uni_cba val_cba = {0};
	val_cba.c = 0x12;
	val_cba.b = 0x1234;
	val_cba.a = 0x12345678;
	
	printf("%x, %x, %x", val_cba.c, val_cba.b, val_cba.a);
}