/*
 * @file MemoryTest.h
 * @brief Header file which contains info shared between different .c files
 *
 * This header file  contains info shared between different .c files for the
 * Memory tests
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 3 2019
 * @verison 1.0
 */
#ifndef _MEMORY_TEST_H
#define _MEMORY_TEST_H

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#if defined frdm_debug || frdm_release
	#include "../frdm_includes/ledControl.h"
#endif

#if defined pc_debug || pc_release
	#include "../pc_includes/ledControl.h"
#endif

typedef enum mem_statusop
{
	SUCCESS = 0, // no error
	FAILED, // failure case
	WARNING
}mem_status;

// mem_statusop mem_status;

/*
 * @brief Allocate a block of memory for the test
 * 
 * This function allocates a block of memory based on
 * the number of bytes specified in the argument
 * 
 * @parameter  number of bytes to allocate
 * @return Returns a pointer to the allocated memory
 */
uint32_t * allocate_words(size_t length);

/*
 * @brief Clears a block of memory for the test
 * 
 * This function clears a block of memory based on
 * the address specified in the argument
 * 
 * @parameter  address of the memory block
 * @return void
 */
void free_words(uint32_t * src);

uint8_t * display_memory(uint32_t * loc, size_t length);

mem_status write_memory(uint32_t * loc, uint8_t value);

mem_status invert_block(uint32_t * loc, size_t length);

mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed);

uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed);

uint32_t *get_address(uint32_t * base_addr, uint32_t offset);

void gen_pattern(uint8_t* pattern, uint8_t length, uint8_t seed);

#endif
