
#include "test.h"

TASK_TYPE gTaskReg;
MOTO_TYPE gMotor_l;
MOTO_TYPE gMotor_r;


void moto_l_forward(void)
{
    HAL_GPIO_WritePin(MOTO_DIR_PORT, B1, GPIO_PIN_SET);
    HAL_GPIO_WritePin(MOTO_DIR_PORT, B2, GPIO_PIN_RESET);
}

void moto_l_back(void)
{
    HAL_GPIO_WritePin(MOTO_DIR_PORT, B1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTO_DIR_PORT, B2, GPIO_PIN_SET);
}


void moto_r_forward(void)
{
    HAL_GPIO_WritePin(MOTO_DIR_PORT, A1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTO_DIR_PORT, A2, GPIO_PIN_SET);
}

void moto_r_back(void)
{
    HAL_GPIO_WritePin(MOTO_DIR_PORT, A1, GPIO_PIN_SET);
    HAL_GPIO_WritePin(MOTO_DIR_PORT, A2, GPIO_PIN_RESET);

}

//����1��LEFT/RIGHT
//����2��pwmֵ
void moto_set_pwm_cnt(uint8_t flag, uint16_t cnt)
{

    TIM_OC_InitTypeDef sConfigOC = {0};

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = cnt;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
    sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;

    if(flag == LEFT)
    {
        if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
        {
            Error_Handler();
        }
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
    }
    else if(flag == RIGHT)
    {
        if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
        {
            Error_Handler();
        }
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    }

}



void moto_get_speed(uint8_t flag)
{
    if(flag == LEFT)
    {
        gMotor_l.encoder_cnt = TIM2->CNT;
        TIM2->CNT = 0;
        gMotor_l.speed_get = gMotor_l.encoder_cnt;
    }
    else
    {
        gMotor_r.encoder_cnt = TIM4->CNT;
        TIM4->CNT = 0;
        gMotor_r.speed_get = gMotor_r.encoder_cnt;


    }
}


void get_angle(uint8_t way)
{
//	float Accel_x,Accel_Y,Accel_Z;
//	float Gyro_X,Gyro_X,Gyro_X;

    if(way==1)                           //===DMP�Ķ�ȡ�����ݲɼ��ж϶�ȡ���ϸ���ѭʱ��Ҫ��
    {
        //Read_DMP();                      //===��ȡ���ٶȡ����ٶȡ����
    }
    else
    {
//        Gyro_X=(I2C_ReadOneByte(devAddr,MPU6050_RA_GYRO_XOUT_H)<<8)+I2C_ReadOneByte(devAddr,MPU6050_RA_GYRO_XOUT_L);    //��ȡY��������
//        Gyro_Z=(I2C_ReadOneByte(devAddr,MPU6050_RA_GYRO_ZOUT_H)<<8)+I2C_ReadOneByte(devAddr,MPU6050_RA_GYRO_ZOUT_L);    //��ȡZ��������
//        Accel_Y=(I2C_ReadOneByte(devAddr,MPU6050_RA_ACCEL_YOUT_H)<<8)+I2C_ReadOneByte(devAddr,MPU6050_RA_ACCEL_YOUT_L); //��ȡX����ٶȼ�
//        Accel_Z=(I2C_ReadOneByte(devAddr,MPU6050_RA_ACCEL_ZOUT_H)<<8)+I2C_ReadOneByte(devAddr,MPU6050_RA_ACCEL_ZOUT_L); //��ȡZ����ٶȼ�
//        if(Gyro_X>32768)  Gyro_X-=65536;                       //��������ת��  Ҳ��ͨ��shortǿ������ת��
//        if(Gyro_Z>32768)  Gyro_Z-=65536;                       //��������ת��
//        if(Accel_Y>32768) Accel_Y-=65536;                      //��������ת��
//        if(Accel_Z>32768) Accel_Z-=65536;                      //��������ת��

//		  Gyro_Balance=Gyro_X;                                  //����ƽ����ٶ�
//        Accel_Angle=atan2(Accel_Y,Accel_Z)*180/PI;                 //�������
//        Gyro_X=Gyro_X/16.4;                                    //����������ת��
//        if(Way_Angle==2)		  	Kalman_Filter(Accel_Angle,Gyro_X);//�������˲�
//        else if(Way_Angle==3)   Yijielvbo(Accel_Angle,Gyro_X);    //�����˲�
//        Angle_Balance=angle;                                   //����ƽ�����
//        Gyro_Turn=Gyro_Z;                                      //����ת����ٶ�
//        Acceleration_Z=Accel_Z;                                //===����Z����ٶȼ�


        gMpu.gyro.x = (short)gMpu.gyro.x;
        gMpu.gyro.y = (short)gMpu.gyro.y;
        gMpu.gyro.z = (short)gMpu.gyro.z;


        gMpu.accel.x = (short)gMpu.accel.x;
        gMpu.accel.y = (short)gMpu.accel.y;
        gMpu.accel.z = (short)gMpu.accel.z;



        gMpu.gyro.balance = gMpu.gyro.x;
        gMpu.accel.balance = atan2(gMpu.accel.y, gMpu.accel.z)*180.0/3.14159;
        gMpu.gyro.x = gMpu.gyro.x/16.4;

        Kalman_Filter(gMpu.accel.balance, gMpu.gyro.x);

        gMpu.balance_angle = angle;
        gMpu.gyro.turn = gMpu.gyro.z;
        gMpu.accel.balance = gMpu.accel.z;


    }
}


void moto_dir_ctrl(uint8_t left_flag, uint8_t right_flag)
{
    if(left_flag)
    {
        moto_l_forward();
    }
    else
    {
        moto_l_back();
    }


    if(right_flag)
    {
        moto_r_forward();
    }
    else
    {
        moto_r_back();
    }
}


float roll_offset = 0.9;
float balance_pwm;
float debug_balance_pwm;

void balance_ctrl(float roll, float gyro)
{

    pid_balance.ep = roll_offset - roll;
    pid_balance.ed = gyro;



    balance_pwm = pid_balance.kp * pid_balance.ep - pid_balance.kd * pid_balance.ed;

    //balance_pwm = debug_balance_pwm;



    gMotor_r.pwm_cnt = balance_pwm;
    gMotor_l.pwm_cnt = balance_pwm;



}

float speed_pwm_l = 0.0;
float speed_pwm_r = 0.0;
float speed_sum = 0;
float speed_least = 0;

void speed_ctrl(void)
{
    speed_least = gMotor_l.speed_get + gMotor_r.speed_get;
    speed_sum *= 0.7;
    speed_sum += speed_least * 0.3;

    gMotor_l.speed_set = 0;
    gMotor_r.speed_set = 0;

    speed_pwm_l = pid_calc(&pid_l, speed_sum, gMotor_l.speed_set);
    speed_pwm_r = pid_calc(&pid_r, speed_sum, gMotor_r.speed_set);


    gMotor_l.pwm_cnt += speed_pwm_l;
    gMotor_r.pwm_cnt += speed_pwm_r;




}

