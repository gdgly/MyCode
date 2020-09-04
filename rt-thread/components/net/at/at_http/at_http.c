#include <rtthread.h>

#if defined (AT_USING_HTTP)

#define LOG_TAG "at.ht"

#include "at.h"
#include "at_device.h"
#include "at_http.h"
#include "at_log.h"

#include "netdev.h"

static struct at_http http_client = {0};


static int get_pdpcid(void)
{
    return AT_HTTP_PDPCID;
}

#if defined (AT_HTTP_USING_TLS)
static int get_sslctx_idx(void)
{
    return AT_HTTP_SSLCTX_IDX;
}
#endif

int at_http_init(struct at_http_ops *ops)
{
    extern struct netdev *netdev_default;
    struct netdev *netdev = RT_NULL;
    struct at_device *device = RT_NULL;

    if (netdev_default && netdev_is_up(netdev_default))
    {
        netdev = netdev_default;
    }
    else
    {
        return RT_NULL;
    }

    device = at_device_get_by_name(AT_DEVICE_NAMETYPE_NETDEV, netdev->name);
    if (device == RT_NULL)
    {
        return RT_NULL;
    }

    char name[RT_NAME_MAX] = {0};
    struct at_http *http = &http_client;
    
    http->device = device;
    http->ops = ops;
    http->pdpcid = get_pdpcid();
#if defined(AT_HTTP_USING_TLS)
    http->sslctx_idx = get_sslctx_idx();
#endif

    /* create AT device socket event */
    rt_snprintf(name, RT_NAME_MAX, "ht_evt");
    if ((http->http_event = rt_event_create(name, RT_IPC_FLAG_FIFO)) == RT_NULL)
    {
        LOG_E("no memory for AT http event create.");
        goto __err;
    }

    http->state = AT_HTTP_CLIENT_STATE_INIT;
    http->is_init = 1;

    return RT_EOK;

__err:
    http->state = AT_HTTP_CLIENT_STATE_NONE;
    http->is_init = 0;
    return -RT_ERROR;
}

int at_http_deinit(void)
{
    rt_event_delete(http_client.http_event);
    http_client.state = AT_HTTP_CLIENT_STATE_NONE;
    http_client.is_init = 0;
    
    return RT_EOK;
}

int at_http_open_connection(struct at_httpcfg *options)
{
    int rc = -RT_ERROR;

    rc = http_client.ops->open_connection(&http_client, options);
    if (rc >= 0)
    {
        http_client.state = AT_HTTP_CLIENT_STATE_OPEN;
    }

    return rc;
}

int at_http_establish_connection(char *url, int url_len, int timeout_s)
{
    int rc = -RT_ERROR;

    rc = http_client.ops->establish_connection(&http_client, url, url_len, timeout_s);
    if (rc >= 0)
    {
        http_client.state = AT_HTTP_CLIENT_STATE_CONNECTED;
    }
    return rc;
}

int at_http_get(int timeout_s)
{
    int rc = -RT_ERROR;

    rc = http_client.ops->get(&http_client, timeout_s);
  
    return rc;
}

int at_http_stop(void)
{
    int rc = -RT_ERROR;

    rc = http_client.ops->stop(&http_client);
    if(rc >= 0)
    {
        http_client.state = AT_HTTP_CLIENT_STATE_INIT;
    }
    return rc;
}

int at_http_readfile(char *path, int timeout_s)
{
    int rc = -RT_ERROR;

    rc = http_client.ops->readfile(&http_client, path, timeout_s);
    
    return rc;
}

int at_http_get_body_len(void)
{
    return http_client.resp.content_length;
}

int at_http_get_body_pos()
{
    return 0;
}

struct at_http *at_http_get_ctx(void)
{
    return &http_client;
}

enum at_http_state at_http_get_state(void)
{
    return http_client.state;
}

int at_http_set_state(enum at_http_state state)
{
    http_client.state = state;
    return RT_EOK;
}

#endif
