
#ifndef _EC20_H
#define _EC20_H

#include "main.h"

extern UART_HandleTypeDef huart3;




#define EC20_DELAY  HAL_Delay


#define RxNum_4G	100
#define TxNum_4G	100

#define TCP_VERSION     0x0100	//V1.00

#define TCP_CMD_HEART   0x00	//心跳
#define TCP_CMD_DATA    0x01	//实时数据
#define TCP_CMD_SET_TIM 0x03	//设置上传间隔
#define TCP_CMD_SET_IP  0x04	//设置IP地址、端口号



enum CONNEVT_TYPE
{
	STEP_ATOK = 0,
	STEP_CPIN,
	STEP_CREG,
	STEP_CGREG,
	STEP_APN ,
	STEP_ACT,
	STEP_RSSI,
	STEP_OPENT,
	STEP_CONNECT,
	STEP_STOP_TT,
	STEP_CLOSE,
	STEP_IDLE,
	
};



typedef struct
{

	
	uint8_t RxBuff[RxNum_4G];
	uint8_t TxBuff[TxNum_4G];
	uint8_t DataBuff[RxNum_4G];

	uint8_t AT_RxOk;
	uint8_t TT_RxOk;
	uint8_t RxOk;
	uint8_t TxOk;
	uint8_t UpFlag;		//上传标志位
	uint8_t StepFlag;	
	uint8_t WaitFlag;
	uint8_t Rssi;
	

	uint8_t TimOutCnt;		//AT指令应答超时
	__IO uint16_t RxTimCnt;	//串口接受超时认为接收完成
	__IO uint8_t RxTimStart;
	
	uint16_t DataLen;
	uint16_t WaitCnt;
	__IO uint16_t RxIndex;
	

}EC20_4G_TYPE;

extern EC20_4G_TYPE gEc20Reg;

void Task_4G(void);
void Ec20_Reboot(void);
void Ec20_Active(void);
void Ec20_Csq(void);

void Ec20_Tcp_Up(uint8_t* buff, uint16_t len);
void Ec20_SoftInit(void);
void Ec20_Open(uint8_t* ip_buff, uint8_t* port_buff, uint8_t* mode_buff);
void Ec20_Rx(void);


#endif

/*******************************  END OF FILE  ********************************/


