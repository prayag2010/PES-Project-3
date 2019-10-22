/*
 * @file unitTest.c
 * @brief Source file has all the unit tests
 *
 * This source file contains all the unit tests called, which are defined
 * in the uCUnit.h header
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 20 2019
 * @verison 1.0
 */


#include "../uCUnit/uCUnit.h"
#include <stdint.h>
#include "../common_includes/MemoryTest.h"
#include "../frdm_includes/ledControl.h"
#include "unitTest.h"


void unitTest(void)
{
	//Initialize testing
	UCUNIT_Init();
	UCUNIT_TestcaseBegin("Unit test on pointers and values");

	//Checking if a allocated pointer is NULL
	UCUNIT_WriteString("Checking if a allocated pointer is NULL\n");
	uint32_t *testBlock = NULL;
	UCUNIT_CheckIsNotNull(testBlock);

	//Checking if a allocated pointer is NULL, after malloc
	UCUNIT_WriteString("Checking if a allocated pointer is NULL, after malloc\n");
	testBlock = allocate_words(10);
	UCUNIT_CheckIsNotNull(testBlock);

	//Checking if a allocated pointer is NULL, after malloc
	UCUNIT_WriteString("Checking if a value of generated pattern is 0 (0 = not changed)\n");
	write_pattern(testBlock, 10, 4);
	uint32_t *verifyTestBlock = verify_pattern(testBlock, 10, 4);
	UCUNIT_CheckIsEqual(verifyTestBlock[1], 0);

	//Checking if first value of pattern is larger than seed
	UCUNIT_WriteString("Checking if first value of pattern is larger than seed\n");
	testBlock[1] = 77;
	UCUNIT_CheckIsInRange(testBlock[1],0,5);
	verifyTestBlock = verify_pattern(testBlock, 10, 4);

	//Verifying value after manually changing it
	UCUNIT_WriteString("Verifying value after manually changing it\n");
	UCUNIT_CheckIsEqual(verifyTestBlock[1], 0);

	//Resetting to original values and checking again
	UCUNIT_WriteString("Resetting to original values and checking again\n");
	write_pattern(testBlock, 10, 4);
	verifyTestBlock = verify_pattern(testBlock, 10, 4);
	UCUNIT_CheckIsEqual(verifyTestBlock[1], 0);

	uint32_t *offsetAddrTest = get_address(testBlock, 2);

	//Checking if the value of an offset is 0
	UCUNIT_WriteString("Checking if the value of an offset is 0\n");
	UCUNIT_CheckIsEqual(offsetAddrTest, 0);
	uint32_t temp;

	//Checking if a variable is 8, 16 and 32 bit
	UCUNIT_WriteString("Checking if a variable is 8 bit\n");
	UCUNIT_CheckIs8Bit(temp);
	UCUNIT_WriteString("Checking if a variable is 16 bit\n");
	UCUNIT_CheckIs16Bit(temp);
	UCUNIT_WriteString("Checking if a variable is 32 bit\n");
	UCUNIT_CheckIs32Bit(temp);

	//Turn the status LED to green to indicated end of program
	offLED();
	setGreen();

	//End testing and write summary
	UCUNIT_WriteSummary();
	UCUNIT_Shutdown();
}
