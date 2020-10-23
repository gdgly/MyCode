/*
 * Copyright 2019 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "safety_config.h"

/*******************************************************************************
* Prototypes
******************************************************************************/
void start(void);
extern void common_startup(void);
extern int main(void);
extern void WatchdogEnable(void);  
extern void WatchdogDisable(void); 

/*******************************************************************************
* Code
******************************************************************************/
/*!
* @brief Device Start
*
* @param void
*
* @return None
*
* This function sets up watchdog, calls all of the needed starup routines and then
* branches to the main process.
*/
void start(void)
{
    /* Update of watchdog configuration */
#if WATCHDOG_ENABLED
    WatchdogEnable();
#else
    WatchdogDisable();
#endif

    /* Copy any vector or data sections that need to be in RAM */
    common_startup();

    /* Jump to main process */
    main();

    /* No actions to perform after this so wait forever */
    while(1);
}
