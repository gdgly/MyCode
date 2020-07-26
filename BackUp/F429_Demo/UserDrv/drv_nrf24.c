
#include "global.h"



//uint8_t  TX_ADDRESS[TX_ADR_WIDTH]= {0x34,0x43,0x10,0x10,0x01};  //���ص�ַ
//uint8_t  RX_ADDRESS[RX_ADR_WIDTH]= {0x34,0x43,0x10,0x10,0x01};  //���յ�ַ

static uint8_t TX_ADDRESS[TX_ADR_WIDTH] = {0x19,0x3c,0xb7};

uint8_t SPI_Write_Reg(uint8_t reg, uint8_t value);
static uint8_t SPI_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t uchars);
static uint8_t SPI_Read_Buf(uint8_t reg, uint8_t *pBuf, uint8_t uchars);
void delay_us(uint16_t t)
{
    while(t--)
    {}
}
/*******************************************************************************
* Function Name  : Flash_ReadWriteByte
* Description    : ͨ��Ӳ��SPI����һ���ֽڵ�SST25VF016B
* Input          : - data: ���͵�����
* Output         : None
* Return         : SST25VF016B ���ص�����
* Attention      : None
*******************************************************************************/

#define MY_SPI_MODE 1
uint8_t SPI_ReadWriteByte(uint8_t TxData)
{

#if MY_SPI_MODE == 0
    while((SPI1->SR&1<<1)==0);  //�ȴ���������
    SPI1->DR=TxData;              //����һ��byte
    while((SPI1->SR&1<<0)==0);  //�ȴ�������һ��byte
    return SPI1->DR;            //�����յ�������

#elif MY_SPI_MODE == 1

    uint8_t RxData;
    HAL_SPI_TransmitReceive(&hspi1, &TxData, &RxData, 1, 1000);
    return RxData;

#elif MY_SPI_MODE == 2

#define DELAY_CNT 50
    u8 bit_ctr;
    int delay;
    delay = DELAY_CNT;
    while(delay) delay--;

    for(bit_ctr = 0; bit_ctr < 8; bit_ctr++)
    {
        if(TxData & 0x80)
            MOSI_OUT(1);
        else
            MOSI_OUT(0);
        TxData = (TxData << 1);
        delay = DELAY_CNT;
        while(delay) delay--;
        SCK_OUT(1);
        TxData |= MISO_IN();
        delay = DELAY_CNT;
        while(delay) delay--;
        SCK_OUT(0);
        delay = DELAY_CNT;
        while(delay) delay--;

    }
    return(TxData);


#endif
}
/*
*****************************************************************
* ��ʼ��
*****************************************************************
*/
void Init_NRF24L01(void)
{
    HAL_Delay(10);
    NRF_CE_LOW();
    SPI_NSS_HIGH();

    SPI_Write_Reg(RF_WRITE_REG + CONFIG, 0x0f);							// 20 CRCʹ�ܣ�16λCRCУ�飬�ϵ磬����ģʽ
    SPI_Write_Reg(RF_WRITE_REG + SETUP_AW, 0x01);						//23
    SPI_Write_Buf(RF_WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);	// д�뷢�͵�ַ
    SPI_Write_Buf(RF_WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH);	// 2A  Ϊ��Ӧ������豸������ͨ��0��ַ�ͷ��͵�ַ��ͬ
    SPI_Write_Reg(RF_WRITE_REG + EN_AA, 0x0);							// 21 ʹ�ܽ���ͨ��0�Զ�Ӧ��
    SPI_Write_Reg(RF_WRITE_REG + EN_RXADDR, 0x01);						// 22 ʹ�ܽ���ͨ��0

    SPI_Write_Reg(RF_WRITE_REG + RF_CH, 0x1e);							// 25 ѡ����Ƶͨ��0x40
    SPI_Write_Reg(RF_WRITE_REG + RX_PW_P0, NRF_FIFO_SIZE);				// 31 ����ͨ��0ѡ��ͷ���ͨ����ͬ��Ч���ݿ��

    SPI_Write_Reg(RF_WRITE_REG + RF_SETUP, 0x03);						// 26 ���ݴ�����2Mbps�����书��7dBm


    SPI_Write_Reg(RF_WRITE_REG + STATUS, 0x70);							// 27 ������е��жϱ�־λ
    SPI_Write_Reg(FLUSH_RX,0xff);										//���RX FIFO�Ĵ���


    NRF_CE_HIGH();
    HAL_Delay(10);
}

