/**
 * @file flash.c
 * @author Segway Inside 
 * @brief STM32 Ƭ�� FLASH �����ӿں���
 * @version 1.0
 * @date 2020-01-21
 * 
 * @copyright Copyright (c) 2020 �ɶ������������Ƽ����޹�˾
 * All rights reserved.
 * 
 */

#include "mcu_flash.h"

int flash_read(uint32_t addr, uint8_t *buf, uint32_t size)
{
    __disable_irq();
    int ret = stm32_flash_read(addr, buf, size);
    __enable_irq();
    return ret;
}

int flash_write(uint32_t addr, const uint8_t *buf, uint32_t size)
{
    __disable_irq();
    int ret = stm32_flash_write(addr, buf, size);
    __enable_irq();
    return ret;
    
}

int flash_erase(uint32_t addr, uint32_t size)
{
    __disable_irq();
    int ret = stm32_flash_erase(addr, size);
    __enable_irq();
    return ret;
}


