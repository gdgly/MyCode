
#include "main.h"
#include "string.h"
#include "SEGGER_RTT.h"
#include "app_ec20_4g.h"


EC20_4G_TYPE gEc20Reg = {0};



#define IP_IDEEX	21
#define IP_SIZE		15

#define PORT_IDEEX	38
#define PORT_SIZE	5

#define MODE_IDEEX	46
#define MODE_SIZE	1

#define WAIT_CNT	100	//100ms执行，共等待40s

const uint8_t p_ec20_at[]	=	"AT\r\n\n";

const uint8_t p_ec20_reboot[]	=	"AT+CFUN=1,1\r\n";
const uint8_t p_ec20_cpin[]		=	"AT+CPIN?\r\n";
const uint8_t p_ec20_creg[]		=	"AT+CREG=1\r\n";
const uint8_t p_ec20_cgreg[]    =	"AT+CGREG=1\r\n";
const uint8_t p_ec20_apn[]		=	"AT+QICSGP=1\r\n";
const uint8_t p_ec20_active[]	=	"AT+QIACT=1\r\n";
const uint8_t p_ec20_csq[]		=	"AT+CSQ\r\n";

const uint8_t p_ec20_close[]		=	"AT+QICLOSE=0\r\n";
const uint8_t p_ec20_stop[]		=	"+++";

const uint8_t p_ec20_open[]		=	"AT+QIOPEN=1,0,\"TCP\",\"061.149.215.202\",03000,0,2\r\n";

uint8_t p_ec20_ip[16] =	"120.092.076.047";
uint8_t p_ec20_port[6] =	"04893";
uint8_t p_ec20_mode[2] =	"2";

uint8_t step_flag = 0;
uint8_t next_flag = 0;
uint8_t task_cnt = 0;

UART_HandleTypeDef huart_4g = {0};

void Ec20_SoftInit(void)
{
    memcpy(&huart_4g, &huart3, sizeof(huart_4g));
    
    HAL_GPIO_WritePin(LEVEL_EN_GPIO_Port, LEVEL_EN_Pin, GPIO_PIN_SET);
    
    HAL_GPIO_WritePin(GPIOD, EC25_EN_Pin|EC25_POWKEY_Pin, GPIO_PIN_RESET);
    EC20_DELAY(100);
    HAL_GPIO_WritePin(GPIOD, EC25_EN_Pin|EC25_POWKEY_Pin, GPIO_PIN_SET);
    EC20_DELAY(1000);
    HAL_GPIO_WritePin(GPIOD, EC25_EN_Pin, GPIO_PIN_RESET);
    EC20_DELAY(600);
    HAL_GPIO_WritePin(GPIOD, EC25_EN_Pin, GPIO_PIN_SET);
    
    uint8_t TempRxByte[1] = {0};
    HAL_UART_Receive_IT(&huart_4g, TempRxByte, 1);
    
    gEc20Reg.StepFlag = 0;
    gEc20Reg.WaitFlag = 0;
    gEc20Reg.WaitCnt = WAIT_CNT;
    gEc20Reg.TimOutCnt = 0;

    SEGGER_RTT_printf(0, "Ec20_SoftInit\r\n");
    EC20_DELAY(1000);

}

void Ec20_SendBuff(uint8_t* buff, uint8_t len)
{
    HAL_UART_Transmit(&huart_4g, (uint8_t*)buff, len, 1000);
    
    SEGGER_RTT_printf(0, "SEND-> ");
    SEGGER_RTT_Write(0, buff, len);
}


uint8_t Ec20_FindStr(const char* str)
{
    uint8_t find_test = 0;
    char* pStr = strstr((const char *)gEc20Reg.DataBuff, str);
    

	find_test = !(pStr == NULL);
    return find_test;
}



void EC20_RunFunc_WaitAck(void(*func)(void), uint8_t* str)
{
    if(gEc20Reg.WaitFlag == 0)
    {
        func();
        gEc20Reg.WaitFlag = 1;
    }

    if(gEc20Reg.AT_RxOk == 1)
    {
        gEc20Reg.AT_RxOk = 0;
        memcpy(gEc20Reg.DataBuff, gEc20Reg.RxBuff, RxNum_4G);
        memset(gEc20Reg.RxBuff, 0, RxNum_4G);
        
        SEGGER_RTT_printf(0, "REV <- %s", gEc20Reg.DataBuff);
        
        if(Ec20_FindStr((const char*)str))
        {
            gEc20Reg.StepFlag++;
            gEc20Reg.WaitFlag = 0;
            gEc20Reg.WaitCnt = WAIT_CNT;
            if(func == &Ec20_Reboot)
            {
            	gEc20Reg.WaitCnt = 500;
            }
            else if(func == &Ec20_Active)
            {
            	gEc20Reg.WaitCnt = 500;
            }
            else if(func == &Ec20_Csq)
            {
				gEc20Reg.Rssi = (gEc20Reg.DataBuff[15]-'0')*10;
				gEc20Reg.Rssi += gEc20Reg.DataBuff[16] - '0';
            	//15,16
            }
        }
        if(Ec20_FindStr("ERROR"))
        {
            gEc20Reg.WaitCnt = 0;
        }
    }
}

