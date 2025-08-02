#include "motor.h"
/**
* @description:电机初始化
* @return:无
*/
void Motor_Init(void)
{
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
}

/**
* @description:调整电机的正转/反转速度
* @return:无
*/
void Motor_SetSpeed(int8_t Speed) {
    if(Speed >= 0) {//电机正转
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,Speed);
    }
    else {//电机反转
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
        __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,-Speed) ;
    }
}
