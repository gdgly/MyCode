/**
 * @file drv_stm32_chipid.c
 * @author Segway Insight 
 * @brief 修改自 https://github.com/texane/stlink
 * @version 0.1
 * @date 2019-11-14
 * 
 * @copyright Copyright (c) 2019 纳恩博（北京）科技有限公司
 * All rights reserved.
 * 
 */
#include "drv_stm32_chipid.h"

//#define DRV_DEBUG
#define LOG_TAG "drv.chipid"
#include <drv_log.h>

#if defined(RT_USING_CHIPID)

static const struct stlink_chipid_params devices[] = 
{
#if defined(STM32F7)
    {
        //RM0410 document was used to find these paramaters
        .chip_id = STLINK_CHIPID_STM32_F7XXXX,
#if defined(DRV_DEBUG)
        .description = "F76xxx device",
#endif
        .flash_size_reg = 0x1ff0f442, // section 45.2
        .flash_pagesize = 0x800,      // No flash pages
        .sram_size = 0x80000,         // "SRAM" byte size in hex from
    },
#endif
#if defined(STM32F7)
    {
        //RM0385 and DS10916 document was used to find these paramaters
        .chip_id = STLINK_CHIPID_STM32_F7,
#if defined(DRV_DEBUG)
        .description = "F7 device",
#endif
        .flash_size_reg = 0x1ff0f442, // section 41.2
        .flash_pagesize = 0x800,      // No flash pages
        .sram_size = 0x50000,         // "SRAM" byte size in hex from DS Fig 18
    },
#endif
#if defined(STM32F7)

    {
        //RM0431 and DS document was used to find these paramaters
        .chip_id = STLINK_CHIPID_STM32_F72XXX,
#if defined(DRV_DEBUG)
        .description = "F72 device",
#endif
        .flash_size_reg = 0x1ff07a22, // section 35.2
        .flash_pagesize = 0x800,      // No flash pages
        .sram_size = 0x40000,         // "SRAM" byte size in hex from DS Fig 24
    },
#endif
#if defined(STM32F1)

    {
        // table 2, PM0063
        .chip_id = STLINK_CHIPID_STM32_F1_MEDIUM,
#if defined(DRV_DEBUG)
        .description = "F1 Medium-density device",
#endif
        .flash_size_reg = 0x1ffff7e0,
        .flash_pagesize = 0x400,
        .sram_size = 0x5000,
    },
#endif
#if defined(STM32F2)

    {
        // table 1, PM0059
        .chip_id = STLINK_CHIPID_STM32_F2,
#if defined(DRV_DEBUG)
        .description = "F2 device",
#endif
        .flash_size_reg = 0x1fff7a22, /* As in RM0033 Rev 5*/
        .flash_pagesize = 0x20000,
        .sram_size = 0x20000,
    },
#endif
#if defined(STM32F1)

    {
        // PM0063
        .chip_id = STLINK_CHIPID_STM32_F1_LOW,
#if defined(DRV_DEBUG)
        .description = "F1 Low-density device",
#endif
        .flash_size_reg = 0x1ffff7e0,
        .flash_pagesize = 0x400,
        .sram_size = 0x2800,
    },
#endif
#if defined(STM32F4)

    {
        .chip_id = STLINK_CHIPID_STM32_F4,
#if defined(DRV_DEBUG)
        .description = "F4 device",
#endif
        .flash_size_reg = 0x1FFF7A22, /* As in rm0090 since Rev 2*/
        .flash_pagesize = 0x4000,
        .sram_size = 0x30000,
    },
#endif
#if defined(STM32F4)

    {
        .chip_id = STLINK_CHIPID_STM32_F4_DSI,
#if defined(DRV_DEBUG)
        .description = "F46x and F47x device",
#endif
        .flash_size_reg = 0x1FFF7A22, /* As in rm0090 since Rev 2*/
        .flash_pagesize = 0x4000,
        .sram_size = 0x40000,
    },
#endif
#if defined(STM32F4)

    {
        .chip_id = STLINK_CHIPID_STM32_F4_HD,
#if defined(DRV_DEBUG)
        .description = "F42x and F43x device",
#endif
        .flash_size_reg = 0x1FFF7A22, /* As in rm0090 since Rev 2*/
        .flash_pagesize = 0x4000,
        .sram_size = 0x40000,
    },
#endif
#if defined(STM32F4)

    {
        .chip_id = STLINK_CHIPID_STM32_F4_LP,
#if defined(DRV_DEBUG)
        .description = "F4 device (low power)",
#endif
        .flash_size_reg = 0x1FFF7A22,
        .flash_pagesize = 0x4000,
        .sram_size = 0x10000,
    },
#endif
#if defined(STM32F4)

    {
        .chip_id = STLINK_CHIPID_STM32_F411RE,
#if defined(DRV_DEBUG)
        .description = "F4 device (low power) - stm32f411re",
#endif
        .flash_size_reg = 0x1FFF7A22,
        .flash_pagesize = 0x4000,
        .sram_size = 0x20000,
    },
#endif
#if defined(STM32F4)

    {
        .chip_id = STLINK_CHIPID_STM32_F4_DE,
#if defined(DRV_DEBUG)
        .description = "F4 device (Dynamic Efficency)",
#endif
        .flash_size_reg = 0x1FFF7A22,
        .flash_pagesize = 0x4000,
        .sram_size = 0x18000,
    },
#endif
#if defined(STM32F1)

    {
        .chip_id = STLINK_CHIPID_STM32_F1_HIGH,
#if defined(DRV_DEBUG)
        .description = "F1 High-density device",
#endif
        .flash_size_reg = 0x1ffff7e0,
        .flash_pagesize = 0x800,
        .sram_size = 0x10000,
    },
#endif
#if defined(STM32L1)

    {
        // This ignores the EEPROM! (and uses the page erase size,
        // not the sector write protection...)
        .chip_id = STLINK_CHIPID_STM32_L1_MEDIUM,
#if defined(DRV_DEBUG)
        .description = "L1 Med-density device",
#endif
        .flash_size_reg = 0x1ff8004c,
        .flash_pagesize = 0x100,
        .sram_size = 0x4000,
    },
#endif
#if defined(STM32L1)

    {
        .chip_id = STLINK_CHIPID_STM32_L1_CAT2,
#if defined(DRV_DEBUG)
        .description = "L1 Cat.2 device",
#endif
        .flash_size_reg = 0x1ff8004c,
        .flash_pagesize = 0x100,
        .sram_size = 0x8000,
    },
#endif
#if defined(STM32L1)

    {
        .chip_id = STLINK_CHIPID_STM32_L1_MEDIUM_PLUS,
#if defined(DRV_DEBUG)
        .description = "L1 Medium-Plus-density device",
#endif
        .flash_size_reg = 0x1ff800cc,
        .flash_pagesize = 0x100,
        .sram_size = 0x8000, /*Not completely clear if there are some with 48K*/
    },
#endif
#if defined(STM32L1)

    {
        .chip_id = STLINK_CHIPID_STM32_L1_HIGH,
#if defined(DRV_DEBUG)
        .description = "L1 High-density device",
#endif
        .flash_size_reg = 0x1ff800cc,
        .flash_pagesize = 0x100,
        .sram_size = 0xC000, /*Not completely clear if there are some with 32K*/
    },
#endif
#if defined(STM32L1)

    {
        .chip_id = STLINK_CHIPID_STM32_L152_RE,
#if defined(DRV_DEBUG)
        .description = "L152RE",
#endif
        .flash_size_reg = 0x1ff800cc,
        .flash_pagesize = 0x100,
        .sram_size = 0x14000, /*Not completely clear if there are some with 32K*/
    },
#endif
#if defined(STM32F1)

    {
        .chip_id = STLINK_CHIPID_STM32_F1_CONN,
#if defined(DRV_DEBUG)
        .description = "F1 Connectivity line device",
#endif
        .flash_size_reg = 0x1ffff7e0,
        .flash_pagesize = 0x800,
        .sram_size = 0x10000,
    },
#endif
#if defined(STM32F1)

    {
        //Low and Medium density VL have same chipid. RM0041 25.6.1
        .chip_id = STLINK_CHIPID_STM32_F1_VL_MEDIUM_LOW,
#if defined(DRV_DEBUG)
        .description = "F1 Medium/Low-density Value Line device",
#endif
        .flash_size_reg = 0x1ffff7e0,
        .flash_pagesize = 0x400,
        .sram_size = 0x2000, //0x1000 for low density devices
    },
#endif
#if defined(STM32F4)

    {
        // STM32F446x family. Support based on DM00135183.pdf (RM0390) document.
        .chip_id = STLINK_CHIPID_STM32_F446,
#if defined(DRV_DEBUG)
        .description = "F446 device",
#endif
        .flash_size_reg = 0x1fff7a22,
        .flash_pagesize = 0x20000,
        .sram_size = 0x20000,
    },
#endif
#if defined(STM32F4)

    {
        // STM32F410 MCUs. Support based on DM00180366.pdf (RM0401) document.
        .chip_id = STLINK_CHIPID_STM32_F410,
#if defined(DRV_DEBUG)
        .description = "F410 device",
#endif
        .flash_size_reg = 0x1fff7a22,
        .flash_pagesize = 0x4000,
        .sram_size = 0x8000,
    },
#endif
#if defined(STM32F3)

    {
        // This is STK32F303VCT6 device from STM32 F3 Discovery board.
        // Support based on DM00043574.pdf (RM0316) document.
        .chip_id = STLINK_CHIPID_STM32_F3,
#if defined(DRV_DEBUG)
        .description = "F3 device",
#endif
        .flash_size_reg = 0x1ffff7cc,
        .flash_pagesize = 0x800,
        .sram_size = 0xa000,
    },
#endif
#if defined(STM32F3)

    {
        // This is STK32F373VCT6 device from STM32 F373 eval board
        // Support based on 303 above (37x and 30x have same memory map)
        .chip_id = STLINK_CHIPID_STM32_F37x,
#if defined(DRV_DEBUG)
        .description = "F3 device",
#endif
        .flash_size_reg = 0x1ffff7cc,
        .flash_pagesize = 0x800,
        .sram_size = 0xa000,
    },
#endif
#if defined(STM32F1)

    {
        .chip_id = STLINK_CHIPID_STM32_F1_VL_HIGH,
#if defined(DRV_DEBUG)
        .description = "F1 High-density value line device",
#endif
        .flash_size_reg = 0x1ffff7e0,
        .flash_pagesize = 0x800,
        .sram_size = 0x8000,
    },
#endif
#if defined(STM32F1)

    {
        .chip_id = STLINK_CHIPID_STM32_F1_XL,
#if defined(DRV_DEBUG)
        .description = "F1 XL-density device",
#endif
        .flash_size_reg = 0x1ffff7e0,
        .flash_pagesize = 0x800,
        .sram_size = 0x18000,
    },
#endif
#if defined(STM32F0)

    {
        //Use this as an example for mapping future chips:
        //RM0091 document was used to find these paramaters
        .chip_id = STLINK_CHIPID_STM32_F0_CAN,
#if defined(DRV_DEBUG)
        .description = "F07x device",
#endif
        .flash_size_reg = 0x1ffff7cc, // "Flash size data register" (pg735)
        .flash_pagesize = 0x800,      // Page sizes listed in Table 4
        .sram_size = 0x4000,          // "SRAM" byte size in hex from Table 2
    },
#endif
#if defined(STM32F0)

    {
        //Use this as an example for mapping future chips:
        //RM0091 document was used to find these paramaters
        .chip_id = STLINK_CHIPID_STM32_F0,
#if defined(DRV_DEBUG)
        .description = "F0 device",
#endif
        .flash_size_reg = 0x1ffff7cc, // "Flash size data register" (pg735)
        .flash_pagesize = 0x400,      // Page sizes listed in Table 4
        .sram_size = 0x2000,          // "SRAM" byte size in hex from Table 2
    },
#endif
#if defined(STM32F4)

    {
        // RM0402 document was used to find these parameters
        // Table 4.
        .chip_id = STLINK_CHIPID_STM32_F412,
#if defined(DRV_DEBUG)
        .description = "F4 device",
#endif
        .flash_size_reg = 0x1FFF7A22, // "Flash size data register" (pg1135)
        .flash_pagesize = 0x4000,     // Table 5. Flash module organization ?
        .sram_size = 0x40000,         // "SRAM" byte size in hex from Table 4
    },
#endif
#if defined(STM32F4)

    {
        // RM0430 DocID029473 Rev 2 document was used to find these parameters
        // Figure 2, Table 4, Table 5, Section 35.2
        .chip_id = STLINK_CHIPID_STM32_F413,
#if defined(DRV_DEBUG)
        .description = "F4 device",
#endif
        .flash_size_reg = 0x1FFF7A22, // "Flash size data register" Section 35.2
        .flash_pagesize = 0x4000,     // Table 5. Flash module organization (variable sector sizes, but 0x4000 is smallest)
        .sram_size = 0x50000,         // "SRAM" byte size in hex from Figure 2 (Table 4 only says 0x40000)
    },
#endif
#if defined(STM32F0)

    {
        .chip_id = STLINK_CHIPID_STM32_F09X,
#if defined(DRV_DEBUG)
        .description = "F09X device",
#endif
        .flash_size_reg = 0x1ffff7cc, // "Flash size data register" (pg735)
        .flash_pagesize = 0x800,      // Page sizes listed in Table 4 (pg 56)
        .sram_size = 0x8000,          // "SRAM" byte size in hex from Table 2 (pg 50)
    },
#endif
#if defined(STM32F0)

    {
        //Use this as an example for mapping future chips:
        //RM0091 document was used to find these paramaters
        .chip_id = STLINK_CHIPID_STM32_F04,
#if defined(DRV_DEBUG)
        .description = "F04x device",
#endif
        .flash_size_reg = 0x1ffff7cc, // "Flash size data register" (pg735)
        .flash_pagesize = 0x400,      // Page sizes listed in Table 4
        .sram_size = 0x1800,          // "SRAM" byte size in hex from Table 2
    },
#endif
#if defined(STM32F0)

    {
        //Use this as an example for mapping future chips:
        //RM0091 document was used to find these paramaters
        .chip_id = STLINK_CHIPID_STM32_F0_SMALL,
#if defined(DRV_DEBUG)
        .description = "F0 small device",
#endif
        .flash_size_reg = 0x1ffff7cc, // "Flash size data register" (pg735)
        .flash_pagesize = 0x400,      // Page sizes listed in Table 4
        .sram_size = 0x1000,          // "SRAM" byte size in hex from Table 2
    },
#endif
#if defined(STM32F3)

    {
        // STM32F30x
        .chip_id = STLINK_CHIPID_STM32_F3_SMALL,
#if defined(DRV_DEBUG)
        .description = "F3 small device",
#endif
        .flash_size_reg = 0x1ffff7cc,
        .flash_pagesize = 0x800,
        .sram_size = 0xa000,
    },
#endif
#if defined(STM32L0)

    {
        // STM32L0x
        // RM0367,RM0377 documents was used to find these parameters
        .chip_id = STLINK_CHIPID_STM32_L0,
#if defined(DRV_DEBUG)
        .description = "L0x3 device",
#endif
        .flash_size_reg = 0x1ff8007c,
        .flash_pagesize = 0x80,
        .sram_size = 0x2000,
    },
#endif
#if defined(STM32L0)

    {
        // STM32L0x Category 5
        // RM0367,RM0377 documents was used to find these parameters
        .chip_id = STLINK_CHIPID_STM32_L0_CAT5,
#if defined(DRV_DEBUG)
        .description = "L0x Category 5 device",
#endif
        .flash_size_reg = 0x1ff8007c,
        .flash_pagesize = 0x80,
        .sram_size = 0x5000,
    },
#endif
#if defined(STM32L0)

    {
        // STM32L0x Category 2
        // RM0367,RM0377 documents was used to find these parameters
        .chip_id = STLINK_CHIPID_STM32_L0_CAT2,
#if defined(DRV_DEBUG)
        .description = "L0x Category 2 device",
#endif
        .flash_size_reg = 0x1ff8007c,
        .flash_pagesize = 0x80,
        .sram_size = 0x2000,
    },
#endif
#if defined(STM32F3)

    {
        // STM32F334, STM32F303x6/8, and STM32F328
        // From RM0364 and RM0316
        .chip_id = STLINK_CHIPID_STM32_F334,
#if defined(DRV_DEBUG)
        .description = "F3xx medium density device", // (RM0316 sec 33.6.1)
#endif
        .flash_size_reg = 0x1ffff7cc,
        .flash_pagesize = 0x800,
        .sram_size = 0x3000,
    },
#endif
#if defined(STM32F3)

    {
        // This is STK32F303RET6 device from STM32 F3 Nucelo board.
        // Support based on DM00043574.pdf (RM0316) document rev 5.
        .chip_id = STLINK_CHIPID_STM32_F303_HIGH,
#if defined(DRV_DEBUG)
        .description = "F303 high density device",
#endif
        .flash_size_reg = 0x1ffff7cc, // 34.2.1 Flash size data register
        .flash_pagesize = 0x800,      // 4.2.1 Flash memory organization
        .sram_size = 0x10000,         // 3.3 Embedded SRAM
    },
#endif
#if defined(STM32L4)

    {
        // STM32L4x6
        // From RM0351.
        .chip_id = STLINK_CHIPID_STM32_L4,
#if defined(DRV_DEBUG)
        .description = "L4 device",
#endif
        .flash_size_reg = 0x1FFF75e0, // "Flash size data register" (sec 45.2, page 1671)
        .flash_pagesize = 0x800,      // 2K (sec 3.2, page 78; also appears in sec 3.3.1 and tables 4-6 on pages 79-81)
        // SRAM1 is "up to" 96k in the standard Cortex-M memory map;
        // SRAM2 is 32k mapped at at 0x10000000 (sec 2.3, page 73 for
        // sizes; table 2, page 74 for SRAM2 location)
        .sram_size = 0x18000,
    },
#endif
#if defined(STM32L4)

    {
        // STM32L4RX
        // From DM00310109.pdf
        .chip_id = STLINK_CHIPID_STM32_L4RX,
#if defined(DRV_DEBUG)
        .description = "L4Rx device",
#endif
        .flash_size_reg = 0x1fff75e0, // "Flash size data register" (sec 52.2, page 2049)
        .flash_pagesize = 0x1000,     // 4k, section 3.3, pg 97
        .sram_size = 0xa0000,         // 192k (SRAM1) + 64k SRAM2 + 384k SRAM3 = 640k, or 0xA0000
    },
#endif
#if defined(STM32L4)

    {
        // STLINK_CHIPID_STM32_L41X
        // From RM0394 Rev 4 and DS12469 Rev 5
        .chip_id = STLINK_CHIPID_STM32_L41X,
#if defined(DRV_DEBUG)
        .description = "L41x device",
#endif
        .flash_size_reg = 0x1fff75e0, // "Flash size data register" (RM0394, sec 47.2, page 1586)
        .flash_pagesize = 0x800,      // 2K (DS12469, sec 3.4, page 17)
        // SRAM1 is 32k at 0x20000000
        // SRAM2 is 8k at 0x10000000 and 0x20008000 (DS12469, sec 3.5, page 18)
        .sram_size = 0xa000, // 40K (DS12469, sec 3.5, page 18)
    },
#endif
#if defined(STM32L4)

    {
        // STLINK_CHIPID_STM32_L43X
        // From RM0392.
        .chip_id = STLINK_CHIPID_STM32_L43X,
#if defined(DRV_DEBUG)
        .description = "L43x/L44x device",
#endif
        .flash_size_reg = 0x1fff75e0, // "Flash size data register" (sec 43.2, page 1410)
        .flash_pagesize = 0x800,      // 2K (sec 3.2, page 74; also appears in sec 3.3.1 and tables 7-8 on pages 75-76)
        // SRAM1 is "up to" 64k in the standard Cortex-M memory map;
        // SRAM2 is 16k mapped at 0x10000000 (sec 2.3, page 73 for
        // sizes; table 2, page 74 for SRAM2 location)
        .sram_size = 0xc000,
    },
#endif
#if defined(STM32L4)

    {
        // STLINK_CHIPID_STM32_L496X
        // Support based on en.DM00083560.pdf (RM0351) document rev 5.
        .chip_id = STLINK_CHIPID_STM32_L496X,
#if defined(DRV_DEBUG)
        .description = "L496x/L4A6x device",
#endif
        .flash_size_reg = 0x1fff75e0, // "Flash size data register" (sec 49.2, page 1809)
        .flash_pagesize = 0x800,      // Page erase (2 Kbyte) (sec 3.2, page 93)
        // SRAM1 is 256k at 0x20000000
        // SRAM2 is 64k at 0x20040000 (sec 2.2.1, fig 2, page 74)
        .sram_size = 0x40000, // Embedded SRAM (sec 2.4, page 84)
    },
#endif
#if defined(STM32L4)

    {
        // STLINK_CHIPID_STM32_L46X
        // From RM0394 (updated version of RM0392?).
        .chip_id = STLINK_CHIPID_STM32_L46X,
#if defined(DRV_DEBUG)
        .description = "L45x/46x device",
#endif
        .flash_size_reg = 0x1fff75e0, // "Flash size data register" (sec 45.2, page 1463)
        .flash_pagesize = 0x800,      // 2K (sec 3.2, page 73; also appears in sec 3.3.1 and tables 7 on pages 73-74)
        // SRAM1 is 128k at 0x20000000;
        // SRAM2 is 32k mapped at 0x10000000 (sec 2.4.2, table 3-4, page 68, also fig 2 on page 63)
        .sram_size = 0x20000,
    },
#endif
#if defined(STM32L0)

    {
        // STM32L011
        .chip_id = STLINK_CHIPID_STM32_L011,
#if defined(DRV_DEBUG)
        .description = "L011 device",
#endif
        .flash_size_reg = 0x1ff8007c,
        .flash_pagesize = 0x80,
        .sram_size = 0x2000,
    },
#endif
#if defined(STM32G0)

    {
        // STM32G071/081 (from RM0444)
        .chip_id = STLINK_CHIPID_STM32_G0X1,
#if defined(DRV_DEBUG)
        .description = "G071/G081 device",
#endif
        .flash_size_reg = 0x1FFF75E0, // Section 38.2
        .flash_pagesize = 0x800,      // 2K (sec 3.2)
        .sram_size = 0x9000,          // 36K (sec 2.3)
    },
#endif
#if defined(STM32WB)

    {
        // STM32WB55 (from RM0434)
        .chip_id = STLINK_CHIPID_STM32_WB55,
#if defined(DRV_DEBUG)
        .description = "WB55 device",
#endif
        .flash_size_reg = 0x1FFF75E0,
        .flash_pagesize = 0x1000, // 4K
        .sram_size = 0x40000,
    },
#endif

    {
        // unknown
        .chip_id = STLINK_CHIPID_UNKNOWN,
#if defined(DRV_DEBUG)
        .description = "unknown device",
#endif
        .flash_size_reg = 0x0,
        .flash_pagesize = 0x0,
        .sram_size = 0x0,
    },
};

#define STLINK_ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
const struct stlink_chipid_params *stlink_chipid_get_params(uint32_t chipid)
{
    const struct stlink_chipid_params *params = NULL;

    for (size_t n = 0; n < STLINK_ARRAY_SIZE(devices); n++)
    {
        if (devices[n].chip_id == chipid)
        {
            params = &devices[n];
            break;
        }
    }

    return params;
}

#endif //RT_USING_CHIPID
