/*
 * @file ledControl.c
 * @brief Source file that controls the RGB LED
 *
 * This source file turns LEDs on and off of a particular color, based
 *  on the function called
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 20 2019
 * @verison 1.0
 */


#include "ledControl.h"
#include "../board/peripherals.h"
#include "../board/pin_mux.h"

void init_pins()
{
	/* Init board hardware. */
		BOARD_InitBootPins();
		BOARD_InitBootClocks();
		BOARD_InitBootPeripherals();
		/* Init FSL debug console. */
		BOARD_InitDebugConsole();

		/* Initialize LEDs */
		LED_RED_INIT(0);
		LED_GREEN_INIT(0);
		LED_BLUE_INIT(0);

		LED_RED_OFF();
		LED_GREEN_OFF();
		LED_BLUE_OFF();
}

void offLED()
{
	LED_RED_OFF();
	LED_GREEN_OFF();
	LED_BLUE_OFF();
}

void setRed()
{
	LED_RED_ON();
}

void setGreen()
{
	LED_GREEN_ON();
}

void setBlue()
{
	LED_BLUE_ON();
}
