
#ifndef __DRV_NRF24D_H__
#define __DRV_NRF24D_H__

#include "stm32f4xx_hal.h"



#if 1

#define NRF_CE_LOW()	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET)
#define NRF_CE_HIGH()	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET)

#define SPI_NSS_LOW()	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET)
#define SPI_NSS_HIGH()	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET)


#define MISO_IN()		HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)
#define MOSI_OUT(n)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, n)
#define SCK_OUT(n)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, n)


#endif
//*********************************************NRF24L01*************************************
#define TX_ADR_WIDTH    3   	// 5 uints TX address width
#define RX_ADR_WIDTH    3   	// 5 uints RX address width
#define TX_PLOAD_WIDTH  4  	// 20 uints TX payload

#define RX_PLOAD_WIDTH  6  	// 20 uints TX payload

//fyf
#define NRF_FIFO_SIZE  RX_PLOAD_WIDTH  	// 20 uints TX payload



//***************************************NRF24L01�Ĵ���ָ��*******************************************************
#define RF_READ_REG		0x00  	// ���Ĵ���ָ��
#define RF_WRITE_REG	0x20 	// д�Ĵ���ָ��
#define RD_RX_PLOAD     0x61  	// ��ȡ��������ָ��
#define WR_TX_PLOAD     0xA0  	// д��������ָ��
#define FLUSH_TX        0xE1 	// ��ϴ���� FIFOָ��
#define FLUSH_RX        0xE2  	// ��ϴ���� FIFOָ��
#define REUSE_TX_PL     0xE3  	// �����ظ�װ������ָ��
#define NOP             0xFF  	// ����
//*************************************SPI(nRF24L01)�Ĵ�����ַ****************************************************
#define CONFIG          0x00  // �����շ�״̬��CRCУ��ģʽ�Լ��շ�״̬��Ӧ��ʽ
#define EN_AA           0x01  // �Զ�Ӧ��������
#define EN_RXADDR       0x02  // �����ŵ�����
#define SETUP_AW        0x03  // �շ���ַ�������
#define SETUP_RETR      0x04  // �Զ��ط���������
#define RF_CH           0x05  // ����Ƶ������
#define RF_SETUP        0x06  // �������ʡ����Ĺ�������
#define STATUS          0x07  // ״̬�Ĵ���
#define OBSERVE_TX      0x08  // ���ͼ�⹦��
#define CD              0x09  // ��ַ���           
#define RX_ADDR_P0      0x0A  // Ƶ��0�������ݵ�ַ
#define RX_ADDR_P1      0x0B  // Ƶ��1�������ݵ�ַ
#define RX_ADDR_P2      0x0C  // Ƶ��2�������ݵ�ַ
#define RX_ADDR_P3      0x0D  // Ƶ��3�������ݵ�ַ
#define RX_ADDR_P4      0x0E  // Ƶ��4�������ݵ�ַ
#define RX_ADDR_P5      0x0F  // Ƶ��5�������ݵ�ַ
#define TX_ADDR         0x10  // ���͵�ַ�Ĵ���
#define RX_PW_P0        0x11  // ����Ƶ��0�������ݳ���
#define RX_PW_P1        0x12  // ����Ƶ��0�������ݳ���
#define RX_PW_P2        0x13  // ����Ƶ��0�������ݳ���
#define RX_PW_P3        0x14  // ����Ƶ��0�������ݳ���
#define RX_PW_P4        0x15  // ����Ƶ��0�������ݳ���
#define RX_PW_P5        0x16  // ����Ƶ��0�������ݳ���
#define FIFO_STATUS     0x17  // FIFOջ��ջ��״̬�Ĵ�������


uint8_t SPI_Read_Reg(uint8_t reg);
uint8_t SPI_ReadWriteByte(uint8_t data);
uint8_t SPI_Write_Reg(uint8_t reg, uint8_t value);

void Init_NRF24L01(void);
void nRF24L01_TxPacket(uint8_t * tx_buf, uint8_t len);
uint8_t nRF24L01_RxPacket(uint8_t * rx_buf, uint8_t len);
void SetRX_Mode(void);
void SetTX_Mode(void);

#endif


