/**
 * @file app_console.c
 * @author Segway Insight 
 * @brief 
 * @version 0.1
 * @date 2019-11-15
 * 
 * @copyright Copyright (c) 2019 纳恩博（北京）科技有限公司
 * All rights reserved.
 * 
 */

#include "board.h"
#include "SEGGER_RTT.h"

/**
 * @brief rt_kprintf 重定向输出
 * 
 * @param str 
 */
void rt_hw_console_output(const char *str)
{
    /* jlink rtt 输出 */
    SEGGER_RTT_WriteString( 0, str );
}
