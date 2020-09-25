#ifndef __APP_TEST_H
#define __APP_TEST_H

#include "rtdevice.h"
#include "stm32f4xx.h"
#include "board.h"
#define FLASH_TEST_ADDR 	((FLASH_BASE‬) + (1024 * 120)) 		//120k

/*设别名称*/
#define USART_DEVICE "uart2"
#define ADC_DEVICE	 "adc1"
#define CAN_DEVICE	 "can1"
#define SPI1_DEVICE	 "spi10"

#define BAT_CHANNEL			8

#define LED1_PIN GET_PIN(F, 10)
#define LED2_PIN GET_PIN(F, 9)
#endif




//#if 0	
//	char wbuf[10] = "Ninebot";
//	char rbuf[10] = {'\0'};
//	
//	stm32_flash_erase(0x801e000,sizeof(wbuf));						/* 奇怪：这个位置如果将地址（0x801e000）换成宏会报错 */
//	stm32_flash_write(0x801e000, (rt_uint8_t *)wbuf, sizeof(wbuf));
//	stm32_flash_read(0x801e000, (rt_uint8_t *)rbuf, sizeof(rbuf));
//	if (!strcmp(wbuf, rbuf))
//	{
//		rt_kprintf("rt_thread flash test success.\r\n");
//		rt_kprintf("flash r:%s\r\n", rbuf);
//	}
//#endif	
	
	
	
	



	