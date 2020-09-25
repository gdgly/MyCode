#ifndef STLINK_CHIPID_H_
#define STLINK_CHIPID_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 新增元器件可以从对应的网址中查看，同步更新到该文件即可
 * 
 */

/**
 * https://github.com/STMicroelectronics/STM32CubeF0/blob/master/Drivers/CMSIS/Device/ST/STM32F0xx/Include/stm32f0xx.h
 */
#if defined (STM32F030x6) || defined (STM32F030x8) ||                           \
    defined (STM32F031x6) || defined (STM32F038xx) ||                           \
    defined (STM32F042x6) || defined (STM32F048xx) || defined (STM32F070x6) ||  \
    defined (STM32F051x8) || defined (STM32F058xx) ||                           \
    defined (STM32F071xB) || defined (STM32F072xB) || defined (STM32F078xx) || defined (STM32F070xB) || \
    defined (STM32F091xC) || defined (STM32F098xx) || defined (STM32F030xC)
#include "stm32f0xx.h"
#define SOC_SERIES_STM32F0
#endif

/**
 * https://github.com/STMicroelectronics/STM32CubeF1/blob/master/Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h
 */
#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || \
    defined (STM32F101xB) || defined (STM32F101xE) || defined (STM32F101xG) || defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || \
    defined (STM32F103xB) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
#include "stm32f1xx.h"
#define SOC_SERIES_STM32F1
#endif

/**
 * https://github.com/STMicroelectronics/STM32CubeF2/blob/master/Drivers/CMSIS/Device/ST/STM32F2xx/Include/stm32f2xx.h
 */
#if defined (STM32F205xx) || defined (STM32F215xx) || defined (STM32F207xx) || defined (STM32F217xx)
#include "stm32f2xx.h"
#define SOC_SERIES_STM32F2
#endif

/**
 * https://github.com/STMicroelectronics/STM32CubeF3/blob/master/Drivers/CMSIS/Device/ST/STM32F3xx/Include/stm32f3xx.h
 */
#if defined (STM32F301x8) || defined (STM32F302x8) || defined (STM32F318xx) || \
    defined (STM32F302xC) || defined (STM32F303xC) || defined (STM32F358xx) || \
    defined (STM32F303x8) || defined (STM32F334x8) || defined (STM32F328xx) || \
    defined (STM32F302xE) || defined (STM32F303xE) || defined (STM32F398xx) || \
    defined (STM32F373xC) || defined (STM32F378xx)
#include "stm32f3xx.h"
#define SOC_SERIES_STM32F3
#endif

/**
 * https://github.com/STMicroelectronics/STM32CubeF4/blob/master/Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h
 */
#if defined (STM32F405xx) || defined (STM32F415xx) || defined (STM32F407xx) || defined (STM32F417xx) || \
    defined (STM32F427xx) || defined (STM32F437xx) || defined (STM32F429xx) || defined (STM32F439xx) || \
    defined (STM32F401xC) || defined (STM32F401xE) || defined (STM32F410Tx) || defined (STM32F410Cx) || \
    defined (STM32F410Rx) || defined (STM32F411xE) || defined (STM32F446xx) || defined (STM32F469xx) || \
    defined (STM32F479xx) || defined (STM32F412Cx) || defined (STM32F412Rx) || defined (STM32F412Vx) || \
    defined (STM32F412Zx) || defined (STM32F413xx) || defined (STM32F423xx)
#include "stm32f4xx.h"
#define SOC_SERIES_STM32F4
#endif

/**
 * https://github.com/STMicroelectronics/STM32CubeF7/blob/master/Drivers/CMSIS/Device/ST/STM32F7xx/Include/stm32f7xx.h
 */
#if defined (STM32F756xx) || defined (STM32F746xx) || defined (STM32F745xx) || defined (STM32F767xx) || \
    defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F722xx) || \
    defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F730xx) || \
    defined (STM32F750xx)
#include "stm32f7xx.h"
#define SOC_SERIES_STM32F7
#endif

/**
 * https://github.com/STMicroelectronics/STM32CubeH7/blob/master/Drivers/CMSIS/Device/ST/STM32H7xx/Include/stm32h7xx.h
 */
