#include "stm32f4xx.h"

///FUNÇOES COM OS TIMERS
void tempo02(void){
	///ZERANDO O TIMER
	TIM11->CNT = 0x0;
	///CONFERINDO SE O TIMER ESTOROU
	while((TIM11->SR & 0x1)!=1);
	///ZERANDO O TIMER
	TIM11->SR = ~(0x1);
}

void tempo05(void){
	///ZERANDO O TIMER
	TIM10->CNT = 0x0;
	///CONFERINDO SE O TIMER ESTOROU
	while((TIM10->SR & 0x1)!=1);
	///ZERANDO O TIMER
	TIM10->SR = ~(0x1);
}
///FUNCOES DOS SEMAFOROS
void semaforo01(void){
	///DESLIGAR O LED Vm E LIGAR O Vd		PC0, PC2
	GPIOC->ODR &= ~(0x01);
	GPIOC->ODR |= 0x4;
	tempo05();
	tempo05();
	///LIGAR O LED Am
	GPIOC->ODR |= 0x2;
	tempo05();
	//DESLIGAR OS LEDS Vd E Am E LIGAR O Vm
	GPIOC->ODR &= ~(0x4);
	GPIOC->ODR &= ~(0x2);
	GPIOC->ODR |= 0x01;
}
void semaforo02(void){
	///DESLIGAR O LED Vm E LIGAR O Vd		PC3, PC5
	GPIOC->ODR &= ~(0x08);
	GPIOC->ODR |= 0x20;
	tempo05();
	tempo05();
	///LIGAR O LED Am
	GPIOC->ODR |= 0x10;
	tempo05();
	//DESLIGAR OS LEDS Vd E Am E LIGAR O Vm
	GPIOC->ODR &= ~(0x20);
	GPIOC->ODR &= ~(0x10);
	GPIOC->ODR |= 0x08;
}

int main(void)
{
    //Habilitando o clock das portas
    RCC->AHB1ENR |= 0X87;
    //Habilitando o clock do timer 10 e 11
    RCC->APB2ENR |= 0x60000;

    //HABILITENDO A PORTA PC0 A PC5 COMO SAIDA
    GPIOC->MODER |=0x555;
    //HABILITANDO A CONTAGEM DO TIMER
    TIM10->CR1 = 0x5;
    TIM11->CR1 = 0x5;

    //configurando o timer 10 para 500ms
	TIM10->ARR = 1999;
	TIM10->PSC = 3999;

	//configurando o timer 11 para 200ms
	TIM11->ARR = 1999;
	TIM11->PSC = 1599;

	///LIGANDO OS 2 LEDS VERMELHOS		PC0, PC3
	GPIOC->ODR |= 0x09;

    while (1)
    {
    	///FUNCAO DO 1º SEMAFORO
    	semaforo01();
    	///FUNCAO DO 2º SEMAFORO
    	semaforo02();
    }
}
