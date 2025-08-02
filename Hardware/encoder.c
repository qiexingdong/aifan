#include "encoder.h"


void Enoder_Init(void)
{
    HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_1);
    HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_2);
}

/**
* @description:����������ת��ת�Ĵ���
* @return:ÿ��תһ�Σ�����1��ÿ��תһ�Σ�����-1
*/
int8_t Enoder_Get(void)
{
    int16_t Temp = 0,cnt = 0;
    cnt = __HAL_TIM_GET_COUNTER(&htim3);
    cnt = cnt / 2;
	//У׼
    if(cnt > 1) {cnt = 1;}
    if(cnt < -1) {cnt = -1;}
	//�ж�
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
