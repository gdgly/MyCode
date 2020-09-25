/*
* @Description: can上层(初始化发送 接收 解析 中断等)
 * @Author: your name
 * @Date: 2019-08-21 09:56:05
 * @LastEditTime: 2019-09-08 15:45:13
 * @LastEditors: Please set LastEditors
 */


#include "bsp_can.h"
#include "main.h"
#include "kfifo.h"
#include "can.h"
#include "gpio.h"


CAN_STA_TYPE gCanStaReg = {0};

MyCanRxMsgTypeDef gCanTempMsg = {0};

const uint32_t filter_id[] =
{
    0x000, 0x010, 0x020, 0x030, 0x040, 0x080, 0x300,
};

const uint32_t filter_mask[] =
{
    0xCF0, 0xCF0, 0xCF0, 0xCF0, 0xCF0, 0xCF0, 0xf00,
};

uint32_t test_can = 0;

#if 1


void bsp_can_filter_config(CAN_HandleTypeDef *hcan)
{
    CAN_FilterTypeDef Filter_Init;


    Filter_Init.FilterIdHigh		= 0;
    Filter_Init.FilterIdLow			= 0;
    Filter_Init.FilterMaskIdHigh	= 0;
    Filter_Init.FilterMaskIdLow		= 0;
    Filter_Init.FilterMode = CAN_FILTERMODE_IDMASK;
    Filter_Init.FilterScale = CAN_FILTERSCALE_32BIT;
    Filter_Init.FilterActivation = ENABLE;

    Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    Filter_Init.FilterBank = 0;
	Filter_Init.SlaveStartFilterBank = 14;

    while (HAL_CAN_ConfigFilter(&hcan1, &Filter_Init) != HAL_OK);

    Filter_Init.FilterIdHigh		= 0;
    Filter_Init.FilterIdLow			= 0;
    Filter_Init.FilterMaskIdHigh	= 0;
    Filter_Init.FilterMaskIdLow		= 0;
    Filter_Init.FilterMode = CAN_FILTERMODE_IDMASK;
    Filter_Init.FilterScale = CAN_FILTERSCALE_32BIT;
    Filter_Init.FilterActivation = ENABLE;

    Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO1;
    Filter_Init.FilterBank = 14;
	Filter_Init.SlaveStartFilterBank = 14;

    while (HAL_CAN_ConfigFilter(&hcan2, &Filter_Init) != HAL_OK);

}


//void bsp_can_filter_config(CAN_HandleTypeDef *hcan)
//{

//    CAN_FilterTypeDef Filter_Init;
//    
//    if(hcan == &hcan1)
//    {
//		for(uint8_t i=0; i<sizeof(filter_id); i++)
//		{
//			Filter_Init.FilterIdHigh		= ((filter_id[i]<<21) & 0xffff0000) >> 16;
//			Filter_Init.FilterIdLow			= ((filter_id[i]<<21)|CAN_ID_STD|CAN_RTR_DATA) & 0xffff;
//			Filter_Init.FilterMaskIdHigh	= ((filter_mask[i]<<21) & 0xffff0000) >> 16;
//			Filter_Init.FilterMaskIdLow		= 0x04|0x02;
//            
//            Filter_Init.FilterMode = CAN_FILTERMODE_IDMASK;
//            Filter_Init.FilterScale = CAN_FILTERSCALE_32BIT;
//            Filter_Init.FilterActivation = ENABLE;
//            Filter_Init.SlaveStartFilterBank = 14;

//	        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
//	        Filter_Init.FilterBank = i;

//			while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);
//		}

//		Filter_Init.FilterIdHigh		= ((0x99<<3) & 0xffff0000) >> 16;
//		Filter_Init.FilterIdLow			= ((0x99<<3)|CAN_ID_EXT|CAN_RTR_DATA) & 0xffff;
////		Filter_Init.FilterMaskIdHigh	= ((0x99<<3) & 0xffff0000) >> 16;
////		Filter_Init.FilterMaskIdLow		= (0x99<<3)|0x04|0x02;
//		
//		Filter_Init.FilterMaskIdHigh	= 0xffff;
//		Filter_Init.FilterMaskIdLow		= 0xffff;

