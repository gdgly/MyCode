#ifndef __NINEBOT_PROTOCOL_H__
#define __NINEBOT_PROTOCOL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "config.h"



typedef void (*REC_FRAME_CB_T)();
typedef void (*SEND_FREAM_FUNC_T)(uint8_t *arg1, uint16_t arg2);

typedef enum
{
    PARSE_OK,
    PARSE_FAIL
} PARSE_RETURN;

typedef enum
{
    USE_SERIAL,
    USE_TCP
} SEND_RECV_TYPE;

typedef enum
{
    NOHEAD,
    GETHEAD,
    GETVERSION,
    GETLENHALF,
    GETLEN
} PARSE_DATA_STA;

typedef struct rx_frametruct
{
    uint8_t     Version;
    uint16_t    FrameDataLen;
    uint8_t     SourceID;
    uint8_t     TargetID;
    uint8_t     Cmd;
    uint16_t    DataIndex;
    uint8_t     *frame_data;
    SEND_FREAM_FUNC_T send_frame_fun;
    
} FRAME_TYPE;

typedef struct parse_struct
{
    PARSE_DATA_STA  sta;
    uint16_t        frame_cnt;      //一包的长度
    uint16_t        frame_data_len; //数据的长度
    uint16_t        frame_len;
    uint8_t         version;
    uint8_t         frame_buffer[FRAME_MAX];
    REC_FRAME_CB_T  rec_frame_cb;
    FRAME_TYPE   frame;
    

} NB_BUS_TYPE;

PARSE_RETURN creat_send_cmd(NB_BUS_TYPE *nb_bus_t, FRAME_TYPE *frame);
PARSE_RETURN parse_struct_init(NB_BUS_TYPE *nb_bus_t);

void parse_data(NB_BUS_TYPE *nb_bus_t, uint8_t *receive_buffer, uint16_t receive_len);
void rx_frameet_send_fun(FRAME_TYPE *frame, SEND_FREAM_FUNC_T send_frame_fun);

void parse_set_send_fun(NB_BUS_TYPE *nb_bus_t, SEND_FREAM_FUNC_T send_frame_fun);
void parse_set_rec_callback(NB_BUS_TYPE *nb_bus_t, REC_FRAME_CB_T rec_frame_cb);

#ifdef __cplusplus
}
#endif

#endif
