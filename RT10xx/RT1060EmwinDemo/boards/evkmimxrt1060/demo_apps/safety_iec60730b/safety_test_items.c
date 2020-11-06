/*
 * Copyright 2019 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "safety_config.h"

#if defined(__IAR_SYSTEMS_ICC__)
    #pragma location =  ".safety_ram"
#endif

#define MUX_ADDR(arg1) MUX_ADDR_(arg1) /* wrapper */
#define MUX_ADDR_(arg1, arg2, arg3, arg4, arg5) arg1 /* get 1st value from macro */
#define PAD_ADDR(arg1) PAD_ADDR_(arg1) /* wrapper */
#define PAD_ADDR_(arg1, arg2, arg3, arg4, arg5) arg5 /* get 5th value from macro */

/*******************************************************************************
*                                                                              *
*                           STRUCTURE FOR DIO Initialization and TEST          *
*                                                                              *
*******************************************************************************/
dio_test_rt_t dio_safety_test_item_0 =
{
  .gpio   = GPIO1_BASE,
  .pinNum = 2,
  .pinDir = PIN_DIRECTION_IN,
  .muxAddr = MUX_ADDR(IOMUXC_GPIO_AD_B0_02_GPIO1_IO02),
  .padAddr = PAD_ADDR(IOMUXC_GPIO_AD_B0_02_GPIO1_IO02),
};

dio_test_rt_t dio_safety_test_item_1 =
{
  .gpio   = GPIO3_BASE,
  .pinNum = 13,
  .pinDir = PIN_DIRECTION_IN,
  .muxAddr = MUX_ADDR(IOMUXC_GPIO_SD_B0_01_GPIO3_IO13),
  .padAddr = PAD_ADDR(IOMUXC_GPIO_SD_B0_01_GPIO3_IO13),
};
 
/* NULL terminated array of pointers to dio_test_t items for safety DIO test */
dio_test_rt_t *dio_safety_test_items[] = { &dio_safety_test_item_0, &dio_safety_test_item_1, NULL };