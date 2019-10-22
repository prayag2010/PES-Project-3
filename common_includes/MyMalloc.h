#ifndef _MYMALLOC_H
#define _MYMALLOC_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

char memory[4*1024];
char *mem;
//__attribute__ ((section(".memory"))) extern char memory[4*1024] ;


struct block
{
	 size_t size;
	 int free;
	 struct block *next; 
};

extern struct block *freeMyList;

void initialize();
void split(struct block *fitting_slot,size_t size);
void *MyMalloc(size_t noOfBytes);
void merge();
void MyFree(void* ptr);

#endif
