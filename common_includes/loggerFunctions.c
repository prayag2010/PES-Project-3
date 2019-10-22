/*
 * loggerFunctions.c
 *
 *  Created on: Oct 20, 2019
 *      Author: rahul
 */

#include "loggerFunctions.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

//Enable the logger
void log_enable(void)
{
	loggerEnable = true;
}

//Disable the logger
void log_disable(void)
{
	loggerEnable = false;
}

//Give status of the logger
bool log_status(void)
{
	return(loggerEnable);
}


//Log data at a certain address till length
void log_data(uint32_t *inAddress, size_t length)
{
	if(loggerEnable){
		for(size_t i = 0; i < length; i++){
			printf("%p: ", inAddress + i);
			log_integer((inAddress + i));
		}
		printf("\n");
	}
}

//Print a string
void log_string(char *inString)
{
	if(loggerEnable)
		printf("%s\n", inString);
}

//Print an integer
void log_integer(uint32_t *inAddress)
{
	if(loggerEnable)
		printf("%d\n", *inAddress);
}
