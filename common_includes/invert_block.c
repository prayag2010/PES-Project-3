/*
 * @file invert_block.c
 * @brief Source file that inverts the bits at a given address
 *
 * This source file takes the location and length of data as an input,
 * and inverts them according to the length
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 20 2019
 * @verison 1.0
 */

#include "MemoryTest.h"

mem_status invert_block(uint32_t * loc, size_t length)
{
	for ( int i = 0; i < length; i++)			//Loop length number of times
	{
		*loc = *loc ^ (0x000000FF << (i * 8));	//Invert a block by XORing 8 bits with FF and shifting left one byte at a time
	}
	if (loc == NULL)							//if the passed location is NULL return error
	{
		offLED();								//Switch of all LEDs
		setRed();								//Set Red LED on
		return FAILED;							//Return FAILED enum status
	}
	else
		return SUCCESS;						    //Retun SUCCESS enum ststaus in the case of no errors
}
