#ifndef AT_MQTT_H
#define AT_MQTT_H

#define AT_MQTT_CLIENTID_SIZE_MAX  128
#define AT_MQTT_USERNAME_SIZE_MAX  128
#define AT_MQTT_PASSWORD_SIZE_MAX  128
#define AT_MQTT_CLIENT_BUFFER_SIZE 1024
#define AT_MQTT_TOPIC_SIZE_MAX     64 //topic字符串缓冲区大小
#define AT_MQTT_PAYLOAD_SIZE_MAX   512 //payload大小,跟mqtt协议和模块的能力有关
#define AT_MQTT_RECV_SIZE_MAX      AT_MQTT_PAYLOAD_SIZE_MAX //receive大小
#define AT_MQTT_PUBLISH_SIZE_MAX   AT_MQTT_PAYLOAD_SIZE_MAX //Publish大小

#define MAX_MSG_ID      65535 /* according to the MQTT specification - do not change! */

#if !defined(AT_MQTT_MESSAGE_HANDLERS_MAX)
#define AT_MQTT_MESSAGE_HANDLERS_MAX        5 /* redefinable - how many subscriptions do you want? */
#endif


enum QoS { QOS0, QOS1, QOS2, SUBFAIL=0x80 };

typedef struct MQTTMessage
{
    enum QoS qos;
    unsigned char retained;
    unsigned char dup;
    unsigned short id;
    void *payload;
    size_t payloadlen;
} MQTTMessage;

typedef struct MessageData
{
    MQTTMessage* message;
    char* topicName;
} MessageData;

enum at_mqtt_state
{
    AT_MQTT_STATE_NONE,
    AT_MQTT_STATE_INIT,
    AT_MQTT_STATE_OPEN,
    AT_MQTT_STATE_CONNECT,
    AT_MQTT_STATE_DISCONNECT,
    AT_MQTT_STATE_CLOSED
};

struct at_mqtt;

struct at_mqtt_connect_data
{
	/** Version of MQTT to be used.  3 = 3.1 4 = 3.1.1
	  */
    unsigned char version;
    char clientID[AT_MQTT_CLIENTID_SIZE_MAX];
    unsigned short keepAliveInterval;
    unsigned char cleansession;
    unsigned char willFlag;
    char username[AT_MQTT_USERNAME_SIZE_MAX];
    char password[AT_MQTT_PASSWORD_SIZE_MAX];
    unsigned char pkt_timeout;    //The range is 1-60. The default value is 5. Unit: second
    unsigned char retry_times;    //Integer type. Retry times when packet delivery times out. The range is 0-10. The default value is 3.
    unsigned char timeout_notice; // 0 Not report timeout message when transmitting packet
                                  // 1 Report timeout message when transmitting packet
                                    
};


struct at_mqtt_ops
{
    int (*open)(struct at_mqtt *mqtt, char *ip, int32_t port);
    int (*close)(struct at_mqtt *mqtt);
    int (*connect)(struct at_mqtt *mqtt, struct at_mqtt_connect_data *options);
    int (*disconnect)(struct at_mqtt *mqtt);
    int (*publish)(struct at_mqtt *mqtt, const char *topicName, MQTTMessage *message);
    int (*subscribe)(struct at_mqtt *mqtt, const char *topicName, enum QoS qos);
    int (*unsubscribe)(struct at_mqtt *mqtt, const char *topicName);
};

struct at_mqtt_config
{
    char ping_outstanding;
    int isconnected;
};

typedef void (*mqtt_recv_cb_t)(int idx, uint16_t msgID, const char *topic, int payload_len, const uint8_t *payload);
typedef void (*mqtt_stat_cb_t)(int client_idx, uint8_t err_code);

typedef struct
{
   mqtt_recv_cb_t recv_cb;
   mqtt_stat_cb_t stat_cb;
   
} mqtt_client_cb_t;
struct at_mqtt
{
    int client_idx;

    void *device;
    enum at_mqtt_state state;
    const struct at_mqtt_ops *ops;
    
    struct at_mqtt_connect_data *connect_data;
    mqtt_client_cb_t *callback;
    struct rt_ringbuffer *recv_ring;

    rt_event_t mqtt_event;                       /* AT device mqtt event */

    unsigned int next_msgid;

    int pdpcid;
#ifdef AT_MQTT_USING_TLS
    int sslctx_idx;
#endif
    int is_init;
    /* user-specific data */
    void *user_data;
};

int at_mqtt_init(struct at_mqtt_ops *ops);
int at_mqtt_deinit(int client_idx);
int at_mqtt_open(int client_idx, char *ip, int32_t port);
int at_mqtt_close(int client_idx);
int at_mqtt_connect(int client_idx, struct at_mqtt_connect_data *options);
int at_mqtt_disconnect(int client_idx);
int at_mqtt_publish(int client_idx, const char* topicName, MQTTMessage* message);
int at_mqtt_subscribe(int client_idx, const char *topicName, enum QoS qos);
int at_mqtt_unsubscribe(int client_idx, const char *topicName);
int at_mqtt_set_connect_data(int client_idx, struct at_mqtt_connect_data *connect_data);
int at_mqtt_set_callback(int client_idx, mqtt_client_cb_t *callback);
struct at_mqtt *at_mqtt_get_ctx_by_id(int idx);
enum at_mqtt_state at_mqtt_get_state(int client_idx);
int at_mqtt_set_state(int client_idx, enum at_mqtt_state state);





#endif
