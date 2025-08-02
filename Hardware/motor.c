#include "motor.h"
/**
* @description:�����ʼ��
* @return:��
*/
void Motor_Init(void)
{
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
}

/**
* @description:�����������ת/��ת�ٶ�
* @return:��
*/
void Motor_SetSpeed(int8_t Speed) {
    if(Speed >= 0) {//�����ת
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,Speed);
    }
    else {//�����ת
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
        __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,-Speed) ;
    }
}
