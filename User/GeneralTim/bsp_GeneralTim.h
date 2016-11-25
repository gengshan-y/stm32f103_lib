#ifndef __BSP_GENERALTIME_H
#define __BSP_GENERALTIME_H

#include "stm32f10x.h"


/************通用定时器TIM参数定义，只限TIM2、3、4、5************/

// use TIM5 to fetch input, gpioa0 for key1
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_PSC               (72-1)

// use TIM3 to generate PWM signal



// 定时器输入捕获用户自定义变量结构体声明
typedef struct
{   
	uint8_t   Capture_FinishFlag;   // 捕获结束标志位
	uint8_t   Capture_StartFlag;    // 捕获开始标志位
	uint16_t  Capture_CcrValue;     // 捕获寄存器的值
	uint16_t  Capture_Period;       // 自动重装载寄存器更新标志 
}TIM_ICUserValueTypeDef;

extern TIM_ICUserValueTypeDef TIM_ICUserValueStructure;


void GENERAL_TIM_KEYIN_Init(void);
void GENERAL_TIM_PWMOUT_Init(void);

#endif	/* __BSP_GENERALTIME_H */
