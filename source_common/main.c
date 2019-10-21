#include <stdio.h>
#include <stdlib.h>
#include "../frdm_includes/MyMalloc.h"
#include "../frdm_includes/MemoryTest.h"
#include "../frdm_includes/loggerFunctions.h"

enum mem_status;
//struct block *freeList=(void*)memory;

bool loggerEnable = false;
size_t myBlockSize = 16;
int8_t seedValue = 7;
uint32_t blockOffset = 2;
uint8_t writeVal = 0xFFEE;

int main()
{


	log_enable();
	//FIX THIS FUNCTION, return null if not allocated
	uint32_t *myBlock = allocate_words(myBlockSize);
	printf("Address of myblock %p\n",myBlock);

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


	offsetAddr = get_address(myBlock, offsetAddr);
	if( invert_block(offsetAddr, sizeof(offsetAddr))) //?
	{

	}
	log_string("Invert 4 bytes and display");
//	printf("Invert 4 bytes and display\n");
	log_data(myBlock, myBlockSize);

	log_string("Verify and display");
//	printf("Verify and display\n");
	temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_data(temp, myBlockSize);


	offsetAddr = get_address(myBlock, offsetAddr);
	if( invert_block(offsetAddr, sizeof(offsetAddr)))
	{

	}
	log_string("Invert 4 bytes again and display");
//	printf("Invert 4 bytes again and display\n");
	log_data(myBlock, myBlockSize);

	temp = verify_pattern(myBlock, myBlockSize, seedValue);
	log_string("Verify and display");
//	printf("Verify and display\n");
	log_data(temp, myBlockSize);

	return 0;

}

