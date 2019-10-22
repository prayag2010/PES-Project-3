/*
 * @file malloc.c
 * @brief Source file that contains the custom allocation functions
 *
 * This source file has the custom allocation and deloc functions used for the PC
 *
 *
 * Reference:
 * http://tharikasblogs.blogspot.com/p/how-to-write-your-own-malloc-and-free.html
 *
 * @authors tharikasblogs, Rahul Ramaprasad, Prayag Milan Desai
 * @date October 20 2019
 * @verison 1.0
 */

#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "MyMalloc.h"

struct block *freeMyList = (void*)memory;                                     //Create a temporary pointer to the memory block

void initialize()
{
	freeMyList->size=(4*1024)-sizeof(struct block);							  //Initialise the size as allocate dmemory size minus the sizeof the metadata
	freeMyList->free=1;														  //Set the block status as free
	freeMyList->next=NULL;													  //Point the next pointer to NULL initially
}

void split(struct block *fitting_slot,size_t size)
{
	struct block *new=(void*)((void*)fitting_slot+size+sizeof(struct block)); //Allocate a new block which has a size of fitting slot plus the metadata
	new->size=(fitting_slot->size)-size-sizeof(struct block);				  //Set the usable size
	new->free=1;															  //Set the free status to 1
	new->next=fitting_slot->next;											  //Set the next of fitting_slot to next of new
	fitting_slot->size=size;												  //Set the value of size base on the argument
	fitting_slot->free=0;													  //Set the free status to 0
	fitting_slot->next=new;													  //Replace fitting slot block by new
}


void *MyMalloc(size_t noOfBytes)
{
	struct block *curr,*prev;												  //Declare two pointer current and previous

	void *result;															  //Declare a pointer to return from the function

	if(!(freeMyList->size))													  //Initializing the block of memory
	{
		initialize();
	}

	curr=freeMyList;														  //Initialise the current pointer

	while((((curr->size)<noOfBytes)||((curr->free)==0))&&(curr->next!=NULL))  //Traverse through the blocks if conditions are not met
	{
		prev=curr;
		curr=curr->next;
	}

	if((curr->size)==noOfBytes)                                               //When this condition is met, this block is allocated
	{
		curr->free=0;														  //Freee status is set to 0
		result=(void*)(++curr);
		return result;													      //Starting address of this block is returned
	}
	 else if((curr->size)>(noOfBytes+sizeof(struct block)))					  //If the block size is more than what's required, the block is split
	 {
		  split(curr,noOfBytes);											  //Split a larger block to a require dblock size
		  result=(void*)(++curr);
		  return result;													  //Return the starting address of the block
	 }
	else
	{
		result=NULL;														  //Return NULL when there are no free blocks available
		//printf("No sufficient memory to allocate\n");
		return result;
	}
}

void merge()
{
	struct block *curr,*prev;												  //Declare two pointer current and previous
	curr=freeMyList;														  //Initialise the current pointer
	while((curr->next)!=NULL)												  //Traverse till the end of the list
	{
		if((curr->free) && (curr->next->free))								  //Check if two continous blocks are free
		{
			curr->size+=(curr->next->size)+sizeof(struct block);			  //Merge the two blocks by adding size and pointing the current to next to the next of current->next
			curr->next=curr->next->next;
		}

		prev=curr;															  //Continue the interation
		curr=curr->next;
	}
}

void MyFree(void* ptr)
{
	if(((void*)memory<=ptr)&&(ptr<=(void*)(memory + 4096)))					 //Check if the address is valid
	{
		struct block* curr=ptr;												 //Store the passed pointer in a current pointer variable
		--curr;																 //Decrement the pointer
		curr->free=1;														 //Set the free status to 1
		merge();															 //Call the merge function
	}
	else
		printf("Please provide a valid pointer allocated by MyMalloc\n");
}
