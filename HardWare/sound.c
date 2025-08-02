#include "sound.h"

char voice[] = "无";
char shock[] = "无";
volatile CountdownTimer cdt;
/**
  * 函    数：开启声音传感器
  * 参    数：无
  * 返 回 值：无
  * 注意事项：无
  */
void LM393_Run(void) {
    if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == GPIO_PIN_RESET) {
		cdt.is_running = 1;
		cdt.seconds = 2;
		__HAL_TIM_SET_COUNTER(&htim4, 0);//定时器置零
        HAL_TIM_Base_Start_IT(&htim4);//开始3秒的马达震动
        strcpy(voice,"有");
        strcpy(shock,"有");
        Motor_ON();
    }
    else {
		if(cdt.is_running == 0){
		strcpy(voice,"无");
        strcpy(shock,"无");
        Motor_OFF();
		}
    }
//		OLED_Printf(0,48,8,"震动马达:%s               ",shock);
        OLED_Printf(0,32,8,"异常声音:%s               ",voice);
        OLED_Update();
}
