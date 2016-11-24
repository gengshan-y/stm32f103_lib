#include "stm32f10x.h"  // defines registers' address
#include "bsp_led.h"
#include "bsp_rccclkconfig.h"  // to set clock
#include "bsp_exti.h"  // to set interruption
#include "bsp_systick.h"
#include "bsp_usart.h"
#include "bsp_GeneralTim.h"
#include "funcLib.h"  // user defined lib

uint32_t time;

int main (void) {
	// systick is now 72MHz
	uint16_t pinGreen = GPIO_Pin_0;
	uint16_t pinBlue = GPIO_Pin_1;
	uint16_t pinRed = GPIO_Pin_5;
	
	// HSE_SetSysClk( RCC_PLLMul_3 );  // set to 24MHz
	
	SysTick_Config(72000);  // 1ms
	
	LED_GPIO_Config();  // PB0, PB1 and PB5
	
	EXIT_Key_Config();  // set external interruption, PA0
	
	USART_Config();  // PA9 and PA10
	printf("Please enter the delay multiplier\n");
	
	GENERAL_TIM_Init();
	
	while (1) {
		GPIO_ResetBits(GPIOB, pinGreen);  // low-lovel to turn on
		SysTick_Delay_ms(500);
		BIT_ADDR(GPIOB_BASE+12,0)=1;  // using bit operation
		// GPIO_SetBits(GPIOB, pinGreen);  
		SysTick_Delay_ms(500);

		GPIO_ResetBits(GPIOB, pinBlue);
		SysTick_Delay_ms(500);
		GPIO_SetBits(GPIOB, pinBlue);  
		SysTick_Delay_ms(500);

		GPIO_ResetBits(GPIOB, pinRed);
		SysTick_Delay_ms(500);
		GPIO_SetBits(GPIOB, pinRed); 
		SysTick_Delay_ms(500);
		
		if (TIM_ICUserValueStructure.Capture_FinishFlag == 1) {
		  time = TIM_ICUserValueStructure.Capture_Period * (GENERAL_TIM_PERIOD+1) + (TIM_ICUserValueStructure.Capture_CcrValue+1);
	    printf ( "\r\n测得高电平脉宽时间：%d.%d s\r\n",time/72000000,time%72000000 );
	  }
	}
}