void EC20_Open_WaitAck(uint8_t* str)
{
    if(gEc20Reg.WaitFlag == 0)
    {
        Ec20_Open(p_ec20_ip, p_ec20_port, p_ec20_mode);
        gEc20Reg.WaitFlag = 1;
    }

    if(gEc20Reg.AT_RxOk == 1)
    {
        gEc20Reg.AT_RxOk = 0;

        memcpy(gEc20Reg.DataBuff, gEc20Reg.RxBuff, RxNum_4G); 
        memset(gEc20Reg.RxBuff, 0, RxNum_4G);
        
        SEGGER_RTT_printf(0, "REV <- %s", gEc20Reg.DataBuff);
        
        if(Ec20_FindStr((const char*)str))
        {
            gEc20Reg.StepFlag++;
            gEc20Reg.WaitFlag = 0;
            gEc20Reg.WaitCnt = WAIT_CNT;
        }
        if(Ec20_FindStr("ERROR"))
        {
            gEc20Reg.WaitCnt = 0;
        }
    }
}


void EC20_WaitAck(uint8_t* str)
{
    if(gEc20Reg.AT_RxOk == 1)
    {
        gEc20Reg.AT_RxOk = 0;
        
        memcpy(gEc20Reg.DataBuff, gEc20Reg.RxBuff, RxNum_4G);
        memset(gEc20Reg.RxBuff, 0, RxNum_4G);
        
        SEGGER_RTT_printf(0, "REV <- %s", gEc20Reg.DataBuff);
        
        if(Ec20_FindStr((const char*)str))
        {
            gEc20Reg.StepFlag++;
            gEc20Reg.WaitFlag = 0;
            gEc20Reg.WaitCnt = WAIT_CNT;
        }
        if(Ec20_FindStr("ERROR"))
        {
            gEc20Reg.WaitCnt = 0;
        }
    }
}



uint16_t uart_end_cnt = 0;
void Ec20_AT_Rx(void)
{
    gEc20Reg.RxBuff[gEc20Reg.RxIndex] = huart_4g.Instance->DR;
	gEc20Reg.RxTimStart = 1;
    
    
    if(gEc20Reg.RxBuff[gEc20Reg.RxIndex] == 0x0D)
    {
        uart_end_cnt++;
        gEc20Reg.RxIndex++;
    }
    else if(gEc20Reg.RxBuff[gEc20Reg.RxIndex] == 0x0A)
    {
        uart_end_cnt++;
        if(uart_end_cnt == 2)
        {
            uart_end_cnt = 0;

            gEc20Reg.AT_RxOk = 1;
            gEc20Reg.RxIndex = 0;
        }
    }
    else
    {
        uart_end_cnt = 0;
        gEc20Reg.RxIndex++;
    }

}

