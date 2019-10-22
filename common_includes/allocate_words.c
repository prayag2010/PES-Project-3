/*
 * @file allocate_words.c
 * @brief The source file that contains the memory allocation functions
 *
 * This source file has the custom memory allocation function for the PC and the
 * allocation function for the KL25Z
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 20 2019
 * @verison 1.0
 */


#include "MemoryTest.h"
#include "MyMalloc.h"
#include "loggerFunctions.h"


uint32_t * allocate_words(size_t length)
{

	#if defined frdm_debug || frdm_release                  //Implementing in built malloc() for the KL25Z board
		uint32_t *temp = malloc(length * sizeof(size_t));   //Allocating a temporary block of memory to return from this function
	#endif

	#if defined pc_debug || pc_release						//Implementing custome MyMalloc() for the PC 
		uint32_t *temp = MyMalloc(length * sizeof(size_t)); //Allocating a temporary block of memory to return from this function
	#endif

	if( temp == NULL)										//Checking if the memory block got allocated
	{
		offLED();											//Switch of all LEDs before turning anything on
		setRed();											//Set Red LED on to indicate an error
		log_string("Memory allocation failed\n");			//Log that memory allocation was failed
		return NULL;										//Return NULL in-case nothing was allocated
	}
	else
		return (temp);										//Return the allocated block
}
