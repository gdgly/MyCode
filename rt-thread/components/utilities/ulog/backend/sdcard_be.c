/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-09-04     armink       the first version
 */

#include <rthw.h>
#include <ulog.h>
#include "log_data.h"

#ifdef ULOG_BACKEND_USING_SDCARD

#if defined(ULOG_ASYNC_OUTPUT_BY_THREAD) && ULOG_ASYNC_OUTPUT_THREAD_STACK < 384
#error "The thread stack size must more than 384 when using async output by thread (ULOG_ASYNC_OUTPUT_BY_THREAD)"
#endif

static struct ulog_backend sdcard;

void ulog_sdcard_backend_output(struct ulog_backend *backend, rt_uint32_t level, const char *tag, rt_bool_t is_raw,
        const char *log, size_t len)
{
    log_data_put((char *)log, len);
}

int ulog_sdcard_backend_init(void)
{
    ulog_init();
    sdcard.output = ulog_sdcard_backend_output;

    ulog_backend_register(&sdcard, "sdcard", RT_FALSE);

    return 0;
}
INIT_PREV_EXPORT(ulog_sdcard_backend_init);

#endif /* ULOG_BACKEND_USING_SDCARD */
