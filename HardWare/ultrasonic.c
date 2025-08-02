//#include "ultrasonic.h"

//void SR04_Run(void){
//       //让计数器cnt置零
//        __HAL_TIM_SET_COUNTER(&htim1,0);
//        //清除cc1/cc2标志位
//        __HAL_TIM_CLEAR_FLAG(&htim1,TIM_FLAG_CC1);
//        __HAL_TIM_CLEAR_FLAG(&htim1,TIM_FLAG_CC2);
//        //启动输入捕获
//        HAL_TIM_IC_Start(&htim1,TIM_CHANNEL_1);
//        HAL_TIM_IC_Start(&htim1,TIM_CHANNEL_2);
//        //向trig发送脉冲
//        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET);
//        for(uint32_t i = 0; i < 10; i++);
//        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET);
//        //等待测量结束
//        uint8_t success  = 0;
//        uint32_t expireTime = HAL_GetTick() + 50;
//        while(expireTime > HAL_GetTick()) {
//            uint32_t cc1Flag = __HAL_TIM_GET_FLAG(&htim1,TIM_FLAG_CC1);
//            uint32_t cc2Flag = __HAL_TIM_GET_FLAG(&htim1,TIM_FLAG_CC2);
//            if(cc1Flag && cc2Flag) {
//                success = 1;
//                break;
//            }
//        }
//        //关闭定时器
//        HAL_TIM_IC_Stop(&htim1,TIM_CHANNEL_1);
//        HAL_TIM_IC_Stop(&htim1,TIM_CHANNEL_2);
//		float distance = 0;
//        //计算测量结果
//        if(success == 1) {
//            uint16_t ccr1 = __HAL_TIM_GET_COMPARE(&htim1,TIM_CHANNEL_1);
//            uint16_t ccr2 = __HAL_TIM_GET_COMPARE(&htim1,TIM_CHANNEL_2);
//            float fulseWidth = (ccr2-ccr1) * 1e-6f;
//            distance = 340.0f * fulseWidth / 2.0f;
//			if(distance < 0.2){
//			LED_PC13_On();
//			}
//			else{
//			LED_PC13_Off();
//			}
//		  OLED_Printf(0,0,8,"距离=%.2fcm               ",distance);
//        }
//		OLED_Update();
//}

