/*
 * buff_test.c
 *
 *  Created on: 2020年7月7日
 *      Author: yufei.fan
 */

#include "main.h"

//测试转义字符
void buff_test(void)
{
	char json_buff[] = "{\"results\":[{\"location\":{\"id\":\"WX4FBXXFKE4F\",\"name\":\"Beijing\"},\"now\":{\"temperature\":\"18\"}}]}";

	char hello[] = "\"HelloWorld!\"";


	int size = sizeof(json_buff);
	printf("size = %d\n", size);

	size = sizeof(hello);
	printf("size = %d\n", size);
}
