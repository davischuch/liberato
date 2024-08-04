#include "stm32f4xx.h"

int main(void) {
	RCC->AHB1ENR |= 0x87;
	GPIOA->MODER = 0x28000400;
	GPIOB->MODER = 0x00000000;
	GPIOB->PUPDR = 0x00008000;

  while (1)  {
	  if ((GPIOB->IDR&0x80) != 0) {
		  GPIOA->ODR ^= 0x20;
	  }
  }
}
