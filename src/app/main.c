#include "stm32f10x_conf.h"

//#include <stdint.h>

// In the mini stm32f103c8t6 board,
// PC13 is the LED

void led_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* GPIOC Periph clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

  // 
  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void led_on(void)
{
  GPIO_ResetBits(GPIOC, GPIO_Pin_13);
}

void led_off(void)
{
  GPIO_SetBits(GPIOC, GPIO_Pin_13);
}

void delay(volatile uint32_t cnt)
{
  while(cnt--)
    ;
}

int main(void)
{
  led_init();

  while(1)
  {
    led_off();
    delay(0x3FFFFF);
    led_on();
    delay(0x3FFFFF);
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

#endif
