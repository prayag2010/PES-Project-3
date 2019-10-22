/*
 * @file free_words.c
 * @brief Source file that frees allocated memory
 *
 * This source file uses the free function for the KL25Z and
 * a custom MyFree functions for the PC to free allocated memory
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 20 2019
 * @verison 1.0
 */

#include "MemoryTest.h"
#include "MyMalloc.h"

void free_words(uint32_t* src)
{
	if (src == NULL)		   				//Check if the passed pointer is NULL
	{
		offLED();							//Turn of all LEDs
		setRed();							//Set Red LED on to indicate error
		return;								
	}
	else
	{
	#if defined frdm_debug || frdm_release  //Use inbuilt free() for KL25Z
			free(src);
	#endif
	#if defined pc_debug || pc_release		//Use custom Myfree() for PC
			MyFree(src);
	#endif
	}
}
