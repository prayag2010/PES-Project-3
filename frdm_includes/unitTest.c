/*
 * unitTest.c
 *
 *  Created on: 22-Oct-2019
 *      Author: prayag
 */
#include "../uCUnit/uCUnit.h"
#include <stdint.h>
#include "../common_includes/MemoryTest.h"
#include "unitTest.h"


void unitTest(void)
{
	UCUNIT_Init();
	UCUNIT_TestcaseBegin("Unit test on pointers and values");

	UCUNIT_WriteString("Checking if a allocated pointer is NULL\n");
	uint32_t *testBlock = NULL;
	UCUNIT_CheckIsNotNull(testBlock);

	UCUNIT_WriteString("Checking if a allocated pointer is NULL, after malloc\n");
	testBlock = allocate_words(10);
	UCUNIT_CheckIsNotNull(testBlock);

	UCUNIT_WriteString("Checking if a value of generated pattern is 0 (0 = not changed)\n");
	write_pattern(testBlock, 10, 4);
	uint32_t *verifyTestBlock = verify_pattern(testBlock, 10, 4);
	UCUNIT_CheckIsEqual(verifyTestBlock[1], 0);

	UCUNIT_WriteString("Checking if first value of pattern is larger than seed\n");
	testBlock[1] = 77;
	UCUNIT_CheckIsInRange(testBlock[1],0,5);
	verifyTestBlock = verify_pattern(testBlock, 10, 4);
	UCUNIT_WriteString("Verifying value after manually changing it\n");
	UCUNIT_CheckIsEqual(verifyTestBlock[1], 0);

	UCUNIT_WriteString("Resetting to original values and checking again\n");
	write_pattern(testBlock, 10, 4);
	verifyTestBlock = verify_pattern(testBlock, 10, 4);
	UCUNIT_CheckIsEqual(verifyTestBlock[1], 0);

	uint32_t *offsetAddrTest = get_address(testBlock, 2);

	UCUNIT_WriteString("Checking if the value of an offset is 0\n");
	UCUNIT_CheckIsEqual(offsetAddrTest, 0);
	uint32_t temp;

	UCUNIT_WriteString("Checking if a variable is 8 bit\n");
	UCUNIT_CheckIs8Bit(temp);
	UCUNIT_WriteString("Checking if a variable is 16 bit\n");
	UCUNIT_CheckIs16Bit(temp);
	UCUNIT_WriteString("Checking if a variable is 32 bit\n");
	UCUNIT_CheckIs32Bit(temp);

	UCUNIT_WriteSummary();
	UCUNIT_Shutdown();
}
