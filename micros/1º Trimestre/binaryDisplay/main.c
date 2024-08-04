#include "stm32f4xx.h"
#include <stdbool.h>

int main(void) {
	RCC->AHB1ENR |= 0x87;
	GPIOB->MODER = 0x00001555;
	GPIOB->PUPDR = 0x002A8000;

	while (1) {
	  int i = (GPIOB->IDR&0x780)>>7;
	  switch (i) {
	  	  case 0:
	  		  GPIOB->ODR = 0x003F;
			  break;
		  case 1:
			  GPIOB->ODR = 0x0006;
			  break;
		  case 2:
			  GPIOB->ODR = 0x005B;
			  break;
		  case 3:
			  GPIOB->ODR = 0x004F;
			  break;
		  case 4:
			  GPIOB->ODR = 0x0066;
			  break;
		  case 5:
			  GPIOB->ODR = 0x006D;
			  break;
		  case 6:
			  GPIOB->ODR = 0x007D;
			  break;
		  case 7:
			  GPIOB->ODR = 0x0007;
			  break;
		  case 8:
			  GPIOB->ODR = 0x007F;
			  break;
		  case 9:
			  GPIOB->ODR = 0x0067;
			  break;
		  case 10:
			  GPIOB->ODR = 0x0077;
			  break;
		  case 11:
			  GPIOB->ODR = 0x007C;
			  break;
		  case 12:
			  GPIOB->ODR = 0x0039;
			  break;
		  case 13:
			  GPIOB->ODR = 0x005E;
			  break;
		  case 14:
			  GPIOB->ODR = 0x0079;
			  break;
		  case 15:
			  GPIOB->ODR = 0x0071;
			  break;
		  default:
			  GPIOB->IDR = 0x003F;
			  break;
	  }
	}
}
