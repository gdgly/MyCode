/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2019-10-30     RGW            the first version
 */
#include <board.h>
#include "drv_spi.h"
#include "spi_flash.h"

#define LOG_TAG "drv.spi_flash"
#include <drv_log.h>

#if defined(BSP_USING_SPI_FLASH)

#ifdef RT_USING_SFUD
#include "spi_flash_sfud.h"
#endif

#ifdef RT_USING_W25QXX
#include "spi_flash_w25qxx.h"
#endif

#if defined(RT_USING_SFUD) && defined(RT_USING_W25QXX)
#error "RT_USING_SFUD and RT_USING_W25QXX only need one"
#endif

#define SPI_BUS_NAME "spi2"
#define SPI_DEVICE_NAME "spi20"
#define SPI_FLASH_CHIP "W25QXX"

static rt_err_t rt_hw_spi_flash_attach(void)
{
    rt_err_t result;

    __HAL_RCC_GPIOB_CLK_ENABLE();
    result = rt_hw_spi_device_attach(SPI_BUS_NAME, SPI_DEVICE_NAME, GPIOB, GPIO_PIN_12);
    if (result != RT_EOK)
    {
        LOG_D("spi flash attach error, bus name: %s, device name: %s", SPI_BUS_NAME, SPI_DEVICE_NAME);
        return result;
    }

    return RT_EOK;
}

#ifdef RT_USING_SFUD
static int rt_hw_spi_flash_with_sfud_init(void)
{
    rt_err_t result;

    result = rt_hw_spi_flash_attach();
    if (result != RT_EOK)
    {
        return result;
    }
    if (RT_NULL == rt_sfud_flash_probe(SPI_FLASH_CHIP, SPI_DEVICE_NAME))
    {
        return RT_ERROR;
    }

    return RT_EOK;
}
INIT_DEVICE_EXPORT(rt_hw_spi_flash_with_sfud_init);
#endif

#ifdef RT_USING_W25QXX
int rt_hw_spi_flash_init(void)
{
    rt_err_t result;

    result = rt_hw_spi_flash_attach();
    if (result != RT_EOK)
    {
        return result;
    }
    return w25qxx_init(SPI_FLASH_CHIP, SPI_DEVICE_NAME);
}
INIT_DEVICE_EXPORT(rt_hw_spi_flash_init);
#endif

#endif //BSP_USING_SPI_FLASH
