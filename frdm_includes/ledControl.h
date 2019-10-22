/*
 * ledControl.h
 *
 *  Created on: Oct 21, 2019
 *      Author: rahul
 */

#ifndef FRDM_INCLUDES_LEDCONTROL_H_
#define FRDM_INCLUDES_LEDCONTROL_H_

#include "../board/board.h"



/*
 * @brief Initializes the LED pins
 *
 * Enables the clocks, sets pins as outputs, etc for the LEDs
 * using the built in SDK functions
 *
 * @return void
 */
void init_pins();


/*
 * @brief Turns off all LEDs
 *
 * Turns off all RGB leds
 *
 * @return void
 */
void offLED();


/*
 * @brief Change LED color
 *
 * Change LED color to red
 *
 * @return void
 */
void setRed();


/*
 * @brief Change LED color
 *
 * Change LED color to green
 *
 * @return void
 */
void setGreen();


/*
 * @brief Change LED color
 *
 * Change LED color to blue
 *
 * @return void
 */
void setBlue();

#endif /* FRDM_INCLUDES_LEDCONTROL_H_ */
