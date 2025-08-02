#include "key.h"

#define KEY_1 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)
#define KEY_2 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)
#define KEY_3 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_14)

/**
  * ��    ����������ȡ����
  * ��    ������
  * �� �� ֵ�����°����ļ���ֵ����Χ��0~3������0����û�а�������
  * ע������˺���������ʽ��������������ס����ʱ�������Ῠס��ֱ����������
  */
uint8_t Key_GetNum(void)
{
    uint8_t Key = 0;		//Ĭ�ϼ���Ϊ0

    if(KEY_1 == 1)	//��ȡPB13����
    {
        HAL_Delay(20);
        while(KEY_1 == 1);	//�ȴ�����
        HAL_Delay(20);
        Key = 1;
    }
    if(KEY_2 == 1)	//��ȡPB12����
    {
        HAL_Delay(20);
        while(KEY_2 == 1);	//�ȴ�����
        HAL_Delay(20);
        Key = 2;
    }
    if(KEY_3 == 1)	//��ȡPB14����
    {
        HAL_Delay(20);
        while(KEY_3 == 1);	//�ȴ�����
        HAL_Delay(20);
        Key = 3;
    }
    return Key;
}