//        Filter_Init.FilterMode = CAN_FILTERMODE_IDMASK;
//        Filter_Init.FilterScale = CAN_FILTERSCALE_32BIT;
//        Filter_Init.FilterActivation = ENABLE;
//        Filter_Init.SlaveStartFilterBank = 14;

//        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
//        Filter_Init.FilterBank = 10;

//		while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);
//		

//    }
//    else if(hcan == &hcan2)
//    {
//		for(uint8_t i=0; i<sizeof(filter_id); i++)
//		{
//			Filter_Init.FilterIdHigh		= ((filter_id[i]<<21) & 0xffff0000) >> 16;
//			Filter_Init.FilterIdLow			= ((filter_id[i]<<21)|CAN_ID_STD|CAN_RTR_DATA) & 0xffff;
//			Filter_Init.FilterMaskIdHigh	= ((filter_mask[i]<<21) & 0xffff0000) >> 16;
//			Filter_Init.FilterMaskIdLow		= 0x04|0x02;

//            Filter_Init.FilterMode = CAN_FILTERMODE_IDMASK;
//            Filter_Init.FilterScale = CAN_FILTERSCALE_32BIT;
//            Filter_Init.FilterActivation = ENABLE;
//            Filter_Init.SlaveStartFilterBank = 14;

//	        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO1;
//	        Filter_Init.FilterBank = 15+i;

//			while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);
//		}
//    }
//}

#else

void bsp_can_filter_config(CAN_HandleTypeDef *hcan)
{
    uint16_t std_id1 = 0x0000;
    uint16_t std_id2 = 0x0000;
    uint16_t std_id3 = 0x0000;
    uint16_t std_id4 = 0x0000;

    uint32_t ext_id1 = 0x0000;


    CAN_FilterTypeDef Filter_Init;

    if(hcan == &hcan1)
    {
        std_id1 = 0x320;
        std_id2 = 0x181;
        std_id3 = 0x352;
        std_id4 = 0x01C;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 0;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);

        std_id1 = 0x360;
        std_id2 = 0x210;
        std_id3 = 0x211;
        std_id4 = 0x212;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 1;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);


        std_id1 = 0x213;
        std_id2 = 0x365;
        std_id3 = 0x019;
        std_id4 = 0x201;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 2;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);


        std_id1 = 0x322;
        std_id2 = 0x01D;
        std_id3 = 0x361;
        std_id4 = 0x01A;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 3;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);


        std_id1 = 0x3B9;
        std_id2 = 0x3BA;
        std_id3 = 0x3BB;
        std_id4 = 0x3BC;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 4;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);


        std_id1 = 0x3BF;
        std_id2 = 0x01B;
        std_id3 = 0x321;
        std_id4 = 0x340;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 5;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);

        std_id1 = 0x035;
        std_id2 = 0x045;
        std_id3 = 0x311;
        std_id4 = 0x025;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 6;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);

        std_id1 = 0x3C2;
        std_id2 = 0x141;
        std_id3 = 0x141;
        std_id4 = 0x121;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 7;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);


        std_id1 = 0x301;
        std_id2 = 0x111;
        std_id3 = 0x122;
        std_id4 = 0x141;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 8;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);

        //iap升级
        ext_id1 = 0x99 << 3;
        ext_id1 = 0x99 << 3;


        Filter_Init.FilterIdHigh		= (ext_id1 >> 16) & 0xffff;
        Filter_Init.FilterIdLow			= (ext_id1 & 0xffff) | CAN_ID_EXT;

        Filter_Init.FilterMaskIdHigh	= (ext_id1 >> 16) & 0xffff;
        Filter_Init.FilterMaskIdLow		= (ext_id1 & 0xffff) | CAN_ID_EXT;


        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO0;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_32BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 9;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);


    }
    else if(hcan == &hcan2)
    {
        std_id1 = 0x301;
        std_id2 = 0x018;
        std_id3 = 0x022;
        std_id4 = 0x012;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO1;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 14;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);


        std_id1 = 0x111;
        std_id2 = 0x112;
        std_id3 = 0x013;
        std_id4 = 0x121;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO1;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 15;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);


        std_id1 = 0x122;
        std_id2 = 0x123;
        std_id3 = 0x134;
        std_id4 = 0x014;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO1;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 16;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);


        std_id1 = 0x141;
        std_id2 = 0x340;
        std_id3 = 0x015;
        std_id4 = 0x347;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO1;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 17;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);


        std_id1 = 0x016;
        std_id2 = 0x01E;
        std_id3 = 0x113;
        std_id4 = 0x36B;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO1;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 18;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);

        std_id1 = 0x029;
        std_id2 = 0x3BC;
        std_id3 = 0x3C2;
        std_id4 = 0x3C2;

        Filter_Init.FilterIdHigh		= std_id1 << 5;
        Filter_Init.FilterIdLow			= std_id2 << 5;
        Filter_Init.FilterMaskIdHigh	= std_id3 << 5;
        Filter_Init.FilterMaskIdLow		= std_id4 << 5;

        Filter_Init.FilterFIFOAssignment = CAN_FILTER_FIFO1;
        Filter_Init.FilterMode = CAN_FILTERMODE_IDLIST;
        Filter_Init.FilterScale = CAN_FILTERSCALE_16BIT;
        Filter_Init.FilterActivation = ENABLE;
        Filter_Init.FilterBank = 19;

        while (HAL_CAN_ConfigFilter(hcan, &Filter_Init) != HAL_OK);

    }
}
#endif

