#include "stm32f4xx.h"

/***************************************************
Exercício 2
****************************************************/
void tempo1 (){ //2Hz (0,25s)
TIM10->PSC=399;
//muda o valor do timer pra zero
TIM10->CNT=0x0;
while ((TIM10->SR & 0x01)!=0x1){ };
TIM10->SR &= ~(0x01);
}

void tempo2 (){ //7Hz
TIM10->PSC=113;
TIM10->CNT=0x0;
while ((TIM10->SR&0x01)!=0x1){ };
TIM10->SR &= ~(0x01);
}

int main(void)
{
	RCC->AHB1ENR=0x87; //Habilitando o CLK dos GPIOs
	//GPIOA->MODER|=0x28000000; // Configurando PA14 e PA13 como função alternativa;
	GPIOB->MODER=0x01; // PB0 como saída (será conectado ao led)
	GPIOC->MODER=0x0; // Iremos utilizar PC1 como entrada
	GPIOC->PUPDR=0x4; // Pull-up em PC1;

	//Configurando o timer;
	RCC->APB2ENR|=0x20000; //Habilitando o CLK do timer10
	TIM10->CR1|=0x05; //Habilita a contagem do timer
	TIM10->ARR=9999;
	while (1)
	{
		if((GPIOC->IDR &= 0x02)==0x02){//botao apertado
			GPIOB->ODR |= 0x01;
			tempo1();
			GPIOB->ODR &= ~(0x01);
			tempo1();
		}else{
			GPIOB->ODR |= 0x01;
			tempo2();
			GPIOB->ODR &= ~(0x01);
			tempo2();
	}
	}
}
