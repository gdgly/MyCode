/*
 ============================================================================
 Name        : test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "test.h"
#include "main.h"

#include "stdio.h"



int print_test(void)
{
	char buff[10] = {0};

	for(int i=0; i<10; i++)
	{
         *buff = 'a';
         buff++;
	}
	printf("%s\r\n", buff);
	printf("HelloWorld\r\n");
	return 0;
}


int app_test(void)
{
	//left_move();

	//gps_test();
	//test_pn_size();
	//test_priority_level();
	print_test();


	return 0;
}


