#include "main.h"
#include "FreeRTOS.h"
#include "croutine.h"
#include "task.h"
#include "gpio.h"


uint8_t ucHeap[configTOTAL_HEAP_SIZE];

void led_task(void* p);


void main(void)
{
    // init section
    SystemInit();
    SysTick_Config(SystemCoreClock / 1000);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    gpio_init();
    // ------------
    
    // tasks section
    BaseType_t res = xTaskCreate(led_task, "LED", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    // ------------
    
    vTaskStartScheduler();  // should never return
    while(1)
    {
    }
}


void led_task(void* p)
{
    while(1)
    {
        ((GPIOC->ODR) ^= (GPIO_ODR_ODR_13));
        vTaskDelay(500);
    }
//    xTaskDelete(NULL);  // comment if using heap_1.c
}