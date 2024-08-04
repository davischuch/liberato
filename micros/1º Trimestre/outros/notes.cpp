//#include <stm32f4xx.h> //habilita as macros

/*
int main() {
	//habilitar clock
	RCC->AHB1ENR = 0x87 //habilita o clock de todas as portas
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN //habilita o clock das portas a

	//habilitar funcoes dos pinos
	//tabela moder 00 = entrada digital, 01 = saida digital, 10 = funcao digital alternativa, 11 = i/o analogica

	//modo sauer
	GPIOA->MODER = 0x1 // habilita o pino 1 como saida
	GPIOA->MODER = 0x100 // habilita o pino 4 como saida

	//modo zucco
	GPIOA->MODER |= GPIOA_MODER _MODER_0_0 //saida pa0

	//verificar se uma entrada esta acionada
	if ((GPIOA->IDR&0x40) == 1) { //verificar se a entrada pa6 esta em nivel logico alto
		GPIOA->ODR |= 0x80;       //colocar a saida pa7 em nivel logico alto
	} else {
		GPIOA->ODR &=~0x80        //colocar a saida pa7 em nivel logico baixo
	}
}
*/