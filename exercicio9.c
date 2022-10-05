#include "stm32f4xx.h"
#include "stdio.h"

void config_tim_11(void){
//configurar timer 11
RCC->APB2ENR |=0x00040000; //habilitando o clock do timer 11
TIM11->ARR=99;
//TIM11->ARR=19999;
TIM11->CR1|=0x00000085;
TIM11->DIER|=0x01; //habilita interrupção timer11
// Habilita interrupção no controlador

}

void notas(){

if((GPIOA->IDR & 0x00000001)==0) //A0
{
TIM11->PSC=306;       //DÓ
GPIOB->ODR^=0x00000010; //B4
}

if((GPIOA->IDR & 0x00000002)==0) //A1
{
TIM11->PSC=272;       //RÉ
GPIOB->ODR^=0x00000010; //B4
}

if((GPIOA->IDR & 0x00000010)==0) //A4
{
TIM11->PSC=241;       //Mi
GPIOB->ODR^=0x00000010; //B4
}

if((GPIOA->IDR & 0x00000020)==0) //A5
{
TIM11->PSC=228;       //FÁ
GPIOB->ODR^=0x00000010; //B4
}

if((GPIOA->IDR & 0x00000040)==0) //A6
{
TIM11->PSC=203;       //SOL
GPIOB->ODR^=0x00000010; //B4
}


if((GPIOA->IDR & 0x00000080)==0) //A7
{
TIM11->PSC=181;       //LÁ
GPIOB->ODR^=0x00000010; //B4
}

if((GPIOA->IDR & 0x00000200)==0) //A9
{
TIM11->PSC=161;       //SI
GPIOB->ODR^=0x00000010; //B4
}

TIM11->SR &=~(0x00000001);//limpando o flag do timer11

}

int main(void)
{
RCC->AHB1ENR=0X00000087;
GPIOA->MODER=0X28000000;
GPIOA->PUPDR=0X00045505; // Pull up em PA0, PA1, PA4, PA5, PA6, PA7 e PA9
GPIOB->MODER=0X00000500; // Saídas PB4 e PB5

config_tim_11();

while (1)
{
if(TIM11->SR & 0x00000001){
notas();}
}
}
