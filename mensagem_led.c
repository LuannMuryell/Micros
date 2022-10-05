#include "stm32f4xx.h"

///FUNÇOES COM OS TIMERS
void tempo1s(void){
///ZERANDO O TIMER 10
TIM11->CNT = 0x0;
///CONFERINDO SE O TIMER ESTOROU
while((TIM11->SR & 0x1)!=1);
///ZERANDO O TIMER
TIM11->SR = ~(0x1);
}

void tempo01s(void){
///ZERANDO O TIMER 11
TIM10->CNT = 0x0;
///CONFERINDO SE O TIMER ESTOROU
while((TIM10->SR & 0x1)!=1);
///ZERANDO O TIMER
TIM10->SR = ~(0x1);
}
//recebe o num de vezes que ira ligar e desligar
void ligaled(int i){

for(int j=0;j<=i;j++)
{
	///INVERTENDO O ESTADO DO PINO PA8
	GPIOA->ODR ^= 0x100;
	///AGUARDANDO O TIMER DE 0.1s
	tempo01s();
	///INVERTENDO O ESTADO DO PINO PA8
	GPIOA->ODR ^= 0x100;
	///AGUARDANDO O TIMER DE 0.1s
	tempo01s();
}
}

int main(void)
{
//VARIAVEL DE CONTROLE
int aux = 0;

//Habilitando o clock das portas
RCC->AHB1ENR |= 0X87;
//Habilitando o clock do timer 10 e 11
RCC->APB2ENR |= 0x60000;

GPIOB->PUPDR=0x540;
//HABILITENDO A PORTA PA8 COMO SAIDA
GPIOA->MODER |=0x10000;
//HABILITANDO A CONTAGEM DO TIMER
TIM10->CR1 = 0x5;
TIM11->CR1 =0x5;

//configurando o timer 10 para 0,10s
TIM10->ARR = 399;
TIM10->PSC = 3999;

//configurando o timer 11 para 1s
TIM11->ARR = 999;
TIM11->PSC = 15999;

//SETANDO O LED PARA 1
GPIOA->ODR |= 0x100;

while (1){
//!Cada entrada sera armazenada em um bit da variavel

///LENDO A PORTA PB3
if((GPIOB->IDR &= 0x8)==0x0)
aux += 1; 				//001
///LENDO A PORTA PB4
if((GPIOB->IDR &= 0x10)==0x0)
	aux += 2; 				//010
///LENDO A PORTA PB5
if((GPIOB->IDR &= 0x20)==0x0)
	aux += 4; 				//100

/// O NUM QUE ESTA ARMAZENADO NA VARIAVEL SERA O UNM DE PISCADAS
switch(aux){
case 1:
	ligaled(1);
	break;
case 2:
	ligaled(2);
	break;
case 3:
	ligaled(3);
	break;
case 4:
	ligaled(4);
	break;
case 5:
	ligaled(5);
	break;
}
//zerando a variavel de controle
aux = 0;
//FUNÇAO QUE ESPERA 1s
tempo1s();
}
}
