#include "funcLib.h"

uint8_t delayMul = 1;  // delay multiplier

void delay (uint32_t count) {
	count *= delayMul;
	while (count--);
}
