#ifndef __SIM900A_H__
#define __SIM900A_H__

#include "main.h"
#include "GPS.h"
#include "stdio.h"
#include "string.h"
#include "usart.h"
#include "stdarg.h"
#include "stdbool.h"
#include "ATGM336H.h"

// 发送AT指令的缓冲区（防止溢出）
#define AT_BUFFER_SIZE 128
extern char at_buffer[AT_BUFFER_SIZE];
extern char English_message[];  //英文短信内容
extern char phonenumber[];      //接受短信的号码
// 定义USART句柄和缓冲区
extern UART_HandleTypeDef huart1;
extern uint8_t ctrlZ;  // Ctrl+Z的十六进制表示

typedef struct {
    uint32_t seconds;  // 总倒计时秒数
    uint8_t is_running;      // 倒计时状态标志
} CountDelay;
extern volatile CountDelay cd; // volatile保证多环境访问安全

// 定义足够大的缓冲区来存储格式化后的消息
extern char message_buffer[100];
void SIM900A_Send_English_Message(const char *number, const char *message);
void TriggerEmergencySMS(void);
#endif
