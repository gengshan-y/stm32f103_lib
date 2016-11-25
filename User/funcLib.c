#include "funcLib.h"
#include "bsp_usart.h"

uint8_t delayMul = 1;  // delay multiplier
uint8_t delayTick = 1;  // delay accumulator
uint8_t colorNum = 0;  // 0 for green, 1 for blue and 5 for red

void delay (uint32_t count) {
	count *= delayMul;
	while (count--);
}

/**
  * @brief check the reading from TIMER5
  */
void checkPulseReading(void) {
	if(TIM_ICUserValueStructure.Capture_FinishFlag == 1) {
		// 计算高电平时间的计数器的值
		uint32_t pauseTime = TIM_ICUserValueStructure.Capture_Period * (0XFFFF+1) + 
		                     (TIM_ICUserValueStructure.Capture_CcrValue+1);
			
		// 打印高电平脉宽时间
		printf( "high-level pulse width：%d.%d s\r\n",pauseTime/1000000,pauseTime%1000000 );  // 1M = 72M clock / GENERAL_TIM_PSC		
		TIM_ICUserValueStructure.Capture_FinishFlag = 0;		
	}
}
