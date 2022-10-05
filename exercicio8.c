#include "stm32f4xx.h"

/***************************************************
Exercício 8
****************************************************/

void tempo (){
while ((TIM10->SR&0x01)==0x00){ };
TIM10->SR &= ~(0x01);
}

void sequenciaex5 (){
	tempo();
	GPIOA->ODR|=0x00000001;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
	return;

	GPIOA->ODR&=~0x00000001;
	GPIOA->ODR|=0x00000002;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000002;
	GPIOA->ODR|=0x00000010;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000010;
	GPIOA->ODR|=0x00000020;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000020;
	GPIOA->ODR|=0x00000040;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000040;
	GPIOA->ODR|=0x00000080;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000080;
	GPIOA->ODR|=0x00000200;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000200;
	GPIOA->ODR|=0x00000400;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR|=0x00000200;
	GPIOA->ODR&=~0x00000400;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000200;
	GPIOA->ODR|=0x00000080;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000080;
	GPIOA->ODR|=0x00000040;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000040;
	GPIOA->ODR|=0x00000020;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000020;
	GPIOA->ODR|=0x00000010;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000010;
	GPIOA->ODR|=0x00000002;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000002;
	GPIOA->ODR|=0x00000001;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;

	GPIOA->ODR&=~0x00000001;
	tempo();

	if((GPIOB->IDR & 0x08)!=0)
		return;
}

void sequenciaex6 (){
	tempo();
	GPIOA->ODR|=0x00000001; //liga a saída PA0
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
		return;

	GPIOA->ODR|=0x00000002;
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR|=0x00000010;
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR|=0x00000020; //PA0, PA1, PA4
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR|=0x00000040; //PAO, PA1, PA4, PA5
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR|=0x00000080; //PA0, PA1, PA4, PA5, PA6
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR|=0x00000200; //PA0, PA1, PA4, PA5, PA6, PA7
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR|=0x00000400; //PA0, PA1, PA4, PA5, PA6, PA7, PA9
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR&=~0x00000400; //PA0, PA1, PA4, PA5, PA6
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR&=~0x00000200;
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR&=~0x00000080; //PA0, PA1, PA4
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR&=~0x00000040;
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR&=~0x00000020; //PA0
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR&=~0x00000010; //Nenhuma ligada
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR&=~0x00000002;
	tempo();

	if((GPIOB->IDR & 0x010)!=0)
			return;

	GPIOA->ODR&=~0x00000001;
}

void sequenciaex7 (){
	GPIOA->ODR|=0x00000001;
	GPIOA->ODR|=0x00000400;
	tempo();

	if((GPIOB->IDR & 0x018)!=0x18)
		return;

	GPIOA->ODR&=~0x00000001;
	GPIOA->ODR&=~0x00000400;
	GPIOA->ODR|=0x00000002;
	GPIOA->ODR|=0x00000200;
	tempo();

	if((GPIOB->IDR & 0x018)!=0x18)
			return;

	GPIOA->ODR&=~0x00000002;
	GPIOA->ODR&=~0x00000200;
	GPIOA->ODR|=0x00000010;
	GPIOA->ODR|=0x00000080;
	tempo();

	if((GPIOB->IDR & 0x018)!=0x18)
			return;

	GPIOA->ODR&=~0x00000010;
	GPIOA->ODR&=~0x00000080;
	GPIOA->ODR|=0x00000020;
	GPIOA->ODR|=0x00000040;
	tempo();

	if((GPIOB->IDR & 0x018)!=0x18)
			return;

	GPIOA->ODR&=~0x00000020;
	GPIOA->ODR&=~0x00000040;
	tempo();

	if((GPIOB->IDR & 0x018)!=0x18)
			return;

	GPIOA->ODR|=0x00000020;
	GPIOA->ODR|=0x00000040;
	tempo();

	if((GPIOB->IDR & 0x018)!=0x18)
			return;

	GPIOA->ODR&=~0x00000020;
	GPIOA->ODR&=~0x00000040;
	GPIOA->ODR|=0x00000010;
	GPIOA->ODR|=0x00000080;
	tempo();

	if((GPIOB->IDR & 0x018)!=0x18)
			return;

	GPIOA->ODR&=~0x00000010;
	GPIOA->ODR&=~0x00000080;
	GPIOA->ODR|=0x00000002;
	GPIOA->ODR|=0x00000200;
	tempo();

	if((GPIOB->IDR & 0x018)!=0x18)
			return;

	GPIOA->ODR&=~0x00000002;
	GPIOA->ODR&=~0x00000200;
	GPIOA->ODR|=0x00000001;
	GPIOA->ODR|=0x00000400;
	tempo();

	if((GPIOB->IDR & 0x018)!=0x18)
			return;

	GPIOA->ODR&=~0x00000001;
	GPIOA->ODR&=~0x00000400;
	tempo();

	if((GPIOB->IDR & 0x018)!=0x18)
			return;
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
GPIOB->PUPDR=0x140; //Pull-up em PB3 e PB4

	while (1){

		if((GPIOB->IDR & 0x18)==0x10){ //PB3 01
			GPIOA->ODR=0;
			sequenciaex5();

		}else if((GPIOB->IDR & 0x018)==0x08){ //PB4 10
			GPIOA->ODR=0;
			sequenciaex6();

		}else{
			sequenciaex7(); //00

		}
	}
}
