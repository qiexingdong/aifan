#include "buzzer.h"

volatile BuzzerStatus buz;

void Buzzer_Init(void) {
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);    
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,100);
}
void Buzzer_ON(void) {
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,10);
}
void Buzzer_OFF(void) {
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,100);
}
void SetBuzz(uint8_t num){
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,num);
}
