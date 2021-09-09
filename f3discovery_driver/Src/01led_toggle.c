/*
 * 01led_toggle.c
 *
 *  Created on: Sep 9, 2021
 *      Author: robot
 */
#include "stm32f3discovery.h"


int main(void)
{
	GPIO_Handle_t gpio;
	gpio.pGPIOx = GPIOE;
	gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
	gpio.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpio.GPIO_PinConfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
	gpio.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;

	GPIO_PeriClockControl(GPIOE, ENABLE);
	GPIO_Init(&gpio);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOE, GPIO_PIN_NO_8);
		for(uint32_t i=0; i<500000;i++);
	}
	return 0;
}
