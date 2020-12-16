/*
* @Description: can上层(初始化发送 接收 解析 中断等)
 * @Author: your name
 * @Date: 2019-08-21 09:56:05
 * @LastEditTime: 2019-09-08 15:45:13
 * @LastEditors: Please set LastEditors
 */


#include "bsp_can.h"
#include "kfifo.h"


void bsp_can_filter_config(CAN_HandleTypeDef *hcan_x)
{
    CAN_FilterTypeDef Filter_Init;

    //can1
    if(hcan_x == &hcan)
    {
        Filter_Init.FilterIdHigh        = 0;
        Filter_Init.FilterIdLow			= 0;
        Filter_Init.FilterMaskIdHigh	= 0;
        Filter_Init.FilterMaskIdLow		= 0;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDMASK;
        Filter_Init.FilterScale = CAN_FILTERSCALE_32BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
        Filter_Init.FilterBank = 1;
        Filter_Init.SlaveStartFilterBank = 14;
        while (HAL_CAN_ConfigFilter(hcan_x, &Filter_Init) != HAL_OK);
    }

}



uint32_t can_send_cnt = 0;
uint32_t can_wait_cnt = 0;

//发送
CAN_TX_STA_E bsp_can_send(CAN_HandleTypeDef *hcan_x, uint32_t can_id, uint8_t *pData, uint16_t len)
{
    static uint8_t can1_err = 0;

    uint8_t temp_buf[8] = {0};
    uint32_t TxMailbox = CAN_TX_MAILBOX0;

    CAN_TxHeaderTypeDef can_tx_str;
    can_tx_str.StdId = can_id;
    can_tx_str.IDE = CAN_ID_STD;
    can_tx_str.RTR = CAN_RTR_DATA;
    can_tx_str.TransmitGlobalTime = DISABLE;


    if (len > 0 && len <= 8)
    {
        can_tx_str.DLC = len;
        memcpy(temp_buf, pData, len);
        
        if(hcan_x == &hcan)
        {
            can_wait_cnt = 0;
            while(HAL_CAN_GetTxMailboxesFreeLevel(hcan_x) == 0)
            {
                if(can1_err == 0)
                {
                    can_wait_cnt++;
                    if(can_wait_cnt > 10000)
                    {
                        can1_err = 1;
                        return SEND_ERR;
                    }
                }
                else if(can1_err == 1)
                {
                    return SEND_ERR;
                }
                
            }
            
            can_wait_cnt = 0;
            while (HAL_CAN_AddTxMessage(hcan_x, &can_tx_str, temp_buf, (uint32_t *)&TxMailbox) != HAL_OK)
            {
                if(can1_err == 0)
                {
                    can_wait_cnt++;
                    if(can_wait_cnt > 10000)
                    {
                        can1_err = 1;
                        return SEND_ERR;
                    }
                }
                else if(can1_err == 1)
                {
                    return SEND_ERR;
                }
            }
            
            //发送成功自动恢复
            can1_err = 0;
        }
    }
    else
    {
        return LEN_ERR;
    }
    return SEND_OK;
}


//接收中断
MyCanRxMsgTypeDef gCanRxMsg10 = {0};

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan_x)
{
    HAL_StatusTypeDef HAL_RetVal;

    if (hcan_x == &hcan)
    {
        HAL_RetVal = HAL_CAN_GetRxMessage(hcan_x,  CAN_RX_FIFO0, (CAN_RxHeaderTypeDef *)&gCanRxMsg10,  gCanRxMsg10.Data);
        if ( HAL_OK == HAL_RetVal)
        {
            kfifo_put(&gFifoCanRx, (uint8_t *)&gCanRxMsg10, sizeof(gCanRxMsg10));

            __HAL_CAN_ENABLE_IT (hcan_x, CAN_IT_RX_FIFO0_MSG_PENDING);
        }
    }

}

MyCanRxMsgTypeDef gCanRxMsg11 = {0};

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan_x)
{
    HAL_StatusTypeDef HAL_RetVal;

    if (hcan_x == &hcan)
    {
        HAL_RetVal = HAL_CAN_GetRxMessage(hcan_x,  CAN_RX_FIFO1, (CAN_RxHeaderTypeDef *)&gCanRxMsg11,  gCanRxMsg11.Data);
        if ( HAL_OK == HAL_RetVal)
        {
            kfifo_put(&gFifoCanRx, (uint8_t *)&gCanRxMsg11, sizeof(gCanRxMsg11));

            __HAL_CAN_ENABLE_IT (hcan_x, CAN_IT_RX_FIFO1_MSG_PENDING);
        }
    }

}


int hw_can_init(void)
{
    MX_CAN_Init();
    bsp_can_filter_config(&hcan);
    HAL_CAN_Start(&hcan);
    __HAL_CAN_ENABLE_IT(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING | CAN_IT_RX_FIFO1_MSG_PENDING);

    return HAL_OK;
}


