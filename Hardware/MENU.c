#include "menu.h"

int8_t KeyNum = 0;					           	 //������������ת�����������ļ���
int Hour = 0,Min = 0,Sec = 0;                            //��ʱģʽ�����ʱ�������
int8_t Motor_Speed = 50;					 //�����ǰת��
uint8_t countdown_active = 0; 			   	 //����ʱ��־
char lock[] = "��ť�ɵ�";                    //�ַ���
uint8_t lock_flag= 0;                        //���������־
uint16_t temperature;						 //�¶�
uint16_t humidity;							 //ʪ��
uint8_t timer1s_flag = 0;                        // ����1���־λ
volatile CountdownTimer cdt;                 // volatile��֤�໷�����ʰ�ȫ

/*----------------------------------һ �� �� ��------------------------------------------*/
/**
* @description:���˵�����
* @return:
*/
void menu1(void) {
    int menu2 = 0;
    uint8_t flag = 1;
    while(1) {
        KeyNum = Key_GetNum();
        if(KeyNum == 1) {//����
            flag--;
            if(flag == 0) {
                flag = 3;
            }
        }
        if(KeyNum == 3) {//����
            flag++;
            if(flag == 4) {
                flag = 1;
            }
        }
        if(KeyNum == 2) {//ȷ��
            OLED_Clear();
            OLED_Update();
            menu2 = flag;
        }

        if(menu2 == 1) {
            Hour = 0;
            Sec = 0;
            Min = 0;                                       //����ʱ����
            Motor_Speed = 50;                              //���õ���ٶ�
            menu2 = menu21();
        }
        if(menu2 == 2) {
            strcpy(lock,"��ť�ɵ�");
            lock_flag = 0;
            Motor_Speed = 20;                             //���õ���ٶ�
            menu2 = menu22();
        }
        if(menu2 == 3) {
            Motor_Speed = 0;                             //���õ���ٶ�
            menu2 = menu23();
        }
        switch(flag) {
        case 1: {
            OLED_ShowString(0,0,"     ���˵�                ",8);
            OLED_ShowString(0,16,"��ʱģʽ               ",8);
            OLED_ShowString(0,32,"�ֶ�ģʽ               ",8);
            OLED_ShowString(0,48,"�Զ�ģʽ               ",8);
            OLED_ReverseArea(0,16,128,16);
            OLED_Update();
            break;
        }
        case 2: {
            OLED_ShowString(0,0,"     ���˵�                ",8);
            OLED_ShowString(0,16,"��ʱģʽ               ",8);
            OLED_ShowString(0,32,"�ֶ�ģʽ               ",8);
            OLED_ShowString(0,48,"�Զ�ģʽ               ",8);
            OLED_ReverseArea(0,32,128,16);
            OLED_Update();
            break;
        }
        case 3:
            OLED_ShowString(0,0,"     ���˵�                ",8);
            OLED_ShowString(0,16,"��ʱģʽ               ",8);
            OLED_ShowString(0,32,"�ֶ�ģʽ               ",8);
            OLED_ShowString(0,48,"�Զ�ģʽ               ",8);
            OLED_ReverseArea(0,48,128,16);
            OLED_Update();
            break;

        }
    }

}
/*---------------------------------�� �� �� ��-----------------------------------------*/
/**
* @description:��ʱģʽ����
* @return:
*/
int menu21(void) {
    int menu3 = 0;
    uint8_t flag = 1;
    while(1) {
        KeyNum = Key_GetNum();
        if(KeyNum == 1) {//����
            flag--;
            if(flag == 0) {
                flag = 6;
            }
        }
        if(KeyNum == 3) {//����
            flag++;
            if(flag == 7) {
                flag = 1;
            }
        }
        if(KeyNum == 2) {//ȷ��
            OLED_Clear();
            OLED_Update();
            menu3 = flag;
        }

        //���������˵�
        if(menu3 == 1) {
            return 0;//����һ���˵�
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
        //����
        OLED_Clear();
        switch(flag) {
        case 1:
            OLED_ShowString(0,0,"  ����                ",8);
            OLED_Printf(0,16,8,"����Сʱ:%d               ",Hour);
            OLED_Printf(0,32,8,"���÷���:%d               ",Min);
            OLED_Printf(0,48,8,"������:  %d               ",Sec);
            OLED_ReverseArea(0,0,64,16);
            OLED_Update();
            break;
        case 2:
            OLED_ShowString(0,0,"  ����                ",8);
            OLED_Printf(0,16,8,"����Сʱ:%d               ",Hour);
            OLED_Printf(0,32,8,"���÷���:%d               ",Min);
            OLED_Printf(0,48,8,"������:  %d               ",Sec);
            OLED_ReverseArea(0,16,64,16);
            OLED_Update();
            break;
        case 3:
            OLED_ShowString(0,0,"  ����                ",8);
            OLED_Printf(0,16,8,"����Сʱ:%d               ",Hour);
            OLED_Printf(0,32,8,"���÷���:%d               ",Min);
            OLED_Printf(0,48,8,"������:  %d               ",Sec);
            OLED_ReverseArea(0,32,64,16);
            OLED_Update();
            break;
        case 4:
            OLED_ShowString(0,0,"  ����                ",8);
            OLED_Printf(0,16,8,"����Сʱ:%d               ",Hour);
            OLED_Printf(0,32,8,"���÷���:%d               ",Min);
            OLED_Printf(0,48,8,"������:  %d               ",Sec);
            OLED_ReverseArea(0,48,64,16);
            OLED_Update();
            break;
        case 5:
            OLED_Printf(0,0,8,"����ת��:%d               ",Motor_Speed);
            OLED_ShowString(0,16,"  ȷ��              ",8);
            OLED_ReverseArea(0,0,64,16);
            OLED_Update();
            break;
        case 6:
            OLED_Printf(0,0,8,"����ת��:%d               ",Motor_Speed);
            OLED_ShowString(0,16,"  ȷ��              ",8);
            OLED_ReverseArea(0,16,64,16);
            OLED_Update();
            break;
        }
    }
}
/**
* @description:�ֶ�ģʽ����
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
        if(KeyNum == 1) {//����
            flag--;
            if(flag == 0) {
                flag = 2;
            }
        }
        if(KeyNum == 3) {//����
            flag++;
            if(flag == 3) {
                flag = 1;
            }
        }
        if(KeyNum == 2) {//ȷ��
            OLED_Clear();
            OLED_Update();
            menu3 = flag;
        }

        //���������˵�
        if(menu3 == 1) {
            Motor_SetSpeed(0);
            return 0;//����һ���˵�
        }
        if(menu3 == 2) {
            //menu3 = menu3_Lock();
            if(lock_flag == 0) {
                strcpy(lock,"��ť����");
                lock_flag = 1;
            } else if(lock_flag == 1) {
                strcpy(lock,"��ť�ɵ�");
                lock_flag = 0;
            }
            menu3 = 0;
        }
        //����
        switch(flag) {
        case 1:
            OLED_ShowString(0,0,"  ����                ",8);
            OLED_Printf(0,16,8,"%s               ",lock);
            OLED_Printf(0,48,8,"����ת��:%d               ",Motor_Speed);
            OLED_ReverseArea(0,0,64,16);
            OLED_Update();
            break;
        case 2:
            OLED_ShowString(0,0,"  ����                ",8);
            OLED_Printf(0,16,8,"%s               ",lock);
            OLED_Printf(0,48,8,"����ת��:%d               ",Motor_Speed);
            OLED_ReverseArea(0,16,64,16);
            OLED_Update();
            break;
        }
        Motor_SetSpeed(Motor_Speed);
    }
}
/**
* @description:�Զ�ģʽ����
* @return:
*/
int menu23(void) {
    int menu3 = 0;
    uint8_t flag = 1;
    while(1) {
        KeyNum = Key_GetNum();
        if(KeyNum == 1) {//����
            flag--;
            if(flag == 0) {
                flag = 3;
            }
        }
        if(KeyNum == 3) {//����
            flag++;
            if(flag == 4) {
                flag = 1;
            }
        }

        if(KeyNum == 2) {//ȷ��
            OLED_Clear();
            OLED_Update();
            menu3 = flag;
        }

        //���������˵�
        if(menu3 == 1) {
            return 0;//����һ���˵�
        }
        //���������˵�
        if(menu3 == 2) {
            menu3 = menu3_ControlTemperature();
        }
        if(menu3 == 3) {
            menu3 = menu3_ControlHumidity();
        }
        //����
        switch(flag) {
        case 1:
            OLED_ShowString(0,0,"  ����                ",8);
            OLED_ShowString(0,16,"�¶ȿ���               ",8);
            OLED_ShowString(0,32,"ʪ�ȿ���               ",8);
            OLED_ReverseArea(0,0,64,16);
            OLED_Update();
            break;
        case 2:
            OLED_ShowString(0,0,"  ����                ",8);
            OLED_ShowString(0,16,"�¶ȿ���               ",8);
            OLED_ShowString(0,32,"ʪ�ȿ���               ",8);
            OLED_ReverseArea(0,16,64,16);
            OLED_Update();
            break;
        case 3:
            OLED_ShowString(0,0,"  ����                ",8);
            OLED_ShowString(0,16,"�¶ȿ���               ",8);
            OLED_ShowString(0,32,"ʪ�ȿ���               ",8);
            OLED_ReverseArea(0,32,64,16);
            OLED_Update();
            break;
        }
    }
}
/*---------------------------------�� �� �� ��-----------------------------------------*/
/**
* @description:����Сʱ
* @return:
*/
int menu3_SetHour(void) {

    while(1) {
        KeyNum = Enoder_Get();
        if(KeyNum == 3) {//����
            Hour--;
            if(Hour <= -1) {
                Hour = 24;
            }
        }
        if(KeyNum == 1) {//����
            Hour++;
            if(Hour >= 25) {
                Hour = 0;
            }
        }
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//ȷ��
			OLED_Clear();
            OLED_Update();
            return 0;
        }
        OLED_ShowString(0,0,"  ����                ",8);
        OLED_Printf(0,16,8,"����Сʱ:%d               ",Hour);
        OLED_Printf(0,32,8,"���÷���:%d               ",Min);
        OLED_Printf(0,48,8,"������:  %d               ",Sec);
        if(Hour<10) {
            OLED_ReverseArea(72,16,8,16);
        } else {
            OLED_ReverseArea(72,16,16,16);
        }
        OLED_Update();
    }

}
/**
* @description:���÷���
* @return:
*/
int menu3_SetMin(void) {
    while(1) {
        KeyNum = Enoder_Get();
        if(KeyNum == 3) {//����
            Min--;
            if(Min <= -1) {
                Min = 60;
            }
        }
        if(KeyNum == 1) {//����
            Min++;
            if(Min >= 61) {
                Min = 0;
            }
        }
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//ȷ��
            return 0;
        }
        OLED_ShowString(0,0,"  ����                ",8);
        OLED_Printf(0,16,8,"����Сʱ:%d               ",Hour);
        OLED_Printf(0,32,8,"���÷���:%d               ",Min);
        OLED_Printf(0,48,8,"������:  %d               ",Sec);
        if(Min<10) {
            OLED_ReverseArea(72,32,8,16);
        } else {
            OLED_ReverseArea(72,32,16,16);
        }
        OLED_Update();
    }
}
/**
* @description:������
* @return:
*/
int  menu3_SetSec(void) {
    while(1) {
        KeyNum = Enoder_Get();
        if(KeyNum == 3) {//����
            Sec--;
            if(Sec <= -1) {
                Sec = 60;
            }
        }
        if(KeyNum == 1) {//����
            Sec++;
            if(Sec >= 61) {
                Sec = 0;
            }
        }
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//ȷ��
            return 0;
        }
        OLED_ShowString(0,0,"  ����                ",8);
        OLED_Printf(0,16,8,"����Сʱ:%d               ",Hour);
        OLED_Printf(0,32,8,"���÷���:%d               ",Min);
        OLED_Printf(0,48,8,"������:  %d               ",Sec);
        if(Sec<10) {
            OLED_ReverseArea(72,48,8,16);
        } else {
            OLED_ReverseArea(72,48,16,16);
        }
        OLED_Update();
    }
}
/**
* @description:�����ٶ�
* @return:
*/
int menu3_SetSpeed(void) {
    while(1) {
        KeyNum = Enoder_Get();
        if(KeyNum == 3) {//����
            Motor_Speed--;
            if(Motor_Speed <= -1) {
                Motor_Speed = 0;
            }
        }
        if(KeyNum == 1) {//����
            Motor_Speed++;
            if(Motor_Speed >= 101) {
                Motor_Speed = 100;
            }
        }
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//ȷ��
            return 0;
        }
        OLED_Printf(0,0,8,"����ת��:%d               ",Motor_Speed);
        OLED_ShowString(0,16,"  ȷ��              ",8);
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
* @description:����ʱ����
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
        if(KeyNum == 2) {//ȷ��
            PauseCountdown();
            return 0;
        }
        OLED_ShowString(0,0,"  ����              ",8);
        OLED_ShowString(0,16,"ʣ��ʱ��:",8);
        OLED_Printf(0,32,8,"%d:%d:%d              ",Hour,Min,Sec);
        OLED_Printf(0,48,8,"ת��:%d              ",Motor_Speed);
        OLED_ReverseArea(0,0,64,16);
        OLED_Update();
    }

}
/**
* @description:������ʱ����
* @return:
*/
void StartCountdown(uint8_t hours, uint8_t minutes, uint8_t seconds) {
    cdt.total_seconds = Hour * 3600 + Min * 60 + Sec;
    cdt.remaining = cdt.total_seconds;
    cdt.is_running = 1; // ������־
    // ������ʱ��������ʹ��TIM4��������Ϊ1���ж�һ�Σ�
    __HAL_TIM_SET_COUNTER(&htim4, 0);//��ʱ������
    HAL_TIM_Base_Start_IT(&htim4);
}
/**
* @description:��ͣ����ʱ
* @return:
*/
void PauseCountdown(void) {
    Motor_SetSpeed(0);
    cdt.is_running = 0;
	HAL_TIM_Base_Stop_IT(&htim4); // ֹͣ��ʱ��
}
/**
* @description:��ȡ�¶�
* @return:
*/
int menu3_ControlTemperature(void) {
    __HAL_TIM_SET_COUNTER(&htim4, 0);   //��ʱ������
    HAL_TIM_Base_Start_IT(&htim4);		//��ʱ������
    while(1) {
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//ȷ��
            OLED_Clear();
            OLED_Update();
            Motor_SetSpeed(0);
            HAL_TIM_Base_Stop_IT(&htim4);//��ʱ��ֹͣ
            return 0;
        }
        if(timer1s_flag == 1) {
            timer1s_flag = 0;
            DHT11_Read_Data(&temperature,&humidity);
        }
        Motor_Speed = temperature>>8;
        OLED_ShowString(0,0,"  ����                ",8);
        OLED_Printf(0,16,8,"�¶�:%d.%d               ",temperature>>8,temperature&0xff);
        OLED_Printf(0,48,8,"ת��:%d               ",Motor_Speed);
        OLED_ReverseArea(0,0,64,16);
        OLED_Update();
        Motor_SetSpeed(Motor_Speed);
    }
}
/**
* @description:��ȡʪ��
* @return:
*/
int menu3_ControlHumidity(void) {
    __HAL_TIM_SET_COUNTER(&htim4, 0);   //��ʱ������
    HAL_TIM_Base_Start_IT(&htim4);
    while(1) {
        KeyNum = Key_GetNum();
        if(KeyNum == 2) {//ȷ��
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
        OLED_ShowString(0,0,"  ����                ",8);
        OLED_Printf(0,16,8,"ʪ��:%d.%d               ",humidity>>8,humidity&0xff);
        OLED_Printf(0,48,8,"ת��:%d               ",Motor_Speed);
        OLED_ReverseArea(0,0,64,16);
        OLED_Update();
        Motor_SetSpeed(Motor_Speed);
    }
}



