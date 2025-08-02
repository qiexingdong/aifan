#include "menu.h"

int8_t KeyNum = 0;					           	 //独立按键和旋转编码器按键的键码
int Hour = 0,Min = 0,Sec = 0;                            //定时模式所需的时分秒变量
int8_t Motor_Speed = 50;					 //电机当前转速
uint8_t countdown_active = 0; 			   	 //倒计时标志
char lock[] = "旋钮可调";                    //字符串
uint8_t lock_flag= 0;                        //电机锁定标志
uint16_t temperature;						 //温度
uint16_t humidity;							 //湿度
uint8_t timer1s_flag = 0;                        // 设置1秒标志位
volatile CountdownTimer cdt;                 // volatile保证多环境访问安全

/*----------------------------------一 级 菜 单------------------------------------------*/
/**
* @description:主菜单界面
* @return:
*/
void menu1(void) {
    int menu2 = 0;
    uint8_t flag = 1;
    while(1) {
        KeyNum = Key_GetNum();
        if(KeyNum == 1) {//上移
            flag--;
            if(flag == 0) {
                flag = 3;
            }
        }
        if(KeyNum == 3) {//下移
            flag++;
            if(flag == 4) {
                flag = 1;
            }
        }
        if(KeyNum == 2) {//确认
            OLED_Clear();
            OLED_Update();
            menu2 = flag;
        }

        if(menu2 == 1) {
            Hour = 0;
            Sec = 0;
            Min = 0;                                       //重置时分秒
            Motor_Speed = 50;                              //重置电机速度
            menu2 = menu21();
        }
        if(menu2 == 2) {
            strcpy(lock,"旋钮可调");
            lock_flag = 0;
            Motor_Speed = 20;                             //重置电机速度
            menu2 = menu22();
        }
        if(menu2 == 3) {
            Motor_Speed = 0;                             //重置电机速度
            menu2 = menu23();
        }
        switch(flag) {
        case 1: {
            OLED_ShowString(0,0,"     主菜单                ",8);
            OLED_ShowString(0,16,"定时模式               ",8);
            OLED_ShowString(0,32,"手动模式               ",8);
            OLED_ShowString(0,48,"自动模式               ",8);
            OLED_ReverseArea(0,16,128,16);
            OLED_Update();
            break;
        }
        case 2: {
            OLED_ShowString(0,0,"     主菜单                ",8);
            OLED_ShowString(0,16,"定时模式               ",8);
            OLED_ShowString(0,32,"手动模式               ",8);
            OLED_ShowString(0,48,"自动模式               ",8);
            OLED_ReverseArea(0,32,128,16);
            OLED_Update();
            break;
        }
        case 3:
            OLED_ShowString(0,0,"     主菜单                ",8);
            OLED_ShowString(0,16,"定时模式               ",8);
            OLED_ShowString(0,32,"手动模式               ",8);
            OLED_ShowString(0,48,"自动模式               ",8);
            OLED_ReverseArea(0,48,128,16);
            OLED_Update();
            break;

        }
    }

}
/*---------------------------------二 级 菜 单-----------------------------------------*/
/**
* @description:定时模式界面
* @return:
*/
int menu21(void) {
    int menu3 = 0;
    uint8_t flag = 1;
    while(1) {
        KeyNum = Key_GetNum();
        if(KeyNum == 1) {//上移
            flag--;
            if(flag == 0) {
                flag = 6;
            }
        }
        if(KeyNum == 3) {//下移
            flag++;
            if(flag == 7) {
                flag = 1;
            }
        }
        if(KeyNum == 2) {//确认
            OLED_Clear();
            OLED_Update();
            menu3 = flag;
        }

        //进入三级菜单
        if(menu3 == 1) {
            return 0;//返回一级菜单
        }
        if(menu3 == 2) {
            menu3 = menu3_SetHour();
        }
        if(menu3 == 3) {
            menu3 = menu3_SetMin();
        }
        if(menu3 == 4) {
            menu3 = menu3_SetSec();
        }
        if(menu3 == 5) {
            menu3 = menu3_SetSpeed();
        }
        if(menu3 == 6) {
            menu3 =  menu3_Start();
        }
        //高亮
        OLED_Clear();
        switch(flag) {
        case 1:
            OLED_ShowString(0,0,"  返回                ",8);
            OLED_Printf(0,16,8,"设置小时:%d               ",Hour);
            OLED_Printf(0,32,8,"设置分钟:%d               ",Min);
            OLED_Printf(0,48,8,"设置秒:  %d               ",Sec);
            OLED_ReverseArea(0,0,64,16);
            OLED_Update();
            break;
        case 2:
            OLED_ShowString(0,0,"  返回                ",8);
            OLED_Printf(0,16,8,"设置小时:%d               ",Hour);
            OLED_Printf(0,32,8,"设置分钟:%d               ",Min);
            OLED_Printf(0,48,8,"设置秒:  %d               ",Sec);
            OLED_ReverseArea(0,16,64,16);
            OLED_Update();
            break;
        case 3:
            OLED_ShowString(0,0,"  返回                ",8);
            OLED_Printf(0,16,8,"设置小时:%d               ",Hour);
            OLED_Printf(0,32,8,"设置分钟:%d               ",Min);
            OLED_Printf(0,48,8,"设置秒:  %d               ",Sec);
            OLED_ReverseArea(0,32,64,16);
            OLED_Update();
            break;
        case 4:
            OLED_ShowString(0,0,"  返回                ",8);
            OLED_Printf(0,16,8,"设置小时:%d               ",Hour);
            OLED_Printf(0,32,8,"设置分钟:%d               ",Min);
            OLED_Printf(0,48,8,"设置秒:  %d               ",Sec);
            OLED_ReverseArea(0,48,64,16);
            OLED_Update();
            break;
        case 5:
            OLED_Printf(0,0,8,"设置转速:%d               ",Motor_Speed);
            OLED_ShowString(0,16,"  确定              ",8);
            OLED_ReverseArea(0,0,64,16);
            OLED_Update();
            break;
        case 6:
            OLED_Printf(0,0,8,"设置转速:%d               ",Motor_Speed);
            OLED_ShowString(0,16,"  确定              ",8);
            OLED_ReverseArea(0,16,64,16);
            OLED_Update();
            break;
        }
    }
}
/**
* @description:手动模式界面
* @return:
*/
int menu22(void) {
    int menu3 = 0;
    uint8_t flag = 1;
    while(1) {
        KeyNum = Enoder_Get();
        if(KeyNum == 1 && lock_flag == 0) {
            Motor_Speed++;
        }
        if(KeyNum == 3 && lock_flag == 0) {
            Motor_Speed--;
        }

        KeyNum = Key_GetNum();
        if(KeyNum == 1) {//上移
            flag--;
            if(flag == 0) {
                flag = 2;
            }
        }
        if(KeyNum == 3) {//下移
            flag++;
            if(flag == 3) {
                flag = 1;
            }
        }
        if(KeyNum == 2) {//确认
            OLED_Clear();
            OLED_Update();
            menu3 = flag;
        }

        //结束二级菜单
        if(menu3 == 1) {
            Motor_SetSpeed(0);
            return 0;//返回一级菜单
        }
        if(menu3 == 2) {
            //menu3 = menu3_Lock();
            if(lock_flag == 0) {
                strcpy(lock,"旋钮锁定");
                lock_flag = 1;
            } else if(lock_flag == 1) {
                strcpy(lock,"旋钮可调");
                lock_flag = 0;
            }
            menu3 = 0;
        }
        //高亮
        switch(flag) {
        case 1:
            OLED_ShowString(0,0,"  返回                ",8);
            OLED_Printf(0,16,8,"%s               ",lock);
            OLED_Printf(0,48,8,"设置转速:%d               ",Motor_Speed);
            OLED_ReverseArea(0,0,64,16);
            OLED_Update();
            break;
        case 2:
            OLED_ShowString(0,0,"  返回                ",8);
            OLED_Printf(0,16,8,"%s               ",lock);
            OLED_Printf(0,48,8,"设置转速:%d               ",Motor_Speed);
            OLED_ReverseArea(0,16,64,16);
            OLED_Update();
            break;
        }
        Motor_SetSpeed(Motor_Speed);
    }
}
/**
* @description:自动模式界面
* @return:
*/
int menu23(void) {
    int menu3 = 0;
    uint8_t flag = 1;
    while(1) {
        KeyNum = Key_GetNum();
        if(KeyNum == 1) {//上移
            flag--;
            if(flag == 0) {
                flag = 3;
            }
        }
        if(KeyNum == 3) {//下移
            flag++;
            if(flag == 4) {
                flag = 1;
            }
        }

        if(KeyNum == 2) {//确认
            OLED_Clear();
            OLED_Update();
            menu3 = flag;
        }

        //结束二级菜单
        if(menu3 == 1) {
            return 0;//返回一级菜单
        }
        //进入三级菜单
        if(menu3 == 2) {
            menu3 = menu3_ControlTemperature();
        }
        if(menu3 == 3) {
            menu3 = menu3_ControlHumidity();
        }
        //高亮
        switch(flag) {
        case 1:
            OLED_ShowString(0,0,"  返回                ",8);
            OLED_ShowString(0,16,"温度控制               ",8);
            OLED_ShowString(0,32,"湿度控制               ",8);
            OLED_ReverseArea(0,0,64,16);
            OLED_Update();
            break;
        case 2:
            OLED_ShowString(0,0,"  返回                ",8);
            OLED_ShowString(0,16,"温度控制               ",8);
            OLED_ShowString(0,32,"湿度控制               ",8);
            OLED_ReverseArea(0,16,64,16);
            OLED_Update();
            break;
        case 3:
            OLED_ShowString(0,0,"  返回                ",8);
            OLED_ShowString(0,16,"温度控制               ",8);
            OLED_ShowString(0,32,"湿度控制               ",8);
            OLED_ReverseArea(0,32,64,16);
            OLED_Update();
            break;
        }
    }
}
/*---------------------------------三 级 菜 单-----------------------------------------*/
/**
* @description:设置小时
* @return:
*/
int menu3_SetHour(void) {

    while(1) {
        KeyNum = Enoder_Get();
        if(KeyNum == 3) {//减少
            Hour--;
            if(Hour <= -1) {
                Hour = 24;
            }
        }
        if(KeyNum == 1) {//增加
            Hour++;
            if(Hour >= 25) {
                Hour = 0;
            }
        }
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//确认
			OLED_Clear();
            OLED_Update();
            return 0;
        }
        OLED_ShowString(0,0,"  返回                ",8);
        OLED_Printf(0,16,8,"设置小时:%d               ",Hour);
        OLED_Printf(0,32,8,"设置分钟:%d               ",Min);
        OLED_Printf(0,48,8,"设置秒:  %d               ",Sec);
        if(Hour<10) {
            OLED_ReverseArea(72,16,8,16);
        } else {
            OLED_ReverseArea(72,16,16,16);
        }
        OLED_Update();
    }

}
/**
* @description:设置分钟
* @return:
*/
int menu3_SetMin(void) {
    while(1) {
        KeyNum = Enoder_Get();
        if(KeyNum == 3) {//减少
            Min--;
            if(Min <= -1) {
                Min = 60;
            }
        }
        if(KeyNum == 1) {//增加
            Min++;
            if(Min >= 61) {
                Min = 0;
            }
        }
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//确认
            return 0;
        }
        OLED_ShowString(0,0,"  返回                ",8);
        OLED_Printf(0,16,8,"设置小时:%d               ",Hour);
        OLED_Printf(0,32,8,"设置分钟:%d               ",Min);
        OLED_Printf(0,48,8,"设置秒:  %d               ",Sec);
        if(Min<10) {
            OLED_ReverseArea(72,32,8,16);
        } else {
            OLED_ReverseArea(72,32,16,16);
        }
        OLED_Update();
    }
}
/**
* @description:设置秒
* @return:
*/
int  menu3_SetSec(void) {
    while(1) {
        KeyNum = Enoder_Get();
        if(KeyNum == 3) {//减少
            Sec--;
            if(Sec <= -1) {
                Sec = 60;
            }
        }
        if(KeyNum == 1) {//增加
            Sec++;
            if(Sec >= 61) {
                Sec = 0;
            }
        }
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//确认
            return 0;
        }
        OLED_ShowString(0,0,"  返回                ",8);
        OLED_Printf(0,16,8,"设置小时:%d               ",Hour);
        OLED_Printf(0,32,8,"设置分钟:%d               ",Min);
        OLED_Printf(0,48,8,"设置秒:  %d               ",Sec);
        if(Sec<10) {
            OLED_ReverseArea(72,48,8,16);
        } else {
            OLED_ReverseArea(72,48,16,16);
        }
        OLED_Update();
    }
}
/**
* @description:设置速度
* @return:
*/
int menu3_SetSpeed(void) {
    while(1) {
        KeyNum = Enoder_Get();
        if(KeyNum == 3) {//减少
            Motor_Speed--;
            if(Motor_Speed <= -1) {
                Motor_Speed = 0;
            }
        }
        if(KeyNum == 1) {//增加
            Motor_Speed++;
            if(Motor_Speed >= 101) {
                Motor_Speed = 100;
            }
        }
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//确认
            return 0;
        }
        OLED_Printf(0,0,8,"设置转速:%d               ",Motor_Speed);
        OLED_ShowString(0,16,"  确定              ",8);
        if(Motor_Speed<10) {
            OLED_ReverseArea(72,0,8,16);
        } else if(Motor_Speed < 100) {
            OLED_ReverseArea(72,0,16,16);
        } else {
            OLED_ReverseArea(72,0,24,16);
        }
        OLED_Update();
    }
}
/**
* @description:倒计时功能
* @return:
*/
int menu3_Start(void) {
    if(Hour > 0 || Sec > 0||Min > 0) {
        StartCountdown(Hour,Sec,Min);
        Motor_SetSpeed(Motor_Speed);
    } else {
        PauseCountdown();
    }
    while(1) {
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//确认
            PauseCountdown();
            return 0;
        }
        OLED_ShowString(0,0,"  返回              ",8);
        OLED_ShowString(0,16,"剩余时间:",8);
        OLED_Printf(0,32,8,"%d:%d:%d              ",Hour,Min,Sec);
        OLED_Printf(0,48,8,"转速:%d              ",Motor_Speed);
        OLED_ReverseArea(0,0,64,16);
        OLED_Update();
    }

}
/**
* @description:开启计时函数
* @return:
*/
void StartCountdown(uint8_t hours, uint8_t minutes, uint8_t seconds) {
    cdt.total_seconds = Hour * 3600 + Min * 60 + Sec;
    cdt.remaining = cdt.total_seconds;
    cdt.is_running = 1; // 启动标志
    // 启动定时器（假设使用TIM4，需配置为1秒中断一次）
    __HAL_TIM_SET_COUNTER(&htim4, 0);//定时器置零
    HAL_TIM_Base_Start_IT(&htim4);
}
/**
* @description:暂停倒计时
* @return:
*/
void PauseCountdown(void) {
    Motor_SetSpeed(0);
    cdt.is_running = 0;
	HAL_TIM_Base_Stop_IT(&htim4); // 停止定时器
}
/**
* @description:获取温度
* @return:
*/
int menu3_ControlTemperature(void) {
    __HAL_TIM_SET_COUNTER(&htim4, 0);   //定时器置零
    HAL_TIM_Base_Start_IT(&htim4);		//定时器开启
    while(1) {
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//确认
            OLED_Clear();
            OLED_Update();
            Motor_SetSpeed(0);
            HAL_TIM_Base_Stop_IT(&htim4);//定时器停止
            return 0;
        }
        if(timer1s_flag == 1) {
            timer1s_flag = 0;
            DHT11_Read_Data(&temperature,&humidity);
        }
        Motor_Speed = temperature>>8;
        OLED_ShowString(0,0,"  返回                ",8);
        OLED_Printf(0,16,8,"温度:%d.%d               ",temperature>>8,temperature&0xff);
        OLED_Printf(0,48,8,"转速:%d               ",Motor_Speed);
        OLED_ReverseArea(0,0,64,16);
        OLED_Update();
        Motor_SetSpeed(Motor_Speed);
    }
}
/**
* @description:获取湿度
* @return:
*/
int menu3_ControlHumidity(void) {
    __HAL_TIM_SET_COUNTER(&htim4, 0);   //定时器置零
    HAL_TIM_Base_Start_IT(&htim4);
    while(1) {
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//确认
            OLED_Clear();
            OLED_Update();
            Motor_SetSpeed(0);
            HAL_TIM_Base_Stop_IT(&htim4);
            return 0;
        }
        if(timer1s_flag == 1) {
            timer1s_flag = 0;
            DHT11_Read_Data(&temperature,&humidity);
        }
        Motor_Speed = humidity>>8;
        OLED_ShowString(0,0,"  返回                ",8);
        OLED_Printf(0,16,8,"湿度:%d.%d               ",humidity>>8,humidity&0xff);
        OLED_Printf(0,48,8,"转速:%d               ",Motor_Speed);
        OLED_ReverseArea(0,0,64,16);
        OLED_Update();
        Motor_SetSpeed(Motor_Speed);
    }
}



