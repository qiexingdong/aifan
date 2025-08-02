#ifndef __SHOCK_H__
#define __SHOCK_H__
#include "main.h"
#include "tim.h"

//结构体
typedef struct {
    uint8_t Motor;      //震动马达状态标志,0为关闭，1为开启
} MotorStatus;
extern volatile MotorStatus mot; // volatile保证多环境访问安全

void Motor_Init(void);
void Motor_ON(void);
void Motor_OFF(void);

#endif




