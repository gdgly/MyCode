#ifndef PID_H_
#define PID_H_

#include "main.h"

typedef struct
{
    float kp;
    float ki;
    float kd;

    float ep;
    float ei;
    float ed;

    float ep_old;

    float ei_max_val;//限制ei的最大值

    float val;//返回值


} PID_TYPE;

extern PID_TYPE pid_l;
extern PID_TYPE pid_r;
extern PID_TYPE pid_balance;


void pid_init(PID_TYPE *pid, float kp, float ki, float kd, float ei_max_val);
float pid_calc(PID_TYPE *pid, float get, float set);


#endif








