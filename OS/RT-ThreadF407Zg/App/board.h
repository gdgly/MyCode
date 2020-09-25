/**
 * @file board.h
 * @author Segway Insight 
 * @brief 
 * @version 0.1
 * @date 2019-10-24
 * 
 * @copyright Copyright (c) 2019 纳恩博（北京）科技有限公司
 * All rights reserved.
 * 
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include <rtthread.h>
#include "drv_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef STM32F407xx
	//#include "stm32f4xx_hal.h"			/*这个位置一定要修改对应系列的单片机才能调用到HAL库的API*/
	#include "stm32f4xx.h"
#endif

/*******************************
 * HEAP 配置
 * **************************/
#define STM32_SRAM_SIZE (120)	/*需要根据对应的单片机修改相应的Heap的大小*/
#define STM32_SRAM_END ((void *)(0x20000000 + STM32_SRAM_SIZE * 1024))

#define STM32_FLASH_START_ADRESS ((uint32_t)0x08000000)
#define STM32_FLASH_SIZE (1024 * 1024)
#define STM32_FLASH_END_ADDRESS ((uint32_t)(STM32_FLASH_START_ADRESS + STM32_FLASH_SIZE))

#ifdef __CC_ARM
    extern int Image$$RW_IRAM1$$ZI$$Limit;
#define HEAP_BEGIN ((void *)&Image$$RW_IRAM1$$ZI$$Limit)
#elif __ICCARM__
#pragma section = "IOTTACK"
#define HEAP_BEGIN (__segment_end("IOTTACK"))
#else
extern int __bss_end;
#define HEAP_BEGIN ((void *)&__bss_end)
#endif

#define HEAP_END STM32_SRAM_END



void SystemClock_Config(void);

#ifdef __cplusplus
}
#endif

#endif
