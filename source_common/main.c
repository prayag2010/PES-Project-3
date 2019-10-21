#include <stdio.h>
#include <stdlib.h>
#include "../frdm_includes/MyMalloc.h"
#include "../frdm_includes/MemoryTest.h"
#include "../frdm_includes/loggerFunctions.h"

enum mem_status;
//struct block *freeList=(void*)memory;

bool loggerEnable = false;

int main()
{


	log_enable();
	uint32_t *myBlock = allocate_words(16);
	printf("Address of myblock %p\n",myBlock);

	log_string("Write pattern and display");
//	printf("Write pattern and display\n");
	write_pattern(myBlock, 16, 7);
	log_data(myBlock, 16);

	log_string("verify pattern and display");
//	printf("verify pattern and display\n");
	uint32_t *temp = verify_pattern(myBlock, 16, 7);
	log_data(temp, 16);


	uint32_t *offsetAddr = get_address(myBlock, (uint32_t)2);
	if(write_memory(offsetAddr, 0xFFEE) == FAILED)
	{
		//LOG STRING MEM PATTERN FAILED
		log_string("Writing memory pattern failed");
	}
	log_string("Write 0xffee and display");
//	printf("Write 0xffee and display\n");
	log_data(myBlock, 16);

	log_string("Verify and display");
//	printf("Verify and display\n");
	temp = verify_pattern(myBlock, 16, 7);
	log_data(temp, 16);


	log_string("Write pattern again and display");
//	printf("Write pattern again and display\n");
	write_pattern(myBlock, 16, 7);
	log_data(myBlock, 16);

	log_string("Verify and display");
//	printf("Verify and display\n");
	temp = verify_pattern(myBlock, 16, 7);
	log_data(temp, 16);


	offsetAddr = get_address(myBlock, (uint32_t)2);
	if( invert_block(offsetAddr, 4))
	{

	}
	log_string("Invert 4 bytes and display");
//	printf("Invert 4 bytes and display\n");
	log_data(myBlock, 16);

	log_string("Verify and display");
//	printf("Verify and display\n");
	temp = verify_pattern(myBlock, 16, 7);
	log_data(temp, 16);


	offsetAddr = get_address(myBlock, (uint32_t)2);
	if( invert_block(offsetAddr, 4))
	{

	}
	log_string("Invert 4 bytes again and display");
//	printf("Invert 4 bytes again and display\n");
	log_data(myBlock, 16);

	temp = verify_pattern(myBlock, 16, 7);
	log_string("Verify and display");
//	printf("Verify and display\n");
	log_data(temp, 16);

	return 0;

}

