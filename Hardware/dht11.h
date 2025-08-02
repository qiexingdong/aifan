#ifndef __DHT11_H__
#define __DHT11_H__

#include "main.h"
#include "tim.h"

#define DHT11_DQ_OUT_HIGH HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET)//PA1��Ϊ�ߵ�ƽ
#define DHT11_DQ_OUT_LOW 	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET)//PA1��Ϊ�͵�ƽ
#define DHT11_DQ_IN	 HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)//��PA1��ƽ
 
//IO��������
void DS18B20_IO_IN(void);
void DS18B20_IO_OUT(void);
	
uint8_t DHT11_Init(void);//��ʼ��DHT11
uint8_t DHT11_Read_Data(uint16_t *temp,uint16_t *humi);//��ȡ��ʪ��
uint8_t DHT11_Read_Byte(void);//����һ���ֽ�
uint8_t DHT11_Read_Bit(void);//����һ��λ
uint8_t DHT11_Check(void);//����Ƿ����DHT11
void DHT11_Rst(void);//��λDHT11  



#endif
