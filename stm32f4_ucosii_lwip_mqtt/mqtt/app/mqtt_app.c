/**********************************************************************************************************
** �ļ���		:mqtt_app.c
** ����			:maxlicheng<licheng.chn@outlook.com>
** ����github	:https://github.com/maxlicheng
** ���߲���		:https://www.maxlicheng.com/	
** ��������		:2018-08-08
** ����			:mqtt�������
************************************************************************************************************/
#include "mqtt_app.h"
#include "MQTTPacket.h"
#include "transport.h"
#include "ucos_ii.h"
#include "led.h"
#include "ds18b20.h"
#include "malloc.h"
#include "lcd.h"

#include <string.h>
#include <stdio.h>

#include "hmac.h"
#include "cJSON.h"

#include "U2GBK.h"
#include "text.h"	

#define send_duration	10	//�¶ȷ������ڣ�ms��

float temp = 0;
float humid = 0;

//typedef struct
//{
//    u8 led;
//	char *display;
//}revType;

//revType revListMem;

void mqtt_thread(void)
{
	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
	MQTTString receivedTopic;
	MQTTString topicString = MQTTString_initializer;
	
	int rc = 0;
	unsigned char buf[200];
	int buflen = sizeof(buf);
	int	mysock = 0;
	
	int payloadlen_in;
	unsigned char* payload_in;
	unsigned short msgid = 1;
	int subcount;
	int granted_qos =0;
	unsigned char sessionPresent, connack_rc;
	unsigned short submsgid;
	int len = 0;
	int req_qos = 1;
	unsigned char dup;
	int qos;
	unsigned char retained = 0;

	uint8_t connect_flag = 0;		//���ӱ�־
	uint8_t msgtypes = CONNECT;		//��Ϣ״̬��ʼ��
	uint8_t t=0;
	
	printf("socket connect to server\r\n");
	mysock = transport_open((char *)HOST_NAME,HOST_PORT);
	printf("Sending to hostname %s port %d\r\n", HOST_NAME, HOST_PORT);
	
	len = MQTTSerialize_disconnect((unsigned char*)buf,buflen);
	rc = transport_sendPacketBuffer(mysock, (unsigned char*)buf, len);
	if(rc == len)															//
		printf("send DISCONNECT Successfully\r\n");
	else
		printf("send DISCONNECT failed\r\n"); 
	
	OSTimeDlyHMSM(0,0,2,500);
	
	printf("socket connect to server\r\n");
	mysock = transport_open((char *)HOST_NAME,HOST_PORT);
	printf("Sending to hostname %s port %d\r\n", HOST_NAME, HOST_PORT);
	
	data.clientID.cstring = CLIENT_ID;
	data.keepAliveInterval = 70;		//����ʱ��
	data.cleansession = 1;
	data.username.cstring = USER_NAME;
	char *PASSWORD;
	PASSWORD = mymalloc(SRAMEX, 200);
	getPassword(DEVICE_SECRET, CONTENT, PASSWORD);			//ͨ��hmac_sha1�㷨�õ�password
	printf("\r\nPassWord = %s\r\n\r\n", PASSWORD);
	data.password.cstring = PASSWORD;
	data.MQTTVersion = 4;
	myfree(SRAMEX, PASSWORD);
	
	unsigned char payload_out[200];
	int payload_out_len = 0;
	OS_CPU_SR cpu_sr=0;
	uint32_t curtick  =	OSTimeGet();
	uint32_t sendtick = OSTimeGet();
	while(1)
	{
		if((OSTimeGet() - curtick) >(data.keepAliveInterval*200))		//uCosII ÿ��200��tick
		{
			if(msgtypes == 0)
			{
				curtick = OSTimeGet();
				msgtypes = PINGREQ;
			}

		}
		if(connect_flag == 1)
		{
			if((OSTimeGet() - sendtick) >= (send_duration*200))
			{
				sendtick = OSTimeGet();
				OS_ENTER_CRITICAL();	//�����ٽ���(�޷����жϴ��)
				temp = DS18B20_Get_Temp()/10.0;
				OS_EXIT_CRITICAL();		//�˳��ٽ���(���Ա��жϴ��)
//				temp = 24.7+rand()%10+1;
				humid = 54.8+rand()%10+1;
				sprintf((char*)payload_out,"{\"params\":{\"CurrentTemperature\":+%0.1f,\"RelativeHumidity\":%0.1f},\"method\":\"thing.event.property.post\"}",temp, humid);
				payload_out_len = strlen((char*)payload_out);
				topicString.cstring = DEVICE_PUBLISH;		//�����ϱ� ����
				len = MQTTSerialize_publish((unsigned char*)buf, buflen, 0, req_qos, retained, msgid, topicString, payload_out, payload_out_len);
				rc = transport_sendPacketBuffer(mysock, (unsigned char*)buf, len);
				if(rc == len)															//
					printf("send PUBLISH Successfully\r\n");
				else
					printf("send PUBLISH failed\r\n");  
				printf("send temp(%0.1f)&humid(%0.1f) !\r\n",temp, humid);
			}
		}
		switch(msgtypes)
		{

			case CONNECT:	len = MQTTSerialize_connect((unsigned char*)buf, buflen, &data); 						//��ȡ�����鳤��		����������Ϣ     
							rc = transport_sendPacketBuffer(mysock, (unsigned char*)buf, len);		//���� ���ط������鳤��
							if(rc == len)															//
								printf("send CONNECT Successfully\r\n");
							else
								printf("send CONNECT failed\r\n");               
							printf("MQTT concet to server!\r\n");
							msgtypes = 0;
							break;

			case CONNACK:   if(MQTTDeserialize_connack(&sessionPresent, &connack_rc, (unsigned char*)buf, buflen) != 1 || connack_rc != 0)	//�յ���ִ
							{
								printf("Unable to connect, return code %d\r\n", connack_rc);		//��ִ��һ�£�����ʧ��
							}
							else
							{
								printf("MQTT is concet OK!\r\n");									//���ӳɹ�
								connect_flag = 1;
							}
							msgtypes = SUBSCRIBE;													//���ӳɹ� ִ�� ���� ����
							break;
			case SUBSCRIBE: topicString.cstring = DEVICE_SUBSCRIBE;
							len = MQTTSerialize_subscribe((unsigned char*)buf, buflen, 0, msgid, 1, &topicString, &req_qos);
							rc = transport_sendPacketBuffer(mysock, (unsigned char*)buf, len);
							if(rc == len)
								printf("send SUBSCRIBE Successfully\r\n");
							else
							{
								printf("send SUBSCRIBE failed\r\n"); 
								t++;
								if(t >= 10)
								{
									t = 0;
									msgtypes = CONNECT;
								}
								else
									msgtypes = SUBSCRIBE;
								break;
							}
							printf("client subscribe:[%s]\r\n",topicString.cstring);
							msgtypes = 0;
							break;
			case SUBACK: 	rc = MQTTDeserialize_suback(&submsgid, 1, &subcount, &granted_qos, (unsigned char*)buf, buflen);	//�л�ִ  QoS                                                     
							printf("granted qos is %d\r\n", granted_qos);         								//��ӡ Qos                                                       
							msgtypes = 0;
							break;
			case PUBLISH:	rc = MQTTDeserialize_publish(&dup, &qos, &retained, &msgid, &receivedTopic,&payload_in, &payloadlen_in, (unsigned char*)buf, buflen);	//��������������Ϣ
							printf("message arrived : %s\r\n", payload_in);
							cJSON *json , *json_params, *json_id, *json_led, *json_display;
							json = cJSON_Parse((char *)payload_in);			//�������ݰ�
							if (!json)  
							{  
								printf("Error before: [%s]\r\n",cJSON_GetErrorPtr());  
							} 
							else
							{
								json_id = cJSON_GetObjectItem(json , "id"); 
								if(json_id->type == cJSON_String)
								{
									printf("id:%s\r\n", json_id->valuestring);  
								}
								json_params = cJSON_GetObjectItem(json , "params");  
								if(json_params)  
								{  
									if(cJSON_GetObjectItem(json_params, "led"))
									{
										json_led  = cJSON_GetObjectItem(json_params, "led");
										if(json_led->type == cJSON_Number)
										{
											printf("LED:%d\r\n", json_led->valueint);  
											LED1 = ~(json_led->valueint);
										}
									}
									if(cJSON_GetObjectItem(json_params, "display"))
									{
										json_display = cJSON_GetObjectItem(json_params, "display");
										if (json_display->type == cJSON_String)  
										{  
											u8 *showbuf;
											showbuf = mymalloc(SRAMIN, 200);
											memset(showbuf, 0, 200);
											Utf8ToGb2312(json_display->valuestring, strlen(json_display->valuestring), showbuf);
//										Show_Str(30,244,200,16,"��Ӧ����(16*16)Ϊ:",16,0);
											POINT_COLOR = BLUE;
											LCD_DrawRectangle(10,210,230,300);
											LCD_Fill(11,211,229,299,WHITE);
//										POINT_COLOR = BLUE;
											Show_Str(30,220,200,16,showbuf,16,0);	
											printf("display��%s\r\n", json_display->valuestring);  
//										LCD_ShowString(30,190,210,16,16,json_display->valuestring); 
											myfree(SRAMIN, showbuf);
										}  
									}
								} 
							}
							cJSON_Delete(json);
							
							if(qos == 1)
							{
								printf("publish qos is 1,send publish ack.\r\n");							//QosΪ1�����л�ִ ��Ӧ
								memset(buf,0,buflen);
								len = MQTTSerialize_ack((unsigned char*)buf,buflen,PUBACK,dup,msgid);   					//publish ack                       
								rc = transport_sendPacketBuffer(mysock, (unsigned char*)buf, len);			//
								if(rc == len)
									printf("send PUBACK Successfully\r\n");
								else
									printf("send PUBACK failed\r\n");                                       
							}
							msgtypes = 0;
							break;
			case PUBACK:    printf("PUBACK!\r\n");					//�����ɹ�
							msgtypes = 0;
							break;

			case PUBREC:    printf("PUBREC!\r\n");     				//just for qos2
							break;
			case PUBREL:    printf("PUBREL!\r\n");        			//just for qos2
							break;
			case PUBCOMP:   printf("PUBCOMP!\r\n");        			//just for qos2
							break;
			case PINGREQ:   len = MQTTSerialize_pingreq((unsigned char*)buf, buflen);							//����
							rc = transport_sendPacketBuffer(mysock, (unsigned char*)buf, len);
							if(rc == len)
								printf("send PINGREQ Successfully\r\n");
							else
								printf("send PINGREQ failed\r\n");       
								printf("time to ping mqtt server to take alive!\r\n");
								msgtypes = 0;
							break;
			case PINGRESP:	printf("mqtt server Pong\r\n");  			//������ִ����������Ӧ                                                     
							msgtypes = 0;
							break;
			default:
							break;

		}
		memset(buf,0,buflen);
		rc=MQTTPacket_read((unsigned char*)buf, buflen, transport_getdata);       	//��ѯ����MQTT�������ݣ�
		if(rc >0)													//��������ݣ�������Ӧ״̬��
		{
			msgtypes = rc;
			printf("MQTT is get recv:\r\n");
		}
	}
	transport_close(mysock);
    printf("mqtt thread exit.\r\n");
    OSTaskDel(NULL);
}



