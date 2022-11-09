#include "stm32f4xx.h"

int disp1=0, disp2=1, disp3=2, disp4=3;
int conta_disp=0;

int nomeLuann[]={0x0, 0X38, 0X1C, 0X77, 0X54, 0X54}; // L-u-a-n-n
// 0x0 espaço em branco

void TIM1_UP_TIM10_IRQHandler(){
  if(++disp1>5)
    disp1=0;
  if(++disp2>5)
    disp2=0;
  if(++disp3>5)
    disp3=0;
  if(++disp4>5)
    disp4=0;
  TIM10->SR &= ~(0x01);  //limpando flag do timer10
}


void TIM1_TRG_COM_TIM11_IRQHandler(){
  GPIOC->ODR |=0xF00;  //desligando todos os displays
  GPIOC->ODR &=~0xFF;  //limpando os oito bits

  switch(conta_disp){
  case 0:
      GPIOC->ODR |= nomeLuann[disp1];
      GPIOC->ODR &= ~0x800;
      break;
  case 1:
      GPIOC->ODR |= nomeLuann[disp2];
      GPIOC->ODR &= ~0x400;
      break;
  case 2:
      GPIOC->ODR |= nomeLuann[disp3];
      GPIOC->ODR &= ~0x200;
      break;
  case 3:
      GPIOC->ODR |= nomeLuann[disp4];
      GPIOC->ODR &= ~0x100;
      break;

  }
  if(++conta_disp>3)conta_disp=0;


  TIM11->SR &= ~(0x01);  //limpando flag do timer10
}
void config_int_tim11(void){
  //configurando o timer11 para 4ms
    RCC->APB2ENR|=0x40000;  //habilita clock timer10
    TIM11->CR1|=0x01;    //habilita contagem timer10
    TIM11->PSC=79;
    TIM11->ARR=799;

    TIM11->DIER|=0x01;    //habilita interrupção timer10
    // Habilita interrupção no controlador
    NVIC_SetPriority(TIM1_TRG_COM_TIM11_IRQn, 4);//Priority 3
    NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);//
}
void config_int_tim10(void){
  //configurando o timer10 para 0,5s
    RCC->APB2ENR|=0x20000;  //habilita clock timer10
    TIM10->CR1|=0x01;    //habilita contagem timer10
    TIM10->PSC=1999;
    TIM10->ARR=3999;

    TIM10->DIER|=0x01; //habilita interrupção timer10
    // Habilita interrupção no controlador
    NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 3);//Priority 3
    NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);//
}

int main(void)
{
  RCC->AHB1ENR=0x87;
  GPIOC->MODER|=0x00555555;
  GPIOA->MODER|=0x28555500;  //PA5 como saída
  //configurando o timer10 para gerar 5segundos
  config_int_tim10();
  config_int_tim11();
  while (1) {

// PC0 -> Segmento A
// PC1 -> B
// PC2 -> C
// PC3 -> D
// PC4 -> E
// PC5 -> F
// PC6 -> G
// PC8 -> Display 1
// PC9 -> Display 2
// PC10 -> Display 3
// PC11 -> Display 4
  }
}
