/*
 * @file display_memory.c
 * @briefSource file that displays content of a memory
 *
 * This source file display the contents of a memory address
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 20 2019
 * @verison 1.0
 */

#include "MemoryTest.h"
#include <stdlib.h>

uint8_t * display_memory(uint32_t * loc, size_t length)
{
	int i = 0;						        //Initialise loop counter
	uint8_t *temp = NULL;			//Declare a static array to return the value stored in the memory address
	temp = (uint8_t*)malloc(length);
	for (i = 0; i < length; i++)     	    //Loop length number of times
		temp[i] = loc[i];			        //Store the value stored at the address in the temporary array
	return (temp);                          //Return the temporary array
} 