void Ec20_TT_Rx(void)
{
    gEc20Reg.RxBuff[gEc20Reg.RxIndex] = huart_4g.Instance->DR;

    switch (gEc20Reg.RxIndex)
    {
    case 0:
        if ( gEc20Reg.RxBuff[gEc20Reg.RxIndex] == 0x7a )
        {
            gEc20Reg.RxIndex++;
        }
        else
        {
            gEc20Reg.RxIndex = 0;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        gEc20Reg.RxIndex++;
        break;
    case 9:
        if(gEc20Reg.RxBuff[gEc20Reg.RxIndex] == 0x7b)
        {
            gEc20Reg.RxIndex = 0;
            gEc20Reg.RxOk = 1;
        }
        else
        {
            gEc20Reg.RxIndex = 0;
        }
        break;
    default:
        gEc20Reg.RxIndex = 0;

        break;
    }
}



void Ec20_Rx(void)
{
    uint32_t it_flag = 0;
    uint32_t it_source = 0;

    it_flag = __HAL_UART_GET_FLAG(&huart_4g, UART_FLAG_RXNE);
    it_source = __HAL_UART_GET_IT_SOURCE(&huart_4g, UART_IT_RXNE);

    if((it_flag != RESET) && (it_source != RESET))
    {
        if(gEc20Reg.StepFlag == STEP_CONNECT)
        {
            Ec20_TT_Rx();
        }
        else
        {
            Ec20_AT_Rx();
        }

    }
}


void Ec20_DataParse(void)
{


}



void Ec20_AT(void)
{
    Ec20_SendBuff((uint8_t*)p_ec20_at, sizeof(p_ec20_at)-1);
}

void Ec20_Reboot(void)
{
    Ec20_SendBuff((uint8_t*)p_ec20_reboot, sizeof(p_ec20_reboot)-1);
}

void Ec20_Cpin(void)
{
    Ec20_SendBuff((uint8_t*)p_ec20_cpin, sizeof(p_ec20_cpin)-1);
}

void Ec20_Creg(void)
{
    Ec20_SendBuff((uint8_t*)p_ec20_creg, sizeof(p_ec20_creg)-1);
}

void Ec20_Cgreg(void)
{
    Ec20_SendBuff((uint8_t*)p_ec20_cgreg, sizeof(p_ec20_cgreg)-1);
}


void Ec20_Apn(void)
{
    Ec20_SendBuff((uint8_t*)p_ec20_apn, sizeof(p_ec20_apn)-1);
}


void Ec20_Active(void)
{
    Ec20_SendBuff((uint8_t*)p_ec20_active, sizeof(p_ec20_active)-1);
}

void Ec20_Close(void)//断开连接
{
    Ec20_SendBuff((uint8_t*)p_ec20_close, sizeof(p_ec20_close)-1);
}


void Ec20_Stop_T_T(void)//停止透传	//Transparent_transmission
{
    Ec20_SendBuff((uint8_t*)p_ec20_stop, sizeof(p_ec20_stop)-1);
}

void Ec20_Csq(void)		//获取4G信号强度
{
    Ec20_SendBuff((uint8_t*)p_ec20_csq, sizeof(p_ec20_csq)-1);
}



void Ec20_Open(uint8_t* ip_buff, uint8_t* port_buff, uint8_t* mode_buff)//开启连接并启动透传
{
    uint8_t len = sizeof(p_ec20_open)-1;

    memcpy(gEc20Reg.TxBuff, p_ec20_open, len);

    memcpy(&gEc20Reg.TxBuff[IP_IDEEX], ip_buff, IP_SIZE);
    memcpy(&gEc20Reg.TxBuff[PORT_IDEEX], port_buff, PORT_SIZE);
    memcpy(&gEc20Reg.TxBuff[MODE_IDEEX], mode_buff, MODE_SIZE);



    Ec20_SendBuff(gEc20Reg.TxBuff, len);

}


void Ec20_ConnectMode(void)//处于连接状态
{
    gEc20Reg.WaitCnt = WAIT_CNT;

}

void Ec20_Idle(void)//处于空闲状态
{
    gEc20Reg.WaitCnt = WAIT_CNT;

}

uint8_t tcp_send_buff[20] = {0x7a, 0x7a, 0, 0, };
void Ec20_Tcp_Up(uint8_t* buff, uint16_t len)
{
	uint16_t crc_temp = 0;
	
	tcp_send_buff[2] = TCP_VERSION>>8;
	tcp_send_buff[3] = TCP_VERSION&0x00ff;
	tcp_send_buff[4] = TCP_CMD_DATA;
	tcp_send_buff[5] = len>>8;
	tcp_send_buff[6] = len&0x00ff;

	//crc_temp = Crc_Crc16(buff, len);

	tcp_send_buff[10] = crc_temp>>8;
	tcp_send_buff[11] = crc_temp&0x00ff;
	tcp_send_buff[12] = 0x7b;
	tcp_send_buff[13] = 0x7b;

	HAL_UART_Transmit(&huart_4g, tcp_send_buff, 7, 100);
	HAL_UART_Transmit(&huart_4g, buff, len, 5000);
	HAL_UART_Transmit(&huart_4g, &tcp_send_buff[10], 4, 100);
	
	
}

void Task_4G(void)
{
    if(gEc20Reg.WaitCnt > 0)
    {
        gEc20Reg.WaitCnt--;
    }

    if(gEc20Reg.WaitCnt == 0)
    {
        gEc20Reg.TimOutCnt++;
        if(gEc20Reg.TimOutCnt <= 2)
        {
            gEc20Reg.WaitFlag = 0;
            gEc20Reg.WaitCnt = WAIT_CNT;
        }
        else if(gEc20Reg.TimOutCnt >= 3)
        {
            Ec20_SoftInit();
        }
    }

    Ec20_DataParse();

    switch(gEc20Reg.StepFlag)
    {
    case STEP_ATOK:
        EC20_RunFunc_WaitAck(Ec20_AT, "OK");
        break;
    
    case STEP_CPIN:
        EC20_RunFunc_WaitAck(Ec20_Cpin, "READY");
        break;
    case STEP_CREG:
        EC20_RunFunc_WaitAck(Ec20_Creg, "OK");
        break;
    case STEP_CGREG:
        EC20_RunFunc_WaitAck(Ec20_Cgreg, "OK");
        break;
    case STEP_APN:
        EC20_RunFunc_WaitAck(Ec20_Apn, "OK");
        break;
    case STEP_ACT:
        EC20_RunFunc_WaitAck(Ec20_Active, "OK");
        break;
    case STEP_RSSI:
        EC20_RunFunc_WaitAck(Ec20_Csq, "OK");
        break;
    case STEP_OPENT:
        EC20_Open_WaitAck("CONNECT");
        break;
    case STEP_CONNECT:
        Ec20_ConnectMode();
        break;
    case STEP_STOP_TT:
        EC20_RunFunc_WaitAck(Ec20_Stop_T_T, "OK");
        break;
    case STEP_CLOSE:
        EC20_RunFunc_WaitAck(Ec20_Close, "OK");
        break;
    case STEP_IDLE:
        Ec20_Idle();
        break;
    default:
        break;
    }

}




