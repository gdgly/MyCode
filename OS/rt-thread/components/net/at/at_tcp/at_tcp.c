#include <rtthread.h>
#include "ringbuffer.h"

#define LOG_TAG "at.tcp"

#include "at.h"
#include "at_device.h"
#include "at_tcp.h"
#include "at_log.h"

#include "netdev.h"

static struct at_tcp tcp_client_table[AT_TCP_CLIENT_MAX] = {0};

static int get_pdpcid(void)
{
    return AT_TCP_PDPCID;
}

#if defined(AT_TCP_USING_TLS)
static int get_sslctx_idx(void)
{
    return AT_TCP_SSLCTX_IDX;
}
#endif

struct at_tcp *at_tcp_get_ctx_by_id(int idx)
{
    if(idx >= AT_CLIENT_NUM_MAX)
        return RT_NULL;
    if(tcp_client_table[idx].is_init == 0)
        return RT_NULL;
    return &tcp_client_table[idx];
}

int at_tcp_init(struct at_tcp_ops *ops)
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
    struct at_tcp *tcp = RT_NULL;
    for (int i = 0; i < AT_TCP_CLIENT_MAX; i++)
    {
        if (tcp_client_table[i].is_init == 0)
        {
            tcp = &tcp_client_table[i];
            tcp->client_idx = i;
        }
    }
    tcp->recv_ring = rt_ringbuffer_create(AT_TCP_RECV_SIZE_MAX);
    tcp->device = device;
    tcp->ops = ops;
    tcp->pdpcid = get_pdpcid();
#if defined(AT_TCP_USING_TLS)
    tcp->sslctx_idx = get_sslctx_idx();
#endif

    /* create AT device socket event */
    rt_snprintf(name, RT_NAME_MAX, "tcp_evt%d", tcp->client_idx);
    if ((tcp->tcp_event = rt_event_create(name, RT_IPC_FLAG_FIFO)) == RT_NULL)
    {
        LOG_E("no memory for AT tcp(%s) tcp event create.", tcp->client_idx);
        goto __err;
    }

    tcp->state = AT_TCP_STATE_INIT;
    tcp->is_init = 1;

    return tcp->client_idx;

__err:
    tcp->state = AT_TCP_STATE_IDLE;
    tcp->is_init = 0;
    return -RT_ERROR;
}

int at_tcp_deinit(int client_idx)
{
    struct at_tcp *tcp = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    tcp = &tcp_client_table[client_idx];
    rt_event_delete(tcp->tcp_event);
    tcp->state = AT_TCP_STATE_IDLE;
    tcp->is_init = 0;
    rt_ringbuffer_destroy(tcp->recv_ring);
    
    return RT_EOK;
}

/**
 * @brief 
 * 
 * @param ip 
 * @param port 
 * @return int client_idx
 */
int at_tcp_open(int client_idx, char *ip, int32_t port)
{
    struct at_tcp *tcp = RT_NULL;
    int rc = -RT_ERROR;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    tcp = &tcp_client_table[client_idx];
    tcp->state = AT_TCP_STATE_OPENING;
    rc = tcp->ops->open(tcp, ip, port);

    return rc;
}

int at_tcp_close(int client_idx)
{
    struct at_tcp *tcp = RT_NULL;
    int rc = -RT_ERROR;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    tcp = &tcp_client_table[client_idx];
    tcp->state = AT_TCP_STATE_CLOSING;
    rc = tcp->ops->close(tcp);
    
    return rc;
}

int at_tcp_send(int client_idx, uint8_t *data, int data_len)
{
    struct at_tcp *tcp = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    tcp = &tcp_client_table[client_idx];

    return tcp->ops->send(tcp, data, data_len);
}

int at_tcp_set_cfg(int client_idx, struct at_tcp_cfg *cfg)
{
    struct at_tcp *tcp = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    tcp = &tcp_client_table[client_idx];
    
    tcp->cfg = cfg;
    
    return 0;
}
int at_tcp_set_callback(int client_idx, tcp_client_cb_t *callback)
{
    struct at_tcp *tcp = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    tcp = &tcp_client_table[client_idx];
    
    tcp->callback = callback;
    
    return 0;
}

enum at_tcp_state at_tcp_get_state(int client_idx)
{
    struct at_tcp *tcp = RT_NULL;

    tcp = &tcp_client_table[client_idx];
    return tcp->state;
}

int at_tcp_set_state(int client_idx, enum at_tcp_state state)
{
    struct at_tcp *tcp = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    tcp = &tcp_client_table[client_idx];
    tcp->state = state;
    return RT_EOK;
}

