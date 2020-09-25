#ifndef AT_TCP_H
#define AT_TCP_H

#define AT_TCP_CLIENT_BUFFER_SIZE 1024
#define AT_TCP_PAYLOAD_SIZE_MAX   512 //payload大小,跟tcp协议和模块的能力有关,The maximum data length is 1460 bytes.
#define AT_TCP_RECV_SIZE_MAX AT_TCP_PAYLOAD_SIZE_MAX //receive大小
#define AT_TCP_SEND_SIZE_MAX AT_TCP_PAYLOAD_SIZE_MAX //Publish大小

#define MAX_MSG_ID      65535 /* according to the TCP specification - do not change! */

enum at_tcp_state
{
    AT_TCP_STATE_IDLE,
    AT_TCP_STATE_INIT,
    AT_TCP_STATE_OPENING,
    AT_TCP_STATE_CONNECTED,
    AT_TCP_STATE_CLOSING
};

struct at_tcp;

struct at_tcp_retranscfg
{
    int max_backoffs; //Integer type. The maximum number of TCP retransmission. The range is  3-20, and the default value is 12.
    int max_rto;      //Integer type. The maximum interval time of TCP retransmission. The range is 5-1000, and the default value is 600. Unit: 100ms.
};

struct at_tcp_cfg
{
    struct at_tcp_retranscfg retranscfg; //Set the maximum interval time and  number for TCP retransmission
    unsigned short qisend_timeout_ms;    //Set the input data timeout, The range is 0-3600, and the default is 0. Unit: ms.
    unsigned char passiveclosed;         //0 Disable the passive close of TCP connection when the server is closed.
                                         //1 Enable the passive close of TCP connection when the server is closed.
};


struct at_tcp_ops
{
    int (*open)(struct at_tcp *tcp, char *ip, int32_t port);
    int (*close)(struct at_tcp *tcp);
    int (*send)(struct at_tcp *tcp, uint8_t *data, int data_len);
};


typedef void (*tcp_recv_cb_t)(int idx, int data_len);
typedef void (*tcp_stat_cb_t)(int client_idx, int err_code);

typedef struct
{
   tcp_recv_cb_t recv_cb;
   tcp_stat_cb_t stat_cb;
} tcp_client_cb_t;

struct at_tcp
{
    int client_idx; //Integer type. The socket service index. The range is 0-11.

    void *device;
    enum at_tcp_state state;
    const struct at_tcp_ops *ops;
    struct at_tcp_cfg *cfg;

    tcp_client_cb_t *callback;
    struct rt_ringbuffer *recv_ring;

    rt_event_t tcp_event; //AT device tcp event

    int pdpcid; //Integer type. The context ID. The range is 1-16.
#ifdef AT_TCP_USING_TLS
    int sslctx_idx;
#endif
    int is_init;
    /* user-specific data */
    void *user_data;
};

int at_tcp_init(struct at_tcp_ops *ops);
int at_tcp_deinit(int client_idx);
int at_tcp_open(int client_idx, char *ip, int32_t port);
int at_tcp_close(int client_idx);
int at_tcp_send(int client_idx, uint8_t *data, int data_len);
int at_tcp_set_cfg(int client_idx, struct at_tcp_cfg *cfg);
int at_tcp_set_callback(int client_idx, tcp_client_cb_t *callback);
struct at_tcp *at_tcp_get_ctx_by_id(int idx);
enum at_tcp_state at_tcp_get_state(int client_idx);
int at_tcp_set_state(int client_idx, enum at_tcp_state state);



/************************************************
 * Summary of Error Codes
 * 
 * If an “ERROR” is returned after executing TCP/IP AT commands, the details of error can be queried via 
 * AT+QIGETERROR. Please note that AT+QIGETERROR just returns error code of the last TCP/IP AT
 * command.
 * **********************************************/
#define TCP_ERR_0          0   //Operation successful
#define TCP_ERR_550        550 //Unknown error
#define TCP_ERR_551        551 //Operation blocked
#define TCP_ERR_552        552 //Invalid parameters
#define TCP_ERR_553        553 //Memory not enough
#define TCP_ERR_554        554 //Create socket failed
#define TCP_ERR_555        555 //Operation not supported
#define TCP_ERR_556        556 //Socket bind failed
#define TCP_ERR_557        557 //Socket listen failed
#define TCP_ERR_558        558 //Socket write failed
#define TCP_ERR_559        559 //Socket read failed
#define TCP_ERR_560        560 //Socket accept failed
#define TCP_ERR_561        561 //Open PDP context failed
#define TCP_ERR_562        562 //Close PDP context failed
#define TCP_ERR_563        563 //Socket identity has been used
#define TCP_ERR_564        564 //DNS busy
#define TCP_ERR_565        565 //DNS parse failed
#define TCP_ERR_566        566 //Socket connect failed
#define TCP_ERR_567        567 //Socket has been closed
#define TCP_ERR_568        568 //Operation busy
#define TCP_ERR_569        569 //Operation timeout
#define TCP_ERR_570        570 //PDP context broken down
#define TCP_ERR_571        571 //Cancel send
#define TCP_ERR_572        572 //Operation not allowed
#define TCP_ERR_573        573 //APN not configured
#define TCP_ERR_574        574 //Port busy

#define TCP_CB_CODE_700    700 //Socket closed by remote peer or due to network error, status “closing”.
#define TCP_CB_CODE_701    701 //PDP context may be deactivated by the network. The module will report URC to the host about PDP 
                               //deactivation. The host must execute AT+QIDEACT to deactivate the context and reset all connections.

#endif
