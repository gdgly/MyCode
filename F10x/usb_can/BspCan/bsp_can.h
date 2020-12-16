
#ifndef __BSP_CAN_H
#define __BSP_CAN_H

#include "main.h"
#include "can.h"


//hal库老版本CAN接收结构体
typedef struct
{
    uint32_t StdId;
    uint32_t ExtId;
    uint32_t IDE;
    uint32_t RTR;
    uint32_t DLC;
    uint8_t Data[8];
    uint32_t Timestamp;
    uint32_t FilterMatchIndex;
} MyCanRxMsgTypeDef;

extern MyCanRxMsgTypeDef	gCanTempMsg;//can临时结构体
extern MyCanRxMsgTypeDef	gCanRxMsg;//can接收结构体


typedef enum
{
    SEND_OK,
	SEND_ERR,
    TIMEOUT,
    LEN_ERR,
	ACC_LOCK,
} CAN_TX_STA_E;


int hw_can_init(void);
CAN_TX_STA_E bsp_can_send(CAN_HandleTypeDef *hcan, uint32_t can_id, uint8_t *pData, uint16_t len);
void bsp_can_send_test(CAN_HandleTypeDef *hcan, uint32_t can_id, uint8_t *pData, uint16_t len);




#endif


