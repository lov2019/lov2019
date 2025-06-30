// 飞 机 杯 控制程序
// by 港南二中2323班罗培玮

#include "stm32f103x8.h"

void SystemClock_Config(void) {
    RCC->CR |= (1 << 16);
    while (!(RCC->CR & (1 << 17)));

    RCC->CFGR &= ~(3 << 0);
    RCC->CFGR |= (2 << 0);

    RCC->CR |= (1 << 16);
    while (!(RCC->CR & (1 << 17)));

    RCC->CFGR |= (0x03 << 16);
    RCC->CR |= (1 << 16);
    while (!(RCC->CR & (1 << 17)));

    RCC->CFGR |= (2 << 0);
    while ((RCC->CFGR & (3 << 0)) != (2 << 0));
}

void GPIO_Init(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void TIM2_Init(void) {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStruct;
    TIM_TimeBaseStruct.TIM_Prescaler = 7199;
    TIM_TimeBaseStruct.TIM_Period = 9999;
    TIM_TimeBaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;

    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStruct);

    TIM_Cmd(TIM2, ENABLE);
}

int main(void) {
    SystemClock_Config();
    GPIO_Init();
    TIM2_Init();

    while (1) {
        for (volatile int i = 0; i < 1000000; i++);
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)(!GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_0)));
    }
}
