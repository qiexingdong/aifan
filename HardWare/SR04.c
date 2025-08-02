#include "SR04.h"

char buzzer[] = "无";
float distance = 0;

/**
  * 函    数：开启超声波传感器
  * 参    数：无
  * 返 回 值：无
  * 注意事项：无
  */
void SR04_Run(void) {
    //让计数器cnt置零
    __HAL_TIM_SET_COUNTER(&htim1,0);
    //清除cc1/cc2标志位
    __HAL_TIM_CLEAR_FLAG(&htim1,TIM_FLAG_CC1);
    __HAL_TIM_CLEAR_FLAG(&htim1,TIM_FLAG_CC2);
    //启动输入捕获
    HAL_TIM_IC_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIM_IC_Start(&htim1,TIM_CHANNEL_2);
    //向trig发送脉冲
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET);
    for(uint32_t i = 0; i < 10; i++);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET);
    //等待测量结束
    uint8_t success  = 0;
    uint32_t expireTime = HAL_GetTick() + 50;
    while(expireTime > HAL_GetTick()) {
        uint32_t cc1Flag = __HAL_TIM_GET_FLAG(&htim1,TIM_FLAG_CC1);
        uint32_t cc2Flag = __HAL_TIM_GET_FLAG(&htim1,TIM_FLAG_CC2);
        if(cc1Flag && cc2Flag) {
            success = 1;
            break;
        }
    }
    //关闭定时器
    HAL_TIM_IC_Stop(&htim1,TIM_CHANNEL_1);
    HAL_TIM_IC_Stop(&htim1,TIM_CHANNEL_2);
    //计算测量结果
    if(success == 1) {
        uint16_t ccr1 = __HAL_TIM_GET_COMPARE(&htim1,TIM_CHANNEL_1);
        uint16_t ccr2 = __HAL_TIM_GET_COMPARE(&htim1,TIM_CHANNEL_2);
        float fulseWidth = (ccr2-ccr1) * 1e-6f;
        distance = 340.0f * fulseWidth / 2.0f;

        if (distance <= THRESHOLD_NEAR) {
            if (buz.State != 2) { // 状态从其他变为2
                buz.State = 2;
                buz.is_running = 0;
                buz.seconds = 1; // 初始化，确保首次触发
				HAL_TIM_Base_Start_IT(&htim2);
            }
        } else if (distance <= THRESHOLD_FAR) {
            if (buz.State != 1) { // 状态从其他变为1
                buz.State = 1;
                buz.is_running = 0;
                buz.seconds = 2; // 初始化
				HAL_TIM_Base_Start_IT(&htim2);
            }
        } else {
            if (buz.State != 0) { // 状态从其他变为0
                buz.State = 0;
                buz.is_running = 0;
                buz.seconds = 0;
            }
        }
        switch(buz.State) {
        case 0:
            LED_PA5_Off();
            strcpy(buzzer,"无");
            break;
        case 1:
            LED_PA5_On();
            strcpy(buzzer,"有");
            break;
        case 2:
            LED_PA5_On();
            strcpy(buzzer,"有");
            break;
        }
    }
    OLED_Printf(0,0,8,"距离:%.2fm               ",distance);
    OLED_Printf(0,16,8,"蜂鸣器:%s               ",buzzer);
    OLED_Update();
}
