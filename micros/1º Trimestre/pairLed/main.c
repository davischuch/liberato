#include "stm32f4xx.h"

int main(void) {
	RCC->AHB1ENR |= 0x87;
	GPIOA->MODER = 0x28000400;
	GPIOB->MODER = 0x00000000;
	GPIOB->PUPDR = 0x002A8000;

	while (1) {
	  int i = (GPIOB->IDR&0x780)>>7;
	  switch (i) {
	  case 3:
	  case 5:
	  case 6:
	  case 9:
	  case 10:
	  case 12:
	  case 15:
		  GPIOA->ODR = 0x20;
		  break;
	  default:
		  GPIOA->ODR = 0x00;
		  break;
	  }
  }
}