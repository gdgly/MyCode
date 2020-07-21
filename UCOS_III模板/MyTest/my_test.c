

#include "my_test.h"
#include "usart.h"
#include "stdio.h"

#include "task.h"




uint8_t	buff[100] = {"test_debug"};
void test_debug(void)
{
    DBG_INFO("mq_receive data : %s \r\n", buff);

}



int print_test(void)
{
	char buff[10] = {0};
    char * p = buff;

	for(int i=0; i<10; i++)
	{
         *p = 'a';
         p++;
        //buff++;   //不能直接写buff++;
	}
	printf("%s\r\n", buff);

	return 0;
}


int app_test(void)
{
    
    printf("%s\r\n", __func__);
	//left_move();

	//gps_test();
	//test_pn_size();
	//test_priority_level();
	print_test();


	return 0;
}



