/*
 * ledControl.c
 *
 *  Created on: Oct 21, 2019
 *      Author: rahul
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
