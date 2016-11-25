#ifndef __FUNC_LIB_H
#define __FUNC_LIB_H
#include "stm32f10x.h"
#include "bsp_GeneralTim.h"

// maps from device / SRAM bit to bitband
#define BITBAND(addr, bitnum)		((addr & 0xF0000000) + 0x02000000 +\
                                 ((addr & 0x00FFFFFF) << 5) + (bitnum << 2))
// maps address to pointer
#define MEM_ADDR(addr)					*((volatile unsigned long *)(addr))
#define BIT_ADDR(addr, bitnum) 	MEM_ADDR(BITBAND(addr, bitnum))

extern uint8_t delayMul; 
extern uint8_t delayTick; 
extern uint8_t colorNum;

/* delay count execution time */
void delay (uint32_t count);

void checkPulseReading(void);

#endif  /* __FUNC_LIB_H */
