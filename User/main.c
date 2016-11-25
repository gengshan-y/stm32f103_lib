#include "stm32f10x.h"  // defines registers' address
#include "bsp_led.h"
#include "bsp_rccclkconfig.h"  // to set clock
#include "bsp_exti.h"  // to set interruption
#include "bsp_systick.h"
#include "bsp_usart.h"
#include "bsp_GeneralTim.h"
#include "bsp_AdvanceTim.h"
#include "funcLib.h"  // user defined lib

int main (void) {
	// systick is now 72MHz
	
	// HSE_SetSysClk( RCC_PLLMul_3 );  // set to 24MHz
	
	SysTick_Config(7200000);  // 100ms, maximum 2^24 ticks for ~200ms
	
	LED_GPIO_Config();  // PB0, PB1 and PB5
	
	EXIT_Key_Config();  // set external interruption, PA0
	
	USART_Config();  // PA9 and PA10
	printf("Usage:\nspeed[1,2,3] or color[r,g,b]\n");
	
	GENERAL_TIM_KEYIN_Init();  // key1 & TIM5
	GENERAL_TIM_PWMOUT_Init();  // TIM3
	ADVANCE_TIM_Init();  // TIM1
	
	while ( 1 )
	{
		checkPulseReading();
		
	}
}
