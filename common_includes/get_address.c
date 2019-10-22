/*
 * @file get_address,c
 * @brief Source file that returns an offset of a given address
 *
 * This source file takes an address and an integer as an offset,
 * and returns a new offset address
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 20 2019
 * @verison 1.0
 */

#include "MemoryTest.h"
#include "MyMalloc.h"

uint32_t *get_address(uint32_t * base_addr, uint32_t offset)
{
	base_addr += offset;	//Increment the base address by offset to calculate the address
	return (base_addr);		//return the offset address
}
