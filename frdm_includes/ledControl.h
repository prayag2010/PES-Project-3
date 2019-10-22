/*
 * @file ledControl.h
 * @brief Header file for controlling the RGB LED
 *
 * This header file has prototypes for functions that
 * turns LEDs on and off of a particular color, based
 * on the function called
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 20 2019
 * @verison 1.0
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
