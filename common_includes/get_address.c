#include "MemoryTest.h"
#include "MyMalloc.h"

uint32_t *get_address(uint32_t * base_addr, uint32_t offset)
{
	base_addr += offset;	//Increment the base address by offset to calculate the address
	return (base_addr);		//return the offset address
}
