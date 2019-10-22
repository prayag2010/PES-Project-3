/*
 * @file main.c
 * @brief The main source file performs the memory test functions
 *
 * This source file performs memory tests and manipulation, which is the solution
 * for the PES Project 3. This file (ot the project) is capable of running on
 * two systems, a PC and a FRDM-KL25Z microcontroller
 *
 * If debug mode is selected, then the microcontroller will display the results
 * of memory tests on the terminal and via an onboard RGB LED. For release
 * version, it will just display LED statuses.
 * The OC version has a similar approach, the only difference being because
 * of no onboard LEDs, it will print the status of the LEDs on the terminal
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 19 2019
 * @verison 1.0
 */


//Include standard header files
#include <stdio.h>
#include <stdlib.h>

//Includes the header files common between the PC and FRDM-KL25Z
#include "../common_includes/MyMalloc.h"
#include "../common_includes/MemoryTest.h"
#include "../common_includes/loggerFunctions.h"

//Includes platform and target sprcific header files (FRDM)
#if defined frdm_debug || defined frdm_release
#include "../frdm_includes/ledControl.h"
#endif

//Includes platform and target sprcific header files (FRDM)
#ifdef frdm_debug
#include "../uCUnit/uCUnit.h"
#include "../frdm_includes/unitTest.h"
#endif

//Includes platform and target sprcific header files (PC)
#if defined pc_debug || pc_release
#include "../pc_includes/ledControl.h"
#endif

//status of memory
enum mem_status;

//logger enable boolean
bool loggerEnable = false;

//size of the allocation block
size_t myBlockSize = 16;

//Seed for the pattern generator
int8_t seedValue = 7;

//Offset for the test functions
uint32_t blockOffset = 2;

//Value to be written at that offset
uint32_t writeVal = 0xFFEE;

//Main routine
int main()
{

	//Initialize the LED pins for the FRDM-KL25Z
#if defined frdm_debug || defined frdm_release
	init_pins();
#endif
	//Enable or disable the logger, if required
#if defined frdm_debug || defined pc_debug
	log_enable();
#endif
#if defined frdm_release || defined pc_release
	log_disable();
#endif

	//Initial LED colour blue
	offLED();
	setBlue();

	//Allocate block of memory
	uint32_t *myBlock = allocate_words(myBlockSize);

	//Write a pattern to that location and display it
	log_string("Write pattern and display");
	write_pattern(myBlock, myBlockSize, seedValue);
	log_data(myBlock, 16);

	//Verify the pattern and display, shows an array with pointers
	//that are different from the original
	log_string("verify pattern and display");
	uint32_t *temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_data(temp, 16);

	//Calculate offset from a given address, and write a value to it
	uint32_t *offsetAddr = get_address(myBlock, blockOffset);
	if(write_memory(offsetAddr, writeVal) == FAILED)
	{
		log_string("Writing memory pattern failed");
	}
	log_string("Write 0xffee and display");
	log_data(myBlock, myBlockSize);


	//Verify the pattern and display, shows an array with pointers
	//that are different from the original
	log_string("Verify and display");
	temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_data(temp, myBlockSize);

	//Write the original pattern again, and siaplay
	log_string("Write pattern again and display");
	write_pattern(myBlock, myBlockSize, seedValue);
	log_data(myBlock, myBlockSize);


	//Verify the pattern and display, shows an array with pointers
	//that are different from the original
	log_string("Verify and display");
	temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_data(temp, 16);

	//Calculate offset from a given address, and write a value to it
	offsetAddr = get_address(myBlock, blockOffset);
	if( invert_block(offsetAddr, sizeof(blockOffset)))
	{
		setRed();
	}
	//Invert 4 bytes at the offset
	log_string("Invert 4 bytes and display");
	log_data(myBlock, myBlockSize);

	//Verify the pattern and display, shows an array with pointers
	//that are different from the original
	log_string("Verify and display");
	temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_data(temp, myBlockSize);

	//Invert 4 bytes at the offset again
	offsetAddr = get_address(myBlock, blockOffset);
	if( invert_block(offsetAddr, sizeof(blockOffset)))
	{
		setRed();
	}
	log_string("Invert 4 bytes again and display");
	log_data(myBlock, myBlockSize);

	//Verify the pattern and display, shows an array with pointers
	//that are different from the original
	temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_string("Verify and display");
	log_data(temp, myBlockSize);

	//Free the memory since we are done
	free_words(myBlock);
	free_words(temp);

	//Set the LED to green to indicate the user that program has ended
	offLED();
	setGreen();



#ifdef frdm_debug
	unitTest();
#endif

	//To stop the program from exiting main

	return 0;

}
