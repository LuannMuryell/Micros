#include "stm32f4xx.h"

/***************************************************
Exercício 7
****************************************************/

void tempo (){
while ((TIM10->SR&0x01)==0x00){ };
TIM10->SR &= ~(0x01);
}

int main(void)
{
RCC->AHB1ENR=0x87; //Habilitando o CLK dos GPIOs
GPIOA->MODER=0x28145505; // Configurando PA14 e PA13 como função alternativa;
						 // PA0, PA1, PA4, PA5, PA6, PA7, PA9 e PA10 como saída 	 	 	 	 	  
//Configurando o timer para gerar 0,5 segundo;
RCC->APB2ENR|=0x20000; //Habilitando o CLK do timer10
TIM10->CR1|=0x05; //Habilitando a contagem do timer
TIM10->PSC=799;
TIM10->ARR=9999;

while (1)
{
GPIOA->ODR|=0x00000001;
GPIOA->ODR|=0x00000400;
tempo();

GPIOA->ODR&=~0x00000001;
GPIOA->ODR&=~0x00000400;
GPIOA->ODR|=0x00000002;
GPIOA->ODR|=0x00000200;
tempo();

GPIOA->ODR&=~0x00000002;
GPIOA->ODR&=~0x00000200;
GPIOA->ODR|=0x00000010;
GPIOA->ODR|=0x00000080;
tempo();

GPIOA->ODR&=~0x00000010;
GPIOA->ODR&=~0x00000080;
GPIOA->ODR|=0x00000020;
GPIOA->ODR|=0x00000040;
tempo();

GPIOA->ODR&=~0x00000020;
GPIOA->ODR&=~0x00000040;
tempo();

GPIOA->ODR|=0x00000020;
GPIOA->ODR|=0x00000040;
tempo();

GPIOA->ODR&=~0x00000020;
GPIOA->ODR&=~0x00000040;
GPIOA->ODR|=0x00000010;
GPIOA->ODR|=0x00000080;
tempo();

GPIOA->ODR&=~0x00000010;
GPIOA->ODR&=~0x00000080;
GPIOA->ODR|=0x00000002;
GPIOA->ODR|=0x00000200;
tempo();

GPIOA->ODR&=~0x00000002;
GPIOA->ODR&=~0x00000200;
GPIOA->ODR|=0x00000001;
GPIOA->ODR|=0x00000400;
tempo();

GPIOA->ODR&=~0x00000001;
GPIOA->ODR&=~0x00000400;
tempo();

	}
}
