 #include "led.h"

/**
  * 函    数：PC13置0
  * 参    数：无
  * 返 回 值：无
  * 注意事项：无
  */
void LED_PC13_On(void) {
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
}
/**
  * 函    数：PC13置1
  * 参    数：无
  * 返 回 值：无
  * 注意事项：无
  */
void LED_PC13_Off(void) {
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
}
/**
  * 函    数：反转PC13引脚
  * 参    数：无
  * 返 回 值：无
  * 注意事项：无
  */
void LED_PC13_Reverse(void) {
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}
/**
  * 函    数：PA5置0
  * 参    数：无
  * 返 回 值：无
  * 注意事项：无
  */
void LED_PA5_On(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}
/**
  * 函    数：PA5置1
  * 参    数：无
  * 返 回 值：无
  * 注意事项：无
  */
void LED_PA5_Off(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}
/**
  * 函    数：反转PA5引脚
  * 参    数：无
  * 返 回 值：无
  * 注意事项：无
  */
void LED_PA5_Reverse(void) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
