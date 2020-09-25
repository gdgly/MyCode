
#include "test.h"
#include "tool.h"
#include "pid.h"





#define EI_MAX_VAL	5000

//float Kp = 20.0;
//float Ki = 10.0;
//float Kd = 5.0;


//float Ep = 0.0;
//float Ei = 0.0;
//float Ed = 0.0;

//float Ep_old = 0.0;




//float pid_val = 0;




PID_TYPE pid_l;
PID_TYPE pid_r;
PID_TYPE pid_balance;

void pid_init(PID_TYPE *pid, float kp, float ki, float kd, float ei_max_val)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;

    pid->ei_max_val = ei_max_val;
}


float pid_calc(PID_TYPE *pid, float get, float set)
{
    pid->ep = set - get;
    pid->ei += pid->ep;
    pid->ed = pid->ep - pid->ep_old;

    pid->ep_old = pid->ep;
    if(pid->ei > pid->ei_max_val)
    {
        pid->ei = pid->ei_max_val;
    }
    if(pid->ei < -pid->ei_max_val)
    {
        pid->ei = -pid->ei_max_val;
    }


    pid->val = (pid->kp * pid->ep) + (pid->ki * pid->ei) + (pid->kd * pid->ed);

//    if(pid->val < 0)
//    {
//        pid->val = 0;
//    }
//    if(pid->val > 7000)
//    {
//        pid->val = 7000;
//    }
    return pid->val;

}


