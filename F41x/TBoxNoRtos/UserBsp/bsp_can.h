
#ifndef __BSP_CAN_H
#define __BSP_CAN_H
#include "main.h"

#include "can.h"


#define CAN_FIFO_SIZE	(2*1024)
typedef struct
{
    uint8_t FifoBuf1[CAN_FIFO_SIZE];
	uint8_t FifoBuf2[CAN_FIFO_SIZE];


    uint8_t TxOk;
    uint8_t FpStep;
	uint8_t VehicleType;	//车辆类型(混动、增程、燃油)

} CAN_STA_TYPE;



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
extern CAN_STA_TYPE			gCanStaReg;	//can状态及fifo结构体

typedef enum
{
    SEND_OK,
    TIMEOUT,
    LEN_ERR,
	ACC_LOCK,
} CAN_TX_STA_E;


int hw_can_init(void);
CAN_TX_STA_E bsp_can_send(CAN_HandleTypeDef *hcan, uint32_t can_id, uint8_t *pData, uint16_t len);




void can_send_mix_or_extend(void);
void can_send_fuel(void);


#endif


