#include <stdio.h>
#include <stdlib.h>
#include "../frdm_includes/MyMalloc.h"
#include "../frdm_includes/MemoryTest.h"
enum mem_status;
//struct block *freeList=(void*)memory;

int main()
{

	//	int *p = (int*)MyMalloc(1*sizeof(int));
	//	*p = 5;
	//	printf("%d\n",*p);
	//	char *q = (char*)malloc(1*sizeof(char));
	//	int *r = (int*)malloc(1*sizeof(int));
	//	free(p);
	//	char *w = (char*)malloc(8);
	//	free(r);
	//	int *k = (int*)malloc(5*sizeof(int));
	//	printf("Allocation and deallocation is done successfully!");

	uint32_t *myBlock = allocate_words(16);
	printf("Address of myblock %p\n",myBlock);

	write_pattern(myBlock, 16, 7);

	for(int i = 0; i < 16; i++)
	{
		printf("%d ",myBlock[i]);
	}
	printf("\n");

	uint32_t *temp = verify_pattern(myBlock, 16, 7);

	for(int i = 0; i < 16; i++)
	{
		printf("%p ",temp[i]);
	}
	printf("\n");
	uint32_t *offsetAddr = get_address(myBlock, (uint32_t)2);
	if(write_memory(offsetAddr, 0xFFEE) == FAILED)
	{

	}
	temp = verify_pattern(myBlock, 16, 7);
	for(int i = 0; i < 16; i++)
	{
		printf("%p ",temp[i]);
	}
	printf("\n");
	write_pattern(myBlock, 16, 7);
	temp = verify_pattern(myBlock, 16, 7);
	for(int i = 0; i < 16; i++)
	{
		printf("%p ",temp[i]);
	}
	printf("\n");
	offsetAddr = get_address(myBlock, (uint32_t)2);
	if( invert_block(offsetAddr, 4))
	{

	}
	temp = verify_pattern(myBlock, 16, 7);
	for(int i = 0; i < 16; i++)
	{
		printf("%p ",temp[i]);
	}
	printf("\n");
	offsetAddr = get_address(myBlock, (uint32_t)2);
	if( invert_block(offsetAddr, 4))
	{

	}
	temp = verify_pattern(myBlock, 16, 7);
	for(int i = 0; i < 16; i++)
	{
		printf("%p ",temp[i]);
	}
	printf("\n");

	return 0;

}