/*
*****************************************************************
* д�Ĵ���
*****************************************************************
*/
uint8_t wRegStat;
uint8_t SPI_Write_Reg(uint8_t reg, uint8_t value)
{

    SPI_NSS_LOW();                    /* ѡͨ���� */
    wRegStat = SPI_ReadWriteByte(reg);  /* д�Ĵ�����ַ */
    wRegStat = SPI_ReadWriteByte(value);         /* д���� */
    SPI_NSS_HIGH();                   /* ��ֹ������ */
    return  wRegStat;
}
/*
*****************************************************************
* ���Ĵ���
*****************************************************************
*/
uint8_t SPI_Read_Reg(uint8_t reg)
{
    uint8_t reg_val;
    SPI_NSS_LOW();                    /* ѡͨ���� */
    SPI_ReadWriteByte(reg);           /* д�Ĵ�����ַ */
    reg_val = SPI_ReadWriteByte(0);   /* ��ȡ�üĴ����������� */
    SPI_NSS_HIGH();                   /* ��ֹ������ */
    return  reg_val;
}
/*
*****************************************************************
*
* д������
*
*****************************************************************
*/

uint8_t wBufStat;
static uint8_t SPI_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t uchars)
{
    uint8_t i;

    SPI_NSS_LOW();                      /* ѡͨ���� */
    wBufStat = SPI_ReadWriteByte(reg);    /* д�Ĵ�����ַ */
    for(i=0; i<uchars; i++)
    {
        wBufStat = SPI_ReadWriteByte(pBuf[i]);     /* д���� */
    }
    SPI_NSS_HIGH();                     /* ��ֹ������ */
    return  wBufStat;
}
/*
*****************************************************************
* ��������
*****************************************************************
*/
static uint8_t SPI_Read_Buf(uint8_t reg, uint8_t *pBuf, uint8_t uchars)
{
    uint8_t i;
    uint8_t status;
    SPI_NSS_LOW();                      /* ѡͨ���� */
    status = SPI_ReadWriteByte(reg);    /* д�Ĵ�����ַ */
    for(i=0; i<uchars; i++)
    {
        pBuf[i] = SPI_ReadWriteByte(0); /* ��ȡ�������� */
    }
    SPI_NSS_HIGH();                     /* ��ֹ������ */
    return  status;
}


/*
*****************************************************************
* ����ģʽ
*****************************************************************
*/
void SetRX_Mode(void)
{
    NRF_CE_LOW();
    SPI_Write_Reg(RF_WRITE_REG + CONFIG, 0x0f);         // IRQ�շ�����ж���Ӧ��16λCRC ��������
    NRF_CE_HIGH();
}
/*
*****************************************************************
* ����ģʽ
*****************************************************************
*/
void SetTX_Mode(void)
{
    NRF_CE_LOW();
    SPI_Write_Reg(RF_WRITE_REG + CONFIG, 0x02);          // IRQ�շ�����ж���Ӧ��16λCRC��������
    NRF_CE_HIGH();
}
/*
*****************************************************************
* �����ݰ�
*****************************************************************
*/
uint8_t rRegStat=0;
uint8_t nRF24L01_RxPacket(uint8_t * rx_buf, uint8_t len)
{
    uint8_t revale=0;

    rRegStat = SPI_Read_Reg(STATUS); // ��ȡ״̬�Ĵ������ж����ݽ���״��

    gNrfReg.Rssi = SPI_Read_Reg(CD);

    if(rRegStat&0x40)                // �ж��Ƿ���յ�����
    {
        SPI_Read_Buf(RD_RX_PLOAD,rx_buf,len);// read receive payload from RX_FIFO buffer
        SPI_Write_Reg(FLUSH_RX,0xff);			//���RX FIFO
        revale =1;								//��ȡ������ɱ�־
    }
    SPI_Write_Reg(RF_WRITE_REG+STATUS,rRegStat);   //���յ����ݺ�RX_DR,TX_DS,MAX_PT���ø�Ϊ1��ͨ��д1������жϱ�־


    if(!gNrfReg.Rssi)
    {
        //memset(rx_buf, 0x00, len);
        //return 0;
    }


    return revale;
}
/*
*****************************************************************
* д���ݰ�
*****************************************************************
*/
void nRF24L01_TxPacket(uint8_t * tx_buf, uint8_t len)
{
    NRF_CE_LOW();        //StandBy Iģʽ

    SPI_Write_Buf(RF_WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // װ�ؽ��ն˵�ַ
    SPI_Write_Buf(WR_TX_PLOAD, tx_buf, len);             // װ������
//  SPI_RW_Reg(RF_WRITE_REG + CONFIG, 0x0e);         // IRQ�շ�����ж���Ӧ��16λCRC��������
    NRF_CE_HIGH();       //�ø�CE���������ݷ���
}


/*======================================================================*/

