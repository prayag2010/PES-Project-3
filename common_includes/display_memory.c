#include "MemoryTest.h"

uint8_t * display_memory(uint32_t * loc, size_t length)
{
	int i = 0;						  //Initialise loop counter
	uint8_t temp[length] = {0};		  //Declare a static array to return the value stored in the memory address
	for (int i = 0; i < length; i++)  //Loop length number of times
		temp[i] = loc[i];			  //Store the value stored at the address in the temporary array
	return (temp);                    //Return the temporary array
} 
