/*
 * loggerFunctions.h
 *
 *  Created on: Oct 20, 2019
 *      Author: rahul
 */

#ifndef LOGGERFUNCTIONS_H_
#define LOGGERFUNCTIONS_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

extern bool loggerEnable;

/*
 * @brief Enable the logger
 *
 * This function enables the logger function
 *
 * @return void
 */
void log_enable(void);




/*
 * @brief Disable the logger
 *
 * This function disables the logger function
 *
 * @return void
 */
void log_disable(void);


/*
 * @brief Check log status
 *
 * This function returns true if the logger is enabled
 *
 * @return bool The status of the logger
 */
bool log_status(void);


/*
 * @brief Log a memory location
 *
 * This function prints the values at the inAddress continuously
 * till the desired length i.e number of data is reached
 *
 * @param *inAddress The input address whose data is to be printed
 * @param length Of how many addresses data should be printed
 * @return void
 */
void log_data(uint32_t *inAddress, size_t length);


/*
 * @brief Print a string
 *
 * This function prints a string followed by a newLine
 *
 * @param The string that has to be printed
 * @return void
 */
void log_string(char *inString);


/*
 * @brief Print an integer
 *
 * This function prints an integer followed by a newLine
 *
 * @param The integer that has to be printed
 * @return void
 */
void log_integer(uint32_t *inAddress);

#endif /* LOGGERFUNCTIONS_H_ */
