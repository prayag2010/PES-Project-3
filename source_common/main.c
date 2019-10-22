#include <stdio.h>
#include <stdlib.h>

#include "../common_includes/MyMalloc.h"
#include "../common_includes/MemoryTest.h"
#include "../common_includes/loggerFunctions.h"

#ifdef frdm_debug
#include "../frdm_includes/ledControl.h"
#include "../uCUnit/uCUnit.h"
#include "../frdm_includes/unitTest.h"
#endif

#ifdef pc_debug
#include "../pc_includes/ledControl.h"
#endif

enum mem_status;
//struct block *freeList=(void*)memory;

bool loggerEnable = false;
size_t myBlockSize = 16;
int8_t seedValue = 7;
uint32_t blockOffset = 2;
uint32_t writeVal = 0xFFEE;

int main()
{

#ifdef frdm_debug
	init_pins();
#endif
#if defined frdm_debug || defined pc_debug
	log_enable();
#endif
#if defined frdm_release || defined pc_release
	log_disable();
#endif
	offLED();
	setBlue();
	uint32_t *myBlock = allocate_words(myBlockSize);

	log_string("Write pattern and display");
	//	printf("Write pattern and display\n");
	write_pattern(myBlock, myBlockSize, seedValue);
	log_data(myBlock, 16);

	log_string("verify pattern and display");
	//	printf("verify pattern and display\n");
	uint32_t *temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_data(temp, 16);


	uint32_t *offsetAddr = get_address(myBlock, blockOffset);
	if(write_memory(offsetAddr, writeVal) == FAILED)
	{
		//LOG STRING MEM PATTERN FAILED
		log_string("Writing memory pattern failed");
	}
	log_string("Write 0xffee and display");
	//	printf("Write 0xffee and display\n");
	log_data(myBlock, myBlockSize);

	log_string("Verify and display");
	//	printf("Verify and display\n");
	temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_data(temp, myBlockSize);


	log_string("Write pattern again and display");
	//	printf("Write pattern again and display\n");
	write_pattern(myBlock, myBlockSize, seedValue);
	log_data(myBlock, myBlockSize);

	log_string("Verify and display");
	//	printf("Verify and display\n");
	temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_data(temp, 16);


	offsetAddr = get_address(myBlock, blockOffset);
	if( invert_block(offsetAddr, sizeof(blockOffset)))
	{
		setRed();
	}
	log_string("Invert 4 bytes and display");
	//	printf("Invert 4 bytes and display\n");
	log_data(myBlock, myBlockSize);

	log_string("Verify and display");
	//	printf("Verify and display\n");
	temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_data(temp, myBlockSize);


	offsetAddr = get_address(myBlock, blockOffset);
	if( invert_block(offsetAddr, sizeof(blockOffset)))
	{
		setRed();
	}
	log_string("Invert 4 bytes again and display");
	//	printf("Invert 4 bytes again and display\n");
	log_data(myBlock, myBlockSize);

	temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_string("Verify and display");
	//	printf("Verify and display\n");
	log_data(temp, myBlockSize);
	offLED();
	setGreen();

#ifdef frdm_debug
	unitTest();
#endif

	return 0;

}
