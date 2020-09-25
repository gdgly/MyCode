#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"


#include "includes.h"
#include "task.h"



int main(void)
{
    OS_ERR err;
    CPU_SR_ALLOC();

    Write_Through();				//透写
    Cache_Enable();					//打开L1-Cache
    HAL_Init();						//初始化HAL库
    Stm32_Clock_Init(432, 16, 2, 9);	//设置时钟,216Mhz
    __enable_irq();
    delay_init(216);				//延时初始化
    uart_init(115200);
    LED_Init();                     //初始化LED
    user_key_init();				//初始化按键

    delay_ms(1000);

    printf("Sys Init Success!\r\n");


    OSInit(&err);		    	 //初始化UCOSIII
    OS_CRITICAL_ENTER();	        //进入临界区
    //创建开始任务
    OSTaskCreate(( OS_TCB	*)&StartTaskTCB,		//任务控制块
                 (CPU_CHAR	*)"start task", 		//任务名字
                 (OS_TASK_PTR)start_task, 			//任务函数
                 (void		*)0,					//传递给任务函数的参数
                 (OS_PRIO	)START_TASK_PRIO,   //任务优先级
                 (CPU_STK	*)&START_TASK_STK[0],	//任务堆栈基地址
                 (CPU_STK_SIZE)START_STK_SIZE / 10,	//任务堆栈深度限位
                 (CPU_STK_SIZE)START_STK_SIZE,		//任务堆栈大小
                 (OS_MSG_QTY)0,					//任务内部消息队列能够接收的最大消息数目,为0时禁止接收消息
                 (OS_TICK	)0,					//当使能时间片轮转时的时间片长度，为0时为默认长度，
                 (void		*)0,					//用户补充的存储区
                 (OS_OPT)OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR | OS_OPT_TASK_SAVE_FP, //任务选项,为了保险起见，所有任务都保存浮点寄存器的值
                 (OS_ERR	*)&err);				//存放该函数错误时的返回值
    OS_CRITICAL_EXIT();	//退出临界区
    OSStart(&err);		//开启UCOSIII
    while(1)
    {

    }
}



