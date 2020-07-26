#include "mpu6050.h"
#include "main.h"


#include "i2c.h"


#define delay_ms    HAL_Delay



uint8_t res;

uint8_t MPU_Init(void)
{
    mpu_write_byte(MPU_PWR_MGMT1_REG, 0X80);	//��λMPU6050
    delay_ms(100);
    mpu_write_byte(MPU_PWR_MGMT1_REG, 0X00);	//����MPU6050
    mpu_set_acc_gyro_fsr(3);					//�����Ǵ�����,��2000dps
    mpu_set_acc_fsr(0);					//���ٶȴ�����,��2g
    mpu_set_rate(50);						//���ò�����50Hz
    mpu_write_byte(MPU_INT_EN_REG, 0X00);	//�ر������ж�
    mpu_write_byte(MPU_USER_CTRL_REG, 0X00);	//I2C��ģʽ�ر�
    mpu_write_byte(MPU_FIFO_EN_REG, 0X00);	//�ر�FIFO
    mpu_write_byte(MPU_INTBP_CFG_REG, 0X80);	//INT���ŵ͵�ƽ��Ч
    res = mpu_read_byte(MPU_DEVICE_ID_REG);
    if(res == MPU_ADDR) //����ID��ȷ
    {
        mpu_write_byte(MPU_PWR_MGMT1_REG, 0X01);	//����CLKSEL,PLL X��Ϊ�ο�
        mpu_write_byte(MPU_PWR_MGMT2_REG, 0X00);	//���ٶ��������Ƕ�����
        mpu_set_rate(50);						//���ò�����Ϊ50Hz
    }
    else return 1;
    return 0;
}

//����MPU6050�����Ǵ����������̷�Χ
//fsr:0,��250dps;1,��500dps;2,��1000dps;3,��2000dps
uint8_t mpu_set_acc_gyro_fsr(uint8_t fsr)
{
    return mpu_write_byte(MPU_GYRO_CFG_REG, fsr << 3); //���������������̷�Χ
}

//����MPU6050���ٶȴ����������̷�Χ
//fsr:0,��2g;1,��4g;2,��8g;3,��16g
uint8_t mpu_set_acc_fsr(uint8_t fsr)
{
    return mpu_write_byte(MPU_ACCEL_CFG_REG, fsr << 3); //���ü��ٶȴ����������̷�Χ
}

//����MPU6050�����ֵ�ͨ�˲���
//lpf:���ֵ�ͨ�˲�Ƶ��(Hz)
uint8_t mpu_set_lpf_fyf(uint16_t lpf)
{
    uint8_t data = 0;
    if(lpf >= 188)data = 1;
    else if(lpf >= 98)data = 2;
    else if(lpf >= 42)data = 3;
    else if(lpf >= 20)data = 4;
    else if(lpf >= 10)data = 5;
    else data = 6;
    return mpu_write_byte(MPU_CFG_REG, data); //�������ֵ�ͨ�˲���
}

//����MPU6050�Ĳ�����(�ٶ�Fs=1KHz)
//rate:4~1000(Hz)
uint8_t mpu_set_rate(uint16_t rate)
{
    uint8_t data;
    if(rate > 1000)rate = 1000;
    if(rate < 4)rate = 4;
    data = 1000 / rate - 1;
    data = mpu_write_byte(MPU_SAMPLE_RATE_REG, data);	//�������ֵ�ͨ�˲���
    return mpu_set_lpf_fyf(rate / 2);	//�Զ�����LPFΪ�����ʵ�һ��
}

//�õ��¶�ֵ
//����ֵ:�¶�ֵ(������100��)
short mpu_get_temp(void)
{
    uint8_t buf[2];
    short raw;
    float temp;
    mpu_read_len(MPU_ADDR, MPU_TEMP_OUTH_REG, 2, buf);
    raw = ((uint16_t)buf[0] << 8) | buf[1];
    temp = 36.53 + ((double)raw) / 340;
    return temp * 100;;
}

//�õ�������ֵ(ԭʼֵ)
//gx,gy,gz:������x,y,z���ԭʼ����(������)
uint8_t mpu_get_gyro(short *gx, short *gy, short *gz)
{
    uint8_t buf[6], res;
    res = mpu_read_len(MPU_ADDR, MPU_GYRO_XOUTH_REG, 6, buf);
    if(res == 0)
    {
        *gx = ((uint16_t)buf[0] << 8) | buf[1];
        *gy = ((uint16_t)buf[2] << 8) | buf[3];
        *gz = ((uint16_t)buf[4] << 8) | buf[5];
    }
    return res;;
}

//�õ����ٶ�ֵ(ԭʼֵ)
//gx,gy,gz:������x,y,z���ԭʼ����(������)
uint8_t mpu_get_acc(float *ax, float *ay, float *az)
{
    uint8_t buf[6], res;
    res = mpu_read_len(MPU_ADDR, MPU_ACCEL_XOUTH_REG, 6, buf);
    if(res == 0)
    {
        *ax = ((uint16_t)buf[0] << 8) | buf[1];
        *ay = ((uint16_t)buf[2] << 8) | buf[3];
        *az = ((uint16_t)buf[4] << 8) | buf[5];
    }
    return res;;
}








/**
 *	������
 */



#define MPU_ADDR_READ	((MPU_ADDR<<1)|0)
#define MPU_ADDR_WRITE	((MPU_ADDR<<1)|1)

uint8_t mpu_write_len(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf)
{
    HAL_I2C_Mem_Write(&hi2c1, MPU_ADDR_WRITE, reg, I2C_MEMADD_SIZE_8BIT, buf, len, 1000);

    return 0;
}


uint8_t mpu_read_len(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf)
{
    HAL_I2C_Mem_Read(&hi2c1, MPU_ADDR_READ, reg, I2C_MEMADD_SIZE_8BIT, buf, len, 1000);

    return 0;
}


uint8_t mpu_write_byte(uint8_t reg, uint8_t data)
{
    HAL_I2C_Mem_Write(&hi2c1, MPU_ADDR_WRITE, reg, I2C_MEMADD_SIZE_8BIT, &data, 1, 1000);

    return 0;
}


uint8_t mpu_read_byte(uint8_t reg)
{
    uint8_t data = 0;

    HAL_I2C_Mem_Read(&hi2c1, MPU_ADDR_READ, reg, I2C_MEMADD_SIZE_8BIT, &data, 1, 1000);

    return data;
}




