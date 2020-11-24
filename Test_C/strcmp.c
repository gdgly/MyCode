

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<math.h>

//相同返回0	//不同返回-1
int my_strcmp(char * src, char * dest)
{
	int i = 0;
	while(src[i] != '\0')
	{
		if(src[i] == dest[i])
			i++;
		else
			return -1;
	}
	
	if(dest[i] == '\0')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

 
int main()
{

	printf("resault = %d\r\n", my_strcmp("1234", "1235"));
	printf("resault = %d\r\n", my_strcmp("123", "1234"));
	printf("resault = %d\r\n", my_strcmp("1234", "123"));
	printf("resault = %d\r\n", my_strcmp("1234", "1234"));
	
	
	printf("resault = %d\r\n", my_strcmp("abc", "acd"));
	printf("resault = %d\r\n", my_strcmp("aaa", "aaa"));
	return 0;
}


