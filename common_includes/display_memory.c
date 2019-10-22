#include "MemoryTest.h"
//frdm_includes/display_memory.c:7:14: warning: returning 'uint32_t' {aka 'long unsigned int'} from a function with return type 'uint32_t *' {aka 'long unsigned int *'} makes pointer from integer without a cast [-Wint-conversion]

uint32_t * display_memory(uint32_t * loc, size_t length)
{
	int i = 0;
	for (int i = 0; i < length; i++)
		return (uint32_t *)(loc[i]);
} 
