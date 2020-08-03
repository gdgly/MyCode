#ifndef _SDMMC_SDCARD_H
#define _SDMMC_SDCARD_H
#include <rtthread.h>
#include <board.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal_sd.h"
#include <rtdevice.h>

#if defined(BSP_SDIO_SDCARD)
#define SD_TIMEOUT ((uint32_t)100000000)            

#define SD_DMA_MODE    		1     //0:轮询模式   1：DMA模式

extern SD_HandleTypeDef        SDCARD_Handler;    
extern HAL_SD_CardInfoTypeDef  SDCardInfo;        
       
rt_uint8_t SD_Init(void);
//rt_uint8_t HAL_SD_GetCardInfo(HAL_SD_CardInfoTypeDef *cardinfo);
//HAL_StatusTypeDef HAL_SD_GetCardInfo(SD_HandleTypeDef *hsd, HAL_SD_CardInfoTypeDef *pCardInfo);
#endif
#endif
