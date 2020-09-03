#include <stdio.h>
#include <string.h>


int main(void)
{
	char buff[20] = {0xcc};
	
	memset(buff, 0xCC, 20);
	memcpy(buff, "Hello", 4);
	
	printf("%s",buff);
	
	printf("\r\n");
	
	for(int i=0; i<20; i++)
	{
		printf("%x ",buff[i]);
	}
}
