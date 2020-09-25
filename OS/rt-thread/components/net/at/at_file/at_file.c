#include <rtthread.h>

#if defined (AT_USING_FILE)

#define LOG_TAG "at.f"

#include "at.h"
#include "at_device.h"
#include "at_file.h"
#include "at_log.h"

static struct at_file file = {0};

int at_file_init(struct at_file_ops *ops, struct at_device *device)
{
    char name[8] = {0};
    int rc;

    if(file.is_init == 1)
    {
        return RT_EOK;
    }
    
    file.device = device;
    file.ops = ops;

    /* create AT device socket event */
    rt_snprintf(name, RT_NAME_MAX, "f_evt");
    if ((file.urc_event = rt_event_create(name, RT_IPC_FLAG_FIFO)) == RT_NULL)
    {
        LOG_E("no memory for AT urc event create.");
        rc = -RT_ERROR;
        goto __exit;
    }
    rc = RT_EOK;
    file.is_init = 1;
__exit:
    return rc;
}

int at_file_deinit(void)
{
    rt_event_delete(file.urc_event);
    file.is_init = 0;
    return RT_EOK;
}

int at_file_open(char *name, int mode)
{
    int rc = -RT_ERROR;

    rc = file.ops->open(&file, name, mode);
    return rc;
}

int at_file_read(int handle, uint8_t *buf, int nbytes)
{
    int rc = -RT_ERROR;

    rc = file.ops->read(&file, handle, buf, nbytes);
    return rc;
}

int at_file_write(int handle, uint8_t *buf, int nbytes)
{
    int rc = -RT_ERROR;

    rc = file.ops->write(&file, handle, buf, nbytes);
    return rc;
}

int at_file_seek(int handle, int offset, int position)
{
    int rc = -RT_ERROR;

    rc = file.ops->seek(&file, handle, offset, position);
    return rc;
}

int at_file_position(int handle)
{
    int rc = -RT_ERROR;

    rc = file.ops->position(&file, handle);
    return rc;
}

int at_file_close(int handle)
{
    int rc = -RT_ERROR;

    rc = file.ops->close(&file, handle);
    return rc;
}

int at_file_delete(char *name)
{
    int rc = -RT_ERROR;

    rc = file.ops->delete(&file, name);
    return rc;
}

int at_file_upload(char *name, uint8_t *buf, int nbytes)
{
    int rc = -RT_ERROR;

    rc = file.ops->upload(&file, name, buf, nbytes);
    return rc;
}

struct at_file *at_file_get_ctx(int handle)
{
    return &file;
}

#endif
