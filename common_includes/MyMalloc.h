/*
 * @file MyMalloc.h
 * @brief Header file which contains info shared between different .c files
 *
 * This header file  contains info shared between different .c files for the
 * Custom Malloc
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 19 2019
 * @verison 1.0
 */
 
/* REFERENCE */
/*http://tharikasblogs.blogspot.com/p/how-to-write-your-own-malloc-and-free.html- the custom malloc functions were taken from this website */
 
#ifndef _MYMALLOC_H
#define _MYMALLOC_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

char memory[4*1024];                                 //This is the declaration of the array which is considered as memory.

struct block										 //The structure definition to contain metadata of each block allocated or deallocated
{
	 size_t size;
	 int free;
	 struct block *next; 
};

extern struct block *freeMyList;                    //Extern pointer to the block used in other functions
/*
 * @brief Initialises metadata
 * 
 * This function initialises the meta data before
 * the malloc and free operations
 * 
 * @parameter  
 * @return void
 */
void initialize();

/*
 * @brief Splits a free block 
 * 
 * This function splits a larger free block
 * to allocate a requested number of bytes
 * 
 * @parameter  address of the fitting slot, size
 * @return void
 */
void split(struct block *fitting_slot,size_t size);

/*
 * @brief Alloctaes a block of memory
 * 
 * This function allocates a block of memory
 * and returns a void pointer to the starting address of the block
 * 
 * @parameter  size to be allocated
 * @return void
 */
void *MyMalloc(size_t noOfBytes);

/*
 * @brief Merges blocks
 * 
 * This function merges two continous blocks
 * if they are both unallocated after a free operation
 * 
 * @parameter  
 * @return void
 */
void merge();

/*
 * @brief Frees a block of memory
 * 
 * This function unallocates an allocated block of memory
 * if a valid pointer to the address of the memory is passed
 * 
 * @parameter  pointer to the allocated block
 * @return void
 */
void MyFree(void* ptr);

#endif