#if defined (STM32H743xx) || defined (STM32H753xx)  || defined (STM32H750xx) || defined (STM32H742xx) || \
    defined (STM32H745xx) || defined (STM32H755xx)  || defined (STM32H747xx) || defined (STM32H757xx)
#include "stm32h7xx.h"
#define SOC_SERIES_STM32H7
#endif

/**
 * https://github.com/STMicroelectronics/STM32CubeL4/blob/master/Drivers/CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h
 */
#if defined (STM32L010x4) || defined (STM32L010x6) || defined (STM32L010x8) || defined (STM32L010xB) || \
    defined (STM32L011xx) || defined (STM32L021xx) || \
    defined (STM32L031xx) || defined (STM32L041xx) || \
    defined (STM32L051xx) || defined (STM32L052xx) || defined (STM32L053xx) || \
    defined (STM32L061xx) || defined (STM32L062xx) || defined (STM32L063xx) || \
    defined (STM32L071xx) || defined (STM32L072xx) || defined (STM32L073xx) || \
    defined (STM32L081xx) || defined (STM32L082xx) || defined (STM32L083xx)
#include "stm32l0xx.h"
#define SOC_SERIES_STM32L0
#endif

/**
 * https://github.com/STMicroelectronics/STM32CubeL4/blob/master/Drivers/CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h
 */
#if defined (STM32L100xB) || defined (STM32L100xBA) || defined (STM32L100xC) || \
    defined (STM32L151xB) || defined (STM32L151xBA) || defined (STM32L151xC) || defined (STM32L151xCA) || defined (STM32L151xD) || defined (STM32L151xDX) || defined (STM32L151xE) || \
    defined (STM32L152xB) || defined (STM32L152xBA) || defined (STM32L152xC) || defined (STM32L152xCA) || defined (STM32L152xD) || defined (STM32L152xDX) || defined (STM32L152xE) || \
    defined (STM32L162xC) || defined (STM32L162xCA) || defined (STM32L162xD) || defined (STM32L162xDX) || defined (STM32L162xE)
#include "stm32l1xx.h"
#define SOC_SERIES_STM32L1
#endif

/**
 * https://github.com/STMicroelectronics/STM32CubeL4/blob/master/Drivers/CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h
 */
#if defined (STM32L412xx) || defined (STM32L422xx) || \
    defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || defined (STM32L443xx) || \
    defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || \
    defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#include "stm32l4xx.h"
#define SOC_SERIES_STM32L4
#endif

/**
 * https://github.com/STMicroelectronics/STM32CubeG0/blob/master/Drivers/CMSIS/Device/ST/STM32G0xx/Include/stm32g0xx.h
 */
#if defined (STM32G071xx) || defined (STM32G081xx) || defined (STM32G070xx) || defined (STM32G030xx) || defined (STM32G031xx) || defined (STM32G041xx)
#include "stm32g0xx.h"
#define SOC_SERIES_STM32G0
#endif

/**
 * https://github.com/STMicroelectronics/STM32CubeG4/blob/master/Drivers/CMSIS/Device/ST/STM32G4xx/Include/stm32g4xx.h
 */
#if defined (STM32G431xx) || defined (STM32G441xx) || \
    defined (STM32G471xx) || defined (STM32G473xx) || defined (STM32G474xx) || defined (STM32G483xx) || defined (STM32G484xx) || defined (STM32GBK1CB)
#include "stm32g4xx.h"
#define SOC_SERIES_STM32G4
#endif





/**
 * Chip IDs are explained in the appropriate programming manual for the
 * DBGMCU_IDCODE register (0xE0042000)
 * stm32 chipids, only lower 12 bits..
 */
enum stlink_stm32_chipids {
	STLINK_CHIPID_UNKNOWN                = 0x000,

