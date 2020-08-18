#include <stdio.h>


int main(void)
{
	int a = 7890;
	int b = a - 123 % 100 >> 3;
	printf("%d\n", b);
	return 0;
}


