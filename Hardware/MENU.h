#ifndef __MENU_H__
#define __MENU_H__

#include "OLED.h"
#include "key.h"
#include "motor.h"
#include "encoder.h"
#include "stdio.h"
#include "string.h"
#include "dht11.h"

//ȫ�ֱ���
extern int8_t KeyNum;					           	 //������������ת�����������ļ���
extern int Hour,Min,Sec;                             //��ʱģʽ�����ʱ�������
extern int8_t Motor_Speed;					         //�����ǰת��
extern uint8_t countdown_active; 			   	     //����ʱ��־
extern char lock[];                                  //�ַ���
extern uint8_t lock_flag;                            //���������־
extern uint16_t temperature;						 //�¶�
extern uint16_t humidity;							 //ʪ��
extern uint8_t timer1s_flag;                         // ����1���־λ
//�ṹ��
typedef struct {
    uint32_t total_seconds;  // �ܵ���ʱ����
    uint32_t remaining;      // ʣ������
    uint8_t is_running;      // ����ʱ״̬��־
} CountdownTimer;
extern volatile CountdownTimer cdt; // volatile��֤�໷�����ʰ�ȫ

//һ���˵�
void menu1(void);
//�����˵�
int menu21(void);
int menu22(void);
int menu23(void);
//�����˵�
int menu3_SetHour(void);
int menu3_SetMin(void);
int menu3_SetSec(void);
int menu3_SetSpeed(void);
int menu3_Start(void);
int menu3_ControlTemperature(void);
int menu3_ControlHumidity(void);
//������ʱ����
void StartCountdown(uint8_t hours, uint8_t minutes, uint8_t seconds);
//��ͣ����ʱ
void PauseCountdown(void);

#endif
