#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "main.h"
#include "tim.h"
//结构体
typedef struct {
    uint8_t State;      // 蜂鸣器状态标志,0为关闭，1为开启
	uint32_t seconds;  // 总倒计时秒数
    uint8_t is_running;      // 倒计时状态标志
} BuzzerStatus;
extern volatile BuzzerStatus buz; // volatile保证多环境访问安全
void Buzzer_Init(void);
void Buzzer_ON(void);
void Buzzer_OFF(void);
void SetBuzz(uint8_t num);
#endif
