#ifndef __MCU_FLASH_H_
#define __MCU_FLASH_H_

#include <stdint.h>

#define ERROR_FLASH_OK              0
#define ERROR_FLASH_MISALIGN        -1
#define ERROR_FLASH_OUT_OF_RANGE    -2
#define ERROR_FLASH_PROGRAM_FAIL    -3
#define ERROR_FLASH_ERASE_FAIL      -4

int stm32_flash_read(uint32_t addr, uint8_t *buf, uint32_t size);
int stm32_flash_write(uint32_t addr, const uint8_t *buf, uint32_t size);
int stm32_flash_erase(uint32_t addr, uint32_t size);

#endif

