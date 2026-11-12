#include "PID.h"

PID::PID()
{
}

void PID::setup(float gains[3], float dt)
{
    _kp = gains[0];
    _ki = gains[1];
    _kd = gains[2];
    _dt = dt;
}

float PID::calculate(float error)
{
    float p = _kp * error; // integral term = y[n] = y[n-1] +(dt/2)(e[n]+e[n-1])
    _integral += _dt * (error + _prev_error) / 2.0f;
    u += _ki * _integral;
    u += _kd * (error - _prev_error) / _dt;
    
    float max_duty = 100.0f;
    float min_duty = 0.0f;

    if( u <= min_duty){
        u = 0;
    } else if (u >= max_duty){
        u = 100;
    }

    _prev_error = error;
    return u;
}
