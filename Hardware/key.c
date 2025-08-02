#include "key.h"

#define KEY_1 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)
#define KEY_2 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)
#define KEY_3 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_14)

/**
  * 函    数：按键获取键码
  * 参    数：无
  * 返 回 值：按下按键的键码值，范围：0~3，返回0代表没有按键按下
  * 注意事项：此函数是阻塞式操作，当按键按住不放时，函数会卡住，直到按键松手
  */
uint8_t Key_GetNum(void)
{
    uint8_t Key = 0;		//默认键码为0

    if(KEY_1 == 1)	//读取PB13输入
    {
        HAL_Delay(20);
        while(KEY_1 == 1);	//等待松手
        HAL_Delay(20);
        Key = 1;
    }
    if(KEY_2 == 1)	//读取PB12输入
    {
        HAL_Delay(20);
        while(KEY_2 == 1);	//等待松手
        HAL_Delay(20);
        Key = 2;
    }
    if(KEY_3 == 1)	//读取PB14输入
    {
        HAL_Delay(20);
        while(KEY_3 == 1);	//等待松手
        HAL_Delay(20);
        Key = 3;
    }
    return Key;
}
