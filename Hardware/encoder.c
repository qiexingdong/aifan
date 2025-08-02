#include "encoder.h"


void Enoder_Init(void)
{
    HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_1);
    HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_2);
}

/**
* @description:检测编码器正转反转的次数
* @return:每正转一次，返回1；每反转一次，返回-1
*/
int8_t Enoder_Get(void)
{
    int16_t Temp = 0,cnt = 0;
    cnt = __HAL_TIM_GET_COUNTER(&htim3);
    cnt = cnt / 2;
	//校准
    if(cnt > 1) {cnt = 1;}
    if(cnt < -1) {cnt = -1;}
	//判断
    if(cnt== 1) {
        __HAL_TIM_SET_COUNTER(&htim3,0);
        Temp = 1;
    }
    if(cnt== -1) {
        __HAL_TIM_SET_COUNTER(&htim3,0);
        Temp = 3;
    }
    return Temp;
}
