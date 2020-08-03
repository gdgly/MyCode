
/* RT-Thread config file */

#ifndef __RTTHREAD_CFG_H__
#define __RTTHREAD_CFG_H__

#include "RTE_Components.h"

// <<< Use Configuration Wizard in Context Menu >>>
// <h>Basic Configuration
// <o>Maximal level of thread priority <8-256>
//	<i>Default: 32
#define RT_THREAD_PRIORITY_MAX 	8

// <o>OS tick per second
//  <i>Default: 1000   (1ms)
#define RT_TICK_PER_SECOND 		1000

// <o>Alignment size for CPU architecture data access
//	<i>Default: 4
#define RT_ALIGN_SIZE 4

// <o>the max length of object name<2-16>
//	<i>Default: 8
#define RT_NAME_MAX 8

// <c1>Using RT-Thread components initialization
//  <i>Using RT-Thread components initialization
#define RT_USING_COMPONENTS_INIT
// </c>

// <c1>Using user main
//  <i>Using user main
#define RT_USING_USER_MAIN
// </c>

// <o>the size of main thread<1-4086>
//	<i>Default: 512
#define RT_MAIN_THREAD_STACK_SIZE 512

// <c1>using tiny size of memory
//  <i>using tiny size of memory
#define RT_USING_TINY_SIZE
// </c>
// </h>

// <h>Debug Configuration
// <c1>enable kernel debug configuration
//  <i>Default: enable kernel debug configuration
//#define RT_DEBUG
// </c>

// <o>enable components initialization debug configuration<0-1>
//  <i>Default: 0
//#define RT_DEBUG_INIT

// <c1>thread stack over flow detect
//  <i> Diable Thread stack over flow detect
#define RT_USING_OVERFLOW_CHECK
// </c>
// </h>

// <h>Hook Configuration
// <c1>using hook
//  <i>using hook
//#define RT_USING_HOOK
// </c>

// <c1>using idle hook
//  <i>using idle hook
//#define RT_USING_IDLE_HOOK
// </c>
// </h>

// <e>Software timers Configuration
// <i> Enables user timers
#define RT_USING_TIMER_SOFT

// <o>The priority level of timer thread <0-31>
//  <i>Default: 4
#define RT_TIMER_THREAD_PRIO 1

// <o>The stack size of timer thread <0-8192>
//  <i>Default: 512
#define RT_TIMER_THREAD_STACK_SIZE 512

// <o>The soft-timer tick per second <0-1000>
//  <i>Default: 100
#define RT_TIMER_TICK_PER_SECOND 1000
// </e>

// <h>IPC(Inter-process communication) Configuration
// <c1>Using Semaphore
//  <i>Using Semaphore
#define RT_USING_SEMAPHORE
// </c>

// <c1>Using Mutex
//  <i>Using Mutex
#define RT_USING_MUTEX
// </c>

// <c1>Using Event
//  <i>Using Event
#define RT_USING_EVENT
// </c>

// <c1>Using MailBox
//  <i>Using MailBox
//#define RT_USING_MAILBOX
// </c>

// <c1>Using Message Queue
//  <i>Using Message Queue
#define RT_USING_MESSAGEQUEUE
// </c>
// </h>

// <h>Memory Management Configuration
// <c1>Using Memory Pool Management
//  <i>Using Memory Pool Management
//#define RT_USING_MEMPOOL
// </c>
// <c1>Dynamic Heap Management
//  <i>Dynamic Heap Management
#define RT_USING_HEAP
// </c>
// <c1>using small memory
//  <i>using small memory
#define RT_USING_SMALL_MEM
// </c>
// </h>

// <h>Console Configuration
// <c1>Using console
//  <i>Using console
#define RT_USING_CONSOLE
// </c>

// <o>the buffer size of console <1-1024>
//  <i>the buffer size of console
//  <i>Default: 128  (128Byte)
#define RT_CONSOLEBUF_SIZE 128

// <s>The device name for console
//  <i>The device name for console
//  <i>Default: uart0
#define RT_CONSOLE_DEVICE_NAME ""
// </h>

#define RT_USING_DEVICE

/*******************************
 * 组件 使能
 * **************************/
#define RT_USING_ULOG

/*******************************
 * 组件 配置
 * **************************/
#if defined(RT_USING_ULOG)
#define ULOG_BACKEND_USING_CONSOLE
//#define ULOG_TIME_USING_TIMESTAMP
//#define ULOG_USING_FILTER
#define ULOG_USING_COLOR
#define ULOG_OUTPUT_TIME
#define ULOG_OUTPUT_LEVEL
#define ULOG_OUTPUT_LVL        LOG_LVL_DBG
#define ULOG_OUTPUT_TAG
#define ULOG_OUTPUT_THREAD_NAME
#endif

/******************************
* AT组件配置
*****************************/
#define RT_USING_AT
#define AT_USING_CLIENT
#define xAT_USING_CLI
#define AT_CLIENT_NUM_MAX 1
#define xAT_USING_SOCKET
#define AT_PRINT_RAW_CMD
/*******************************
 * 设备 使能
 * **************************/
#if defined(RT_USING_DEVICE)
#define RT_USING_DEVICE
#define RT_USING_SERIAL
#define RT_USING_PIN
#define RT_USING_ADC
#define RT_USING_RTC
#define RT_USING_I2C
#define RT_USING_I2C_BITOPS
#define RT_USING_SPI
//#define RT_USING_CAN
#define xRT_USING_W25QXX
#define RT_USING_WDT
#define RT_USING_RTC
#endif

/*******************************
 * BSP 配置
 * **************************/
#define SOC_SERIES_STM32F0

#if defined(RT_USING_SERIAL)
#define BSP_USING_UART1
#define BSP_USING_UART2
#define BSP_USING_UART3
#define BSP_USING_UART4
#endif

#if defined(RT_USING_ADC)
#define BSP_USING_ADC1
#endif

#if defined(RT_USING_RTC)
#define BSP_USING_ONCHIP_RTC
#endif

#if defined(RT_USING_I2C)
#define xBSP_USING_I2C1
#define BSP_I2C1_SCL_PIN    GET_PIN(B,6)		
#define BSP_I2C1_SDA_PIN    GET_PIN(A,10)
#endif

#if defined(RT_USING_I2C)
#define BSP_USING_I2C2
#define BSP_I2C2_SCL_PIN    GET_PIN(A,11)		
#define BSP_I2C2_SDA_PIN    GET_PIN(A,10)
#endif

#if defined(RT_USING_SPI)
#define BSP_USING_SPI2
#define BSP_USING_SPI_FLASH
#define BSP_SPI2_TX_USING_DMA				/*stm32f091的MDA中断向量是一个发送和接收都是用DMA需要更改底层驱动文件*/
//#define BSP_SPI2_RX_USING_DMA
#endif

#if defined(RT_USING_SFUD)
// #define RT_SFUD_USING_SFDP
#define SFUD_USING_FLASH_INFO_TABLE
#define SFUD_INFO(...)
#endif

#define xRT_USING_W25QXX
#define BSP_USING_ON_CHIP_FLASH

#if defined(RTE_USING_FINSH)
#endif //RTE_USING_FINSH

#if defined(RT_USING_RTC)
#define BSP_USING_ONCHIP_RTC
#endif //RT_USING_RTC

// <<< end of configuration section >>>

#endif

