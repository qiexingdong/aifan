#ifndef __MENU_H__
#define __MENU_H__

#include "OLED.h"
#include "key.h"
#include "motor.h"
#include "encoder.h"
#include "stdio.h"
#include "string.h"
#include "dht11.h"

//全局变量
extern int8_t KeyNum;					           	 //独立按键和旋转编码器按键的键码
extern int Hour,Min,Sec;                             //定时模式所需的时分秒变量
extern int8_t Motor_Speed;					         //电机当前转速
extern uint8_t countdown_active; 			   	     //倒计时标志
extern char lock[];                                  //字符串
extern uint8_t lock_flag;                            //电机锁定标志
extern uint16_t temperature;						 //温度
extern uint16_t humidity;							 //湿度
extern uint8_t timer1s_flag;                         // 设置1秒标志位
//结构体
typedef struct {
    uint32_t total_seconds;  // 总倒计时秒数
    uint32_t remaining;      // 剩余秒数
    uint8_t is_running;      // 倒计时状态标志
} CountdownTimer;
extern volatile CountdownTimer cdt; // volatile保证多环境访问安全

//一级菜单
void menu1(void);
//二级菜单
int menu21(void);
int menu22(void);
int menu23(void);
//三级菜单
int menu3_SetHour(void);
int menu3_SetMin(void);
int menu3_SetSec(void);
int menu3_SetSpeed(void);
int menu3_Start(void);
int menu3_ControlTemperature(void);
int menu3_ControlHumidity(void);
//开启计时函数
void StartCountdown(uint8_t hours, uint8_t minutes, uint8_t seconds);
//暂停倒计时
void PauseCountdown(void);

#endif
