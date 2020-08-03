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
#include "app_test.h"
#include "pin.h"
#include "drv_gpio.h"
#include "drv_usart.h"
#include "drv_flash.h"
#include "string.h"
#include "sfud.h"
#include "spi_flash_sfud.h"
#include "dfs_posix.h"
#include "sensor_inven_lsm6ds0.h"
#include "sensor.h"

//#include "os.h"
#include <rtthread.h>

static rt_device_t usart_device;

rt_err_t uart_rx_callback(rt_device_t dev, rt_size_t size)
{
	
	return 0;
}

__weak rt_err_t uart_tx_callback(rt_device_t dev, void *buffer)
{
	
	return 0;
}

rt_err_t can_rx_callback(rt_device_t dev, rt_size_t size)
{
	
	return 0;
}
/**
 * @name: test_gpio_task
 * @test: test font
 * @msg: 
 * @param {type} 
 * @return: 
 */
void test_gpio_task(void *parameter)
{
	rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);
	rt_pin_mode(LED2_PIN, PIN_MODE_OUTPUT);
	
	for (;;)
	{
		rt_pin_write(LED1_PIN, 0);
		rt_pin_write(LED2_PIN, 1);
		rt_thread_mdelay(100);
		rt_pin_write(LED1_PIN, 1);
		rt_pin_write(LED2_PIN, 0);
		rt_thread_mdelay(100);
	}
}

/**
 * @name: uart_write
 * @test: test font
 * @msg: 
 * @param {type} 
 * @return: 
 */
int uart_write(void *ptbuf, int len)
{
	return rt_device_write(usart_device, 0, (uint8_t *)ptbuf, len);
	;
}

/**
 * @name: test_uart_task
 * @test: test font
 * @msg: 
 * @param {type} 
 * @return: 
 */
void test_uart_task(void *parameter)
{
	rt_err_t result = RT_EOK;
	struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;

	config.baud_rate = BAUD_RATE_115200;
	config.data_bits = DATA_BITS_8;
	config.parity = STOP_BITS_1;
	config.stop_bits = PARITY_NONE;
	config.bufsz = 128;
	
	usart_device = rt_device_find(USART_DEVICE);
	if (RT_NULL != usart_device)
	{
		rt_kprintf("usart device find success.\r\n");
		result = rt_device_open(usart_device, RT_DEVICE_OFLAG_RDWR|RT_DEVICE_FLAG_INT_RX);
		if (RT_EOK == result)
		{
			rt_kprintf("uart device open success.\r\n");
		}
	}

	rt_device_control(usart_device, RT_DEVICE_CTRL_CONFIG, &config);
	rt_device_set_rx_indicate(usart_device, uart_rx_callback);			/* 注册接收的回调函数 */
	//rt_device_set_tx_complete();										/* 注册发送完成的回调函数 */
	
	for (;;)
	{
		uart_write("Hello Ninebot.\r\n", 16);
		rt_thread_delay(500);
	}
}

/**
 * @name: test_flash_task
 * @test: test font
 * @msg: 
 * @param {type} 
 * @return: 
 */
void test_adc_flash_task(void *parameter)
{
	rt_adc_device_t adc;
	sfud_flash_t sfud_flash;
	rt_err_t result = RT_EOK;
	
	char test_str[] = "ninebot_Hello_SPI_Device!\r\n";
	char test_buff[100] = {0};

	adc = (rt_adc_device_t)rt_device_find(ADC_DEVICE);
	rt_adc_enable(adc,BAT_CHANNEL);
	rt_kprintf("batt: %d mv\r\n",(rt_adc_read(adc,BAT_CHANNEL)*200 * 33) >> 12);
	
	if (0 == dfs_mkfs("elm","W25QXX"))
	{
		rt_kprintf("file system mkfs success.\r\n");
		if (0 == dfs_mount("W25QXX","/","elm",0,0))
			rt_kprintf("file system mount success.\r\n");
	}

	sfud_flash = rt_sfud_flash_find(SPI1_DEVICE);
	if (RT_NULL != sfud_flash)
	{
		rt_kprintf("sfud device find success.\r\n");
	}
	//sfud_chip_erase(sfud_flash);
	sfud_erase(sfud_flash,0,strlen(test_str));
	sfud_write(sfud_flash, 0, strlen(test_str), (uint8_t *)test_str);
	sfud_read(sfud_flash, 0, strlen(test_str), (uint8_t *)test_buff);
    rt_kprintf("w25qxx read:%s\r\n", test_buff);

	for (;;)
	{
		rt_thread_mdelay(1000);
	}
}

/**
 * @name: test_can_task
 * @test: test font
 * @msg: 
 * @param {type} 
 * @return: 
 */
struct rt_can_msg msg = {0};           /* CAN 消息 */
void test_can_task(void *parameter)
{
	rt_device_t can_device;
	rt_uint16_t size = 0;
	rt_err_t result = RT_EOK;
	
	can_device = rt_device_find(CAN_DEVICE);
	if (can_device != RT_NULL)
	{
		rt_kprintf("can device find success.\r\n");
		result = rt_device_open(can_device,RT_DEVICE_FLAG_INT_TX|RT_DEVICE_FLAG_INT_RX);
		if (RT_EOK == result)
		{
			rt_kprintf("can device open success!\r\n");
		}
	}
	
	rt_device_control(can_device,RT_CAN_CMD_SET_BAUD,(void *)CAN1MBaud);
	rt_device_control(can_device, RT_CAN_CMD_SET_MODE, (void *)RT_CAN_MODE_NORMAL);
	rt_device_set_rx_indicate(can_device, can_rx_callback);
	
	msg.id = 0x66;              /* ID 为 0x78 */
	msg.ide = RT_CAN_STDID;     /* 标准格式 */
	msg.rtr = RT_CAN_DTR;       /* 数据帧 */
	msg.len = 8;                /* 数据长度为 8 */
	/* 待发送的 8 字节数据 */
	msg.data[0] = 0x00;
	msg.data[1] = 0x11;
	msg.data[2] = 0x22;
	msg.data[3] = 0x33;
	msg.data[4] = 0x44;
	msg.data[5] = 0x55;
	msg.data[6] = 0x66;
	msg.data[7] = 0x77;
	
	for(;;)
	{
		msg.data[0]++;
		size = rt_device_write(can_device,0,&msg,sizeof(msg));
		rt_thread_mdelay(1);
	}
}

/**
 * @name: test_rtc_task
 * @test: test font
 * @msg: 
 * @param {type} 
 * @return: 
 */
void test_rtc_task(void *parameter)
{
	time_t now;     					/* 保存获取的当前时间值 */
	
	set_date(2019, 11, 23);
	set_time(16, 18, 50);
	
	rt_thread_mdelay(1000);
	now = time(RT_NULL);				/* 从写C库中的函数，获取本地时间 */
	rt_kprintf("%s\n", ctime(&now));	/* ctime 将时间信息转化为字符串 */
	rt_thread_mdelay(3000);
	now = time(RT_NULL);
	rt_kprintf("%s\n", ctime(&now));	/* ctime 将时间信息转化为字符串 */

	for(;;)
	{
		rt_thread_mdelay(1000);
	}
}

/**
 * @name: test_sensor_task
 * @test: test font
 * @msg: 
 * @param {type} 
 * @return: 
 */
void test_sensor_task(void *parameter)
{
//	rt_kprintf("sensor test start.\r\n");
//	struct rt_sensor_config config;
//	config.intf.dev_name = "spi2";
//	rt_hw_lsm6ds0_init("lsm",&config);
	
	for(;;)
	{
		rt_thread_mdelay(100);
	}
}

















