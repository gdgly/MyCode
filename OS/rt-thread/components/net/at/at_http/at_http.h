#ifndef AT_HTTP_H
#define AT_HTTP_H

#define AT_HTTP_URL_SIZE_MAX        256 //range is 1-2048

enum at_http_state
{
   AT_HTTP_CLIENT_STATE_NONE,
   AT_HTTP_CLIENT_STATE_INIT,
   AT_HTTP_CLIENT_STATE_OPEN,
   AT_HTTP_CLIENT_STATE_CONNECTED,
};

struct at_http;

struct at_httpcfg
{
    char responseheader;
};

// <err> Meaning
// 0     Operation successful
// 701   HTTP(S) unknown error
// 702   HTTP(S) timeout703 HTTP(S) busy
// 704   HTTP(S) UART busy
// 705   HTTP(S) no GET/POST requests
// 706   HTTP(S) network busy
// 707   HTTP(S) network open failed
// 708   HTTP(S) network no configuratio
// 709   HTTP(S) network deactivated
// 710   HTTP(S) network error
// 711   HTTP(S) URL error
// 712   HTTP(S) empty URL713 HTTP(S) IP address error
// 714   HTTP(S) DNS error
// 715   HTTP(S) socket create error
// 716   HTTP(S) socket connect error
// 717   HTTP(S) socket read error
// 718   HTTP(S) socket write error
// 719   HTTP(S) socket closed
// 720   HTTP(S) data encode error
// 721   HTTP(S) data decode error
// 722   HTTP(S) read timeout
// 723   HTTP(S) response failed
// 724   Incoming call busy
// 725   Voice call busy
// 726   Input timeout
// 727   Wait data timeout
// 728   Wait HTTP(S) response timeout
// 729   Memory allocation failed
// 730   Invalid parameter

// <httprspcode> Meaning
// 200      OK
// 403      Forbidden
// 404      Not found
// 409      Conflict
// 411      Length required
// 500      Internal server error
struct at_http_GET_response
{
    int err;
    int httprspcode;
    int content_length;
};

struct at_http_ops
{
    int (*open_connection)(struct at_http *http, struct at_httpcfg *options);
    int (*establish_connection)(struct at_http *http, char *url, int url_len, int timeout_s);
    int (*get)(struct at_http *http, int timeout_s);
    int (*stop)(struct at_http *http);
    int (*readfile)(struct at_http *http, char *path, int timeout_s);
};

// typedef void (*mqtt_recv_cb_t)(int idx, uint16_t msgID, const char *topic, int payload_len, const uint8_t *payload);
// typedef void (*mqtt_stat_cb_t)(int client_idx, uint8_t err_code);

// typedef struct
// {
//    mqtt_recv_cb_t recv_cb;
//    mqtt_stat_cb_t stat_cb;
   
// } mqtt_client_cb_t;

struct at_http
{
    void *device;
    enum at_http_state state;
    const struct at_http_ops *ops;
    
    int pdpcid;
#ifdef AT_HTTP_USING_TLS
    int sslctx_idx;
#endif
    // http_client_cb_t *callback;

    rt_event_t http_event;                       /* AT device mqtt event */
    struct at_http_GET_response resp;

    int is_init;
    /* user-specific data */
    void *user_data;
};

// int at_http_set_callback(int client_idx, http_client_cb_t *callback);
int at_http_init(struct at_http_ops *ops);
int at_http_deinit(void);
int at_http_open_connection(struct at_httpcfg *options);
int at_http_establish_connection(char *url, int url_len, int timeout_s);
int at_http_get(int timeout_s);
int at_http_stop(void);
int at_http_readfile(char *path, int timeout_s);
int at_http_get_body_len(void);
enum at_http_state at_http_get_state(void);
int at_http_set_state(enum at_http_state state);
struct at_http *at_http_get_ctx(void);

#endif
