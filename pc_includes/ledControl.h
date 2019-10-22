/*
 * ledControl.h
 *
 *  Created on: Oct 21, 2019
 *      Author: rahul
 */

#ifndef PC_INCLUDES_LEDCONTROL_H_
#define PC_INCLUDES_LEDCONTROL_H_

#include <stdio.h>


/*
 * @brief Turns off all LEDs
 *
 * Prints if all LEDs are turned off
 *
 * @return void
 */
void offLED();

/*
 * @brief Change LED color
 *
 * Print if LED has been changed to color red
 *
 * @return void
 */
void setRed();

/*
 * @brief Change LED color
 *
 * Print if LED has been changed to color green
 *
 * @return void
 */
void setGreen();

/*
 * @brief Change LED color
 *
 * Print if LED has been changed to color blue
 *
 * @return void
 */
void setBlue();

#endif /* PC_INCLUDES_LEDCONTROL_H_ */
