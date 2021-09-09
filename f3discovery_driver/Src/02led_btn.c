/*
 * 01led_toggle.c
 *
 *  Created on: Sep 9, 2021
 *      Author: robot
 */
#include "stm32f3discovery.h"


int main(void)
{
	GPIO_Handle_t gpio_led, gpio_btn;

	gpio_led.pGPIOx = GPIOE;
	gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
	gpio_led.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpio_led.GPIO_PinConfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
	gpio_led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpio_led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOE, ENABLE);
	GPIO_Init(&gpio_led);

	gpio_btn.pGPIOx = GPIOA;
	gpio_btn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	gpio_btn.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_IN;
	gpio_btn.GPIO_PinConfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
	gpio_btn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&gpio_btn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))
		{
			GPIO_ToggleOutputPin(GPIOE, GPIO_PIN_NO_8);
		}


	}
	return 0;
}
