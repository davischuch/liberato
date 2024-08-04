#include "stm32f4xx.h"

int main(void) {
	RCC->AHB1ENR = 0x087;       //ativa clock
	GPIOA->MODER |= 0x28000400; //pa5 saida
	GPIOC->MODER |= 0x00;       //pc13 entrada

  while (1) {
	if ((GPIOC->IDR&0x2000) == 0) {
		GPIOA->ODR |= 0x20;
	} else {
		GPIOA->ODR &=~0x20;
	}

  }
}