uint32_t can_send_cnt = 0;
uint32_t can_wait_cnt = 0;

//发送
CAN_TX_STA_E bsp_can_send(CAN_HandleTypeDef *hcan, uint32_t can_id, uint8_t *pData, uint16_t len)
{

    uint8_t free_mail_box = 0;
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

        while(free_mail_box == 0)
        {
            free_mail_box = HAL_CAN_GetTxMailboxesFreeLevel(hcan);
            can_wait_cnt++;
        }

        while (HAL_CAN_AddTxMessage(hcan, &can_tx_str, temp_buf, (uint32_t *)&TxMailbox) != HAL_OK)
        {
            can_send_cnt++;
        }


    }
    else
    {
        return LEN_ERR;
    }
    return SEND_OK;
}



//接收中断
MyCanRxMsgTypeDef gCanRxMsg1 = {0};
MyCanRxMsgTypeDef gCanRxMsg2 = {0};
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    HAL_StatusTypeDef HAL_RetVal;

    if (hcan == &hcan1)
    {
        HAL_RetVal = HAL_CAN_GetRxMessage(hcan,  CAN_RX_FIFO0, (CAN_RxHeaderTypeDef *)&gCanRxMsg1,  gCanRxMsg1.Data);
        if ( HAL_OK == HAL_RetVal)
        {
            my_fifo_put(&gFifoReg1, (uint8_t *)&gCanRxMsg1, sizeof(gCanRxMsg1));

            __HAL_CAN_ENABLE_IT (hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
        }
    }
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    HAL_StatusTypeDef HAL_RetVal;

    if (hcan == &hcan2)
    {
        HAL_RetVal = HAL_CAN_GetRxMessage(hcan,  CAN_RX_FIFO1, (CAN_RxHeaderTypeDef *)&gCanRxMsg2,  gCanRxMsg2.Data);
        if ( HAL_OK == HAL_RetVal)
        {
            my_fifo_put(&gFifoReg2, (uint8_t *)&gCanRxMsg2, sizeof(gCanRxMsg2));

            __HAL_CAN_ENABLE_IT (hcan, CAN_IT_RX_FIFO1_MSG_PENDING);
        }
    }
}


int hw_can_init(void)
{
    //MX_CAN1_Init();
    //MX_CAN2_Init();

    bsp_can_filter_config(&hcan1);
    bsp_can_filter_config(&hcan2);


    HAL_CAN_Start(&hcan1);
    HAL_CAN_Start(&hcan2);

    __HAL_CAN_ENABLE_IT(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
    __HAL_CAN_ENABLE_IT(&hcan2, CAN_IT_RX_FIFO1_MSG_PENDING);

    return 0;
}


