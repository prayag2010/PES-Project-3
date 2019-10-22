#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "MyMalloc.h"

struct block *freeMyList = (void*)memory;

void initialize()
{
	freeMyList->size=(4*32)-sizeof(struct block);
	freeMyList->free=1;
	freeMyList->next=NULL;
}

void split(struct block *fitting_slot,size_t size)
{
	struct block *new=(void*)((void*)fitting_slot+size+sizeof(struct block));
	new->size=(fitting_slot->size)-size-sizeof(struct block);
	new->free=1;
	new->next=fitting_slot->next;
	fitting_slot->size=size;
	fitting_slot->free=0;
	fitting_slot->next=new;
}


void *MyMalloc(size_t noOfBytes)
{
	struct block *curr,*prev;

	void *result;

	if(!(freeMyList->size))
	{
		initialize();
		printf("Memory initialized\n");
	}

	curr=freeMyList;

	while((((curr->size)<noOfBytes)||((curr->free)==0))&&(curr->next!=NULL))
	{
		prev=curr;
		curr=curr->next;
		printf("One block checked\n");
	}

	if((curr->size)==noOfBytes)
	{
		curr->free=0;
		result=(void*)(++curr);
		printf("Exact fitting block allocated\n");
		return result;
	}
	 else if((curr->size)>(noOfBytes+sizeof(struct block)))
	 {
		  split(curr,noOfBytes);
		  result=(void*)(++curr);
		  printf("%p\n",result);
		  printf("Fitting block allocated with a split\n");
		  return result;
	 }
	else
	{
		result=NULL;
		printf("No sufficient memory to allocate\n");
		return result;
	}
}

void merge()
{
	struct block *curr,*prev;
	curr=freeMyList;
	while((curr->next)!=NULL)
	{
		if((curr->free) && (curr->next->free))
		{
			curr->size+=(curr->next->size)+sizeof(struct block);
			curr->next=curr->next->next;
		}

		prev=curr;
		curr=curr->next;
	}
}

void MyFree(void* ptr)
{
	if(((void*)memory<=ptr)&&(ptr<=(void*)(memory+20000)))
	{
		struct block* curr=ptr;
		--curr;
		curr->free=1;
		merge();
	}
	else printf("Please provide a valid pointer allocated by MyMalloc\n");
}
