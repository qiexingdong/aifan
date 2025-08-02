//#include "text.h"



///*SIM900A短信内容和号码*/
//char English_message[]= {"sos help!"};                            //英文短信内容
//char phonenumber[]= {"19702208120"};                            //接受短信的号码

//// 定义USART句柄和缓冲区
//uint8_t ctrlZ = 0x1A;  // Ctrl+Z的十六进制表示

//// 自定义发送函数（自动添加\r\n）
//void Send_AT_Command(UART_HandleTypeDef *huart, const char *cmd) {
//    HAL_UART_Transmit(huart, (uint8_t*)cmd, strlen(cmd), 100);  // 发送指令
//    HAL_UART_Transmit(huart, (uint8_t*)"\r\n", 2, 100);         // 添加回车换行
//    HAL_Delay(500);  // 简单延时等待响应（实际需根据模块响应优化）
//}
///**
//  * 函    数：发送短信
//  * 参    数：无
//  * 返 回 值：无
//  * 注意事项：发送短信的AT指令如下
//			AT+CMGF=1
//			AT+CSCS="GSM"
//			AT+CSCA?
//			AT+CSMP=17,167,0,0
//			AT+CMGS="13365113887"
//			sos
//			1A（16进制）
//*/
//void SIM900A_Send_English_Message(void) {
//    // 1. 设置短信为文本模式
//    Send_AT_Command(&huart1, "AT+CMGF=1");
//    
//    // 2. 设置字符集为GSM
//    Send_AT_Command(&huart1, "AT+CSCS=\"GSM\"");
//    
//    // 3. 查询服务中心号码（可选，实际使用时可能需要配置）
//    Send_AT_Command(&huart1, "AT+CSCA?");
//    
//    // 4. 设置短信参数
//    Send_AT_Command(&huart1, "AT+CSMP=17,167,0,0");
//    
//    // 5. 指定接收号码
//    Send_AT_Command(&huart1, "AT+CMGS=\"19702208120\"");
//    
//    // 6. 等待SIM900A返回 "> " 提示符（需实际检测，此处简化）
//    HAL_Delay(1000);
//    
//    // 7. 发送短信内容 "sos"
//    HAL_UART_Transmit(&huart1, (uint8_t*)"SOS", 3, 100);
//    
//    // 8. 发送Ctrl+Z结束符
//    HAL_UART_Transmit(&huart1, &ctrlZ, 1, 100);
//}