	STLINK_CHIPID_STM32_F1_LOW           = 0x412,
	STLINK_CHIPID_STM32_F1_MEDIUM        = 0x410,
	STLINK_CHIPID_STM32_F1_HIGH          = 0x414,
	STLINK_CHIPID_STM32_F2               = 0x411,
	STLINK_CHIPID_STM32_F4               = 0x413,
	STLINK_CHIPID_STM32_L4               = 0x415,
	STLINK_CHIPID_STM32_L1_MEDIUM        = 0x416,
	STLINK_CHIPID_STM32_L0               = 0x417,
	STLINK_CHIPID_STM32_F1_CONN          = 0x418,
	STLINK_CHIPID_STM32_F4_HD            = 0x419,
	STLINK_CHIPID_STM32_F1_VL_MEDIUM_LOW = 0x420,
	STLINK_CHIPID_STM32_F446             = 0x421,
	STLINK_CHIPID_STM32_F3               = 0x422,
	STLINK_CHIPID_STM32_F4_LP            = 0x423,
	STLINK_CHIPID_STM32_L0_CAT2          = 0x425,
	STLINK_CHIPID_STM32_L1_MEDIUM_PLUS   = 0x427,
	STLINK_CHIPID_STM32_F1_VL_HIGH       = 0x428,
	STLINK_CHIPID_STM32_L1_CAT2          = 0x429,
	STLINK_CHIPID_STM32_F1_XL            = 0x430,
	STLINK_CHIPID_STM32_F411RE           = 0x431,
	STLINK_CHIPID_STM32_F37x             = 0x432,
	STLINK_CHIPID_STM32_F4_DE            = 0x433,
	STLINK_CHIPID_STM32_F4_DSI           = 0x434,
	/*
	* 0x435 covers STM32L43xxx and STM32L44xxx devices
	* 0x461 covers STM32L496xx and STM32L4A6xx devices
	* 0x462 covers STM32L45xxx and STM32L46xxx devices
	* 0x464 covers STM32L41xxx and STM32L42xxx devices
	*/
	STLINK_CHIPID_STM32_L43X             = 0x435,
	STLINK_CHIPID_STM32_L496X            = 0x461,
	STLINK_CHIPID_STM32_L46X             = 0x462,
	STLINK_CHIPID_STM32_L41X             = 0x464,
	/*
	* 0x436 is actually assigned to some L1 chips that are called "Medium-Plus"
	* and some that are called "High".  0x427 is assigned to the other "Medium-
	* plus" chips.  To make it a bit simpler we just call 427 MEDIUM_PLUS and
	* 0x436 HIGH.
	*/
	STLINK_CHIPID_STM32_L1_HIGH          = 0x436,
	STLINK_CHIPID_STM32_L152_RE          = 0x437,
	STLINK_CHIPID_STM32_F334             = 0x438,
	STLINK_CHIPID_STM32_F3_SMALL         = 0x439,
	STLINK_CHIPID_STM32_F0               = 0x440,
	STLINK_CHIPID_STM32_F412             = 0x441,
	STLINK_CHIPID_STM32_F09X             = 0x442,
	STLINK_CHIPID_STM32_F0_SMALL         = 0x444,
	STLINK_CHIPID_STM32_F04              = 0x445,
	STLINK_CHIPID_STM32_F303_HIGH        = 0x446,
	STLINK_CHIPID_STM32_L0_CAT5          = 0x447,
	STLINK_CHIPID_STM32_F0_CAN           = 0x448,
	STLINK_CHIPID_STM32_F7               = 0x449,	/* This ID is found on the NucleoF746ZG board */
	STLINK_CHIPID_STM32_F7XXXX           = 0x451,
	STLINK_CHIPID_STM32_F72XXX           = 0x452,	/* This ID is found on the NucleoF722ZE board */
	STLINK_CHIPID_STM32_L011             = 0x457,
	STLINK_CHIPID_STM32_F410             = 0x458,
	STLINK_CHIPID_STM32_F413             = 0x463,
	STLINK_CHIPID_STM32_L4RX             = 0x470, // taken from the STM32L4R9I-DISCO board
	STLINK_CHIPID_STM32_G0X1             = 0x460,
	STLINK_CHIPID_STM32_WB55             = 0x495
};

/**
 * Chipid parameters
 */
struct stlink_chipid_params {
	uint32_t chip_id;
	char *description;
	uint32_t flash_size_reg;
	uint32_t flash_pagesize;
	uint32_t sram_size;
	uint32_t bootrom_base;
	uint32_t bootrom_size;
};

const struct stlink_chipid_params *stlink_chipid_get_params(uint32_t chipid);

#ifdef __cplusplus
}
#endif

#endif /* STLINK_CHIPID_H_ */
