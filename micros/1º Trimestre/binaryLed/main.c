#include "stm32f4xx.h"

int main(void) {
	RCC->AHB1ENR = 0x00000087;
	GPIOB->MODER = 0x00001555;
	GPIOB->PUPDR = 0x000A8000;

	while (1) {
		int i = (GPIOB->IDR&0x380)>>7;
		switch(i) {
			case 0:
				GPIOB->ODR = 0x0000;
				break;
			case 1:
				GPIOB->ODR = 0x0001;
				break;
			case 2:
				GPIOB->ODR = 0x0003;
				break;
			case 3:
				GPIOB->ODR = 0x0007;
				break;
			case 4:
				GPIOB->ODR = 0x000F;
				break;
			case 5:
				GPIOB->ODR = 0x001F;
				break;
			case 6:
				GPIOB->ODR = 0x003F;
				break;
			case 7:
				GPIOB->ODR = 0x007F;
				break;
			default:
				GPIOB->ODR = 0x0000;
				break;
		}
	}
}
