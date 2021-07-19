#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"


void gpio_init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    
    GPIO_InitTypeDef LED;
    GPIO_StructInit(&LED);
    LED.GPIO_Pin = GPIO_Pin_13;
    LED.GPIO_OType = GPIO_OType_PP;
    LED.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_Init(GPIOC, &LED);
}