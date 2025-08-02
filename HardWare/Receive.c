//#include "Receive.h"


//uint8_t counter;//累计接收数据的长度
//uint8_t buff[20];
//uint32_t tick;

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *haurt) {
//    counter++;
//    tick = uwTick;
//    HAL_UART_Receive_IT(&huart1,&buff[counter],1);
//}

//void uart_task() {
//    if(counter != 0) {
//        if((uwTick-tick)>5) {//说明数据接收完毕
//            printf("一共接收到%d个数据，数据的内容是:%s\r\n",counter,buff);
//            counter = 0;
//            memset(buff,0,sizeof(buff));
//            huart1.pRxBuffPtr = buff;
//        }
//    }
//}
