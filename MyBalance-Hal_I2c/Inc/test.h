#ifndef TEST_H_
#define TEST_H_

#include "main.h"

#define MOTO_DIR_PORT GPIOB

#define B1 GPIO_PIN_13
#define B2 GPIO_PIN_12
#define A1 GPIO_PIN_14
#define A2 GPIO_PIN_15

#define LEFT	1
#define RIGHT	2


#define Task_1000ms	1000
#define Task_500ms	500
#define Task_200ms	200
#define Task_100ms	100
#define Task_50ms	50
#define Task_20ms	20
#define Task_10ms	10







typedef struct
{
    uint16_t PowerUpCnt;

    uint16_t	t_1000ms;
    uint16_t	t_500ms;
    uint16_t	t_200ms;
    uint16_t	t_100ms;
    uint16_t	t_50ms;
    uint16_t	t_20ms;
    uint16_t	t_10ms;

} TASK_TYPE;



typedef struct
{
    short pwm_max_cnt;	//pwm的最大输出值
    short pwm_cnt;		//设置pwm的输出值
    short pwm_old_cnt;

    short encoder_cnt;	//编码器计数值

    int speed_set;
    int speed_get;
    uint8_t direction;		//电机旋转方向，按照小车的前后方向

} MOTO_TYPE;

extern MOTO_TYPE gMotor_l;
extern MOTO_TYPE gMotor_r;

extern TASK_TYPE gTaskReg;




void get_angle(uint8_t way);
void moto_get_speed(uint8_t flag);

void moto_dir_ctrl(uint8_t left_flag, uint8_t right_flag);

void moto_set_pwm_cnt(uint8_t n, uint16_t cnt);



void balance_ctrl(float roll, float gyro);
void speed_ctrl(void);

#endif



