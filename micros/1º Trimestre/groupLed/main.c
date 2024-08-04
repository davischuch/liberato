#include "stm32f4xx.h"

int main(void) {
	RCC->AHB1ENR |= 0x87;
	GPIOA->MODER = 0x28000400;
	GPIOB->MODER = 0x00000000;
	GPIOB->PUPDR = 0x002A8000;

  while (1) {
	  int i = (GPIOB->IDR&0x180)>>7;
	  int j = (GPIOB->IDR&0x600)>>9;
	  if (i == j) {
		  GPIOA->ODR = 0x20;
	  } else {
		  GPIOA->ODR = 0x00;
	  }
  }
}