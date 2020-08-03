/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2019-11-14 23:11:08
 * @LastEditors: sueRimn
 * @LastEditTime: 2019-11-16 14:04:28
 */
/**
 * @file app_main.c
 * @author Segway Insight 
 * @brief 
 * @version 0.1
 * @date 2019-11-15
 * 
 * @copyright Copyright (c) 2019 纳恩博（北京）科技有限公司
 * All rights reserved.
 * 
 */

#include <rtthread.h>
#include "watchdog.h"

#include "app_test.h"

#define IWDG_DEVICE_NAME		"wdt"
#define WDT_KEEP_TIME			4095

void test_gpio_task(void *parameter);
void test_uart_task(void *parameter);
void test_adc_flash_task(void *parameter);
void test_can_task(void *parameter);
void test_rtc_task(void *parameter);
void test_sensor_task(void *parameter);

rt_thread_t led;
rt_thread_t usart;
rt_thread_t flash;
rt_thread_t can;
rt_thread_t rtc;
rt_thread_t sensor;

rt_watchdog_t watchdog;
rt_device_t wdt;
rt_uint32_t keeptime = WDT_KEEP_TIME;

/**
 * @name: main
 * @test: test font
 * @msg: 
 * @param {type} 
 * @return: 
 */
int main(void)
{
	wdt = rt_device_find(IWDG_DEVICE_NAME);
	if (RT_NULL != wdt)
    {
        rt_kprintf("find %s success!\n", IWDG_DEVICE_NAME);
		rt_device_open(wdt,RT_DEVICE_OFLAG_OPEN);
    }
	
    led = rt_thread_create("led", test_gpio_task, RT_NULL, 					/*创建LED处理线程*/
                           256, 5, 20);
    RT_ASSERT(yellow != RT_NULL);
    rt_thread_startup(led);

    usart = rt_thread_create("usart", test_uart_task, RT_NULL, 				/*创建USART处理线程*/
                             512, 4, 20);
    RT_ASSERT(usart != RT_NULL);
    rt_thread_startup(usart);

    flash = rt_thread_create("flash", test_adc_flash_task, RT_NULL, 		/*创建flash处理线程*/
                             1024, 3, 20);
    RT_ASSERT(flash != RT_NULL);
    rt_thread_startup(flash);

    can = rt_thread_create("can", test_can_task, RT_NULL, 					/*创建can处理线程*/
                             256, 2, 20);
    RT_ASSERT(flash != RT_NULL);
    rt_thread_startup(can);	
	
	rtc = rt_thread_create("rtc", test_rtc_task, RT_NULL, 					/*创建rtc测试线程*/
                             256, 1, 20);
    RT_ASSERT(flash != RT_NULL);
    rt_thread_startup(rtc);	
	
	sensor = rt_thread_create("sensor", test_sensor_task, RT_NULL, 			/*创建sensor测试线程*/
                             512, 6, 20);
    RT_ASSERT(flash != RT_NULL);
    rt_thread_startup(sensor);	
	
    for(;;)
    {
		rt_device_control(wdt,RT_DEVICE_CTRL_WDT_KEEPALIVE,&keeptime);
        rt_thread_delay(10);
    }
}