/*
// C prototype : void HexToStr(BYTE *pbDest, BYTE *pbSrc, int nLen)
// parameter(s): [OUT] pbDest - ���Ŀ���ַ���
// [IN] pbSrc - ����16����������ʼ��ַ
// [IN] nLen - 16���������ֽ���
// return value: 
// remarks : ��16������ת��Ϊ�ַ���
*/
void HexToStr(uint8_t *pbDest, uint8_t *pbSrc, int nLen)
{
	char ddl,ddh;
	int i;

	for (i=0; i<nLen; i++)
	{
		ddh = 48 + pbSrc[i] / 16;
		ddl = 48 + pbSrc[i] % 16;
		if (ddh > 57) ddh = ddh + 7;
		if (ddl > 57) ddl = ddl + 7;
		pbDest[i*2] = ddh;
		pbDest[i*2+1] = ddl;
	}

	pbDest[nLen*2] = '\0';
}

//ͨ��hmac_sha1�㷨��ȡpassword
void getPassword(const char *device_secret, const char *content, char *password)
{
	char buf[256] = {0};
	int len = sizeof(buf);

//	printf("\r\nlen = %d\r\n\r\n", len);

	hmac_sha1(device_secret, strlen(device_secret), content, strlen(content), buf, &len);
	HexToStr(password, buf, len);
}




