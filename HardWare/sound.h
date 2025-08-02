#ifndef __SOUND_H__
#define __SOUND_H__
#include "main.h"
#include "OLED.h"
#include "string.h"
#include "shock.h"

extern char voice[];
extern char shock[];

typedef struct {
    uint32_t seconds;  // 总倒计时秒数
    uint8_t is_running;      // 倒计时状态标志
} CountdownTimer;
extern volatile CountdownTimer cdt; // volatile保证多环境访问安全

void LM393_Run(void);



#endif
