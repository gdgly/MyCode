#include <rtthread.h>
#include "ringbuffer.h"

#ifdef AT_USING_MQTT

#define LOG_TAG "at.mqt"

#include "at.h"
#include "at_device.h"
#include "at_mqtt.h"
#include "at_log.h"

#include "netdev.h"

#define AT_MQTT_CLIENT_MAX      1
static struct at_mqtt mqtt_client_table[AT_MQTT_CLIENT_MAX] = {0};


static int get_pdpcid(void)
{
    return AT_MQTT_PDPCID;
}

static int get_sslctx_idx(void)
{
    return AT_MQTT_SSLCTX_IDX;
}

struct at_mqtt *at_mqtt_get_ctx_by_id(int idx)
{
    if(idx >= AT_CLIENT_NUM_MAX)
        return RT_NULL;
    if(mqtt_client_table[idx].is_init == 0)
        return RT_NULL;
    return &mqtt_client_table[idx];
}

int at_mqtt_init(struct at_mqtt_ops *ops)
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
    struct at_mqtt *mqtt = RT_NULL;
    for (int i = 0; i < AT_MQTT_CLIENT_MAX; i++)
    {
        if (mqtt_client_table[i].is_init == 0)
        {
            mqtt = &mqtt_client_table[i];
            mqtt->client_idx = i;
        }
    }
    mqtt->recv_ring = rt_ringbuffer_create(AT_MQTT_RECV_SIZE_MAX);
    mqtt->device = device;
    mqtt->ops = ops;
    mqtt->next_msgid = 1;
    mqtt->pdpcid = get_pdpcid();
    mqtt->sslctx_idx = get_sslctx_idx();

    /* create AT device socket event */
    rt_snprintf(name, RT_NAME_MAX, "at_evt%d", mqtt->client_idx);
    if ((mqtt->mqtt_event = rt_event_create(name, RT_IPC_FLAG_FIFO)) == RT_NULL)
    {
        LOG_E("no memory for AT mqtt(%s) mqtt event create.", mqtt->client_idx);
        goto __err;
    }

    mqtt->state = AT_MQTT_STATE_INIT;
    mqtt->is_init = 1;

    return mqtt->client_idx;

__err:
    mqtt->state = AT_MQTT_STATE_NONE;
    mqtt->is_init = 0;
    return -RT_ERROR;
}

int at_mqtt_deinit(int client_idx)
{
    struct at_mqtt *mqtt = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    mqtt = &mqtt_client_table[client_idx];
    rt_event_delete(mqtt->mqtt_event);
    mqtt->state = AT_MQTT_STATE_NONE;
    mqtt->is_init = 0;
    rt_ringbuffer_destroy(mqtt->recv_ring);
    
    return RT_EOK;
}

/**
 * @brief 
 * 
 * @param ip 
 * @param port 
 * @return int client_idx
 */
int at_mqtt_open(int client_idx, char *ip, int32_t port)
{
    struct at_mqtt *mqtt = RT_NULL;
    int rc = -RT_ERROR;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    mqtt = &mqtt_client_table[client_idx];
    rc = mqtt->ops->open(mqtt, ip, port);
    if (rc >= 0)
    {
        mqtt->state = AT_MQTT_STATE_OPEN;
    }

    return rc;
}

int at_mqtt_close(int client_idx)
{
    struct at_mqtt *mqtt = RT_NULL;
    int rc = -RT_ERROR;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    mqtt = &mqtt_client_table[client_idx];
    rc = mqtt->ops->close(mqtt);
    if (rc >= 0)
    {
        mqtt->state = AT_MQTT_STATE_CLOSED;
    }
    return rc;
}

int at_mqtt_connect(int client_idx, struct at_mqtt_connect_data *options)
{
    struct at_mqtt *mqtt = RT_NULL;
    int rc = -RT_ERROR;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    mqtt = &mqtt_client_table[client_idx];
    rc = mqtt->ops->connect(mqtt, options);
    if(rc >= 0)
    {
        mqtt->state = AT_MQTT_STATE_CONNECT;
    }
    return rc;
}

int at_mqtt_disconnect(int client_idx)
{
    struct at_mqtt *mqtt = RT_NULL;
    int rc = -RT_ERROR;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return rc;
    mqtt = &mqtt_client_table[client_idx];
    rc = mqtt->ops->disconnect(mqtt);
    if(rc >= 0)
    {
        mqtt->state = AT_MQTT_STATE_DISCONNECT;
    }
    return rc;
}

int at_mqtt_publish(int client_idx, const char* topicName, MQTTMessage* message)
{
    struct at_mqtt *mqtt = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    mqtt = &mqtt_client_table[client_idx];

    return mqtt->ops->publish(mqtt, topicName, message);
}

int at_mqtt_subscribe(int client_idx, const char *topicName, enum QoS qos)
{
    struct at_mqtt *mqtt = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    mqtt = &mqtt_client_table[client_idx];
    
    return mqtt->ops->subscribe(mqtt, topicName, qos);
}

int at_mqtt_unsubscribe(int client_idx, const char *topicName)
{
    struct at_mqtt *mqtt = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    mqtt = &mqtt_client_table[client_idx];
    
    return mqtt->ops->unsubscribe(mqtt, topicName);
}

int at_mqtt_set_connect_data(int client_idx, struct at_mqtt_connect_data *connect_data)
{
    struct at_mqtt *mqtt = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    mqtt = &mqtt_client_table[client_idx];
    
    mqtt->connect_data = connect_data;
    
    return 0;
}
int at_mqtt_set_callback(int client_idx, mqtt_client_cb_t *callback)
{
    struct at_mqtt *mqtt = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    mqtt = &mqtt_client_table[client_idx];
    
    mqtt->callback = callback;
    
    return 0;
}

enum at_mqtt_state at_mqtt_get_state(int client_idx)
{
    struct at_mqtt *mqtt = RT_NULL;

    mqtt = &mqtt_client_table[client_idx];
    return mqtt->state;
}

int at_mqtt_set_state(int client_idx, enum at_mqtt_state state)
{
    struct at_mqtt *mqtt = RT_NULL;

    if(client_idx >= AT_CLIENT_NUM_MAX)
        return -RT_ERROR;
    mqtt = &mqtt_client_table[client_idx];
    mqtt->state = state;
    return RT_EOK;
}

#endif
