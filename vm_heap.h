
#ifndef VM_HEAP_H
#define VM_HEAP_H

#include "vm_stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
	Implements the VM's heap

	A 'store' refers to some memory in the heap,
	but note that h_new creates a new heap, while
	h_create_store creates a new store in an
	existing heap.
*/

typedef struct heap
{
	void**   conts;
	unsigned size;
} heap;


heap* h_new(unsigned start_size)
{
	heap* h  = (heap*)malloc(sizeof(heap));
	h->size  = start_size;
	h->conts = (void**)malloc(sizeof(void*) * start_size);
	return h;
}

unsigned h_create_store(heap* heap, unsigned store_size)
{
	unsigned i;

	for (i = 0; i < heap->size; ++i)
		if (heap->conts[i] == NULL)
		{
			heap->conts[i] = (void*)malloc(store_size);
			return i;
		}

	heap->conts = (void**)realloc(heap->conts, (size_t)(1.3 * heap->size + 3));

	return h_create_store(heap, store_size);
}

void* h_get_store(heap* heap, unsigned addr)
{
	return heap->conts[addr];
}

void free_heap_store(heap* heap, unsigned addr)
{
	if (heap->conts[addr] != NULL)
		free(heap->conts[addr]);
}

void h_set(heap* heap, unsigned set_to, unsigned addr)
{
	//heap->conts[addr] = set_to;
}

void h_write(heap* heap, unsigned addr, unsigned offset, unsigned bytes, unsigned data_addr)
{
	memcpy((char*)heap->conts[addr] + offset, heap->conts[data_addr], bytes);
}

/* Load some variables, probably from a file, to the heap.
   Format:
     [unsigned n_items][ [unsigned addr][unsigned len][void* data], ... ]
 */
void h_load_data(heap* heap, void* dat)
{ /*
	unsigned items = ((unsigned*)dat)[0];
	unsigned indx;
	for (indx=0; indx < items; ++i)
	{
		memcpy(
			heap->conts[(unsigned)* &(((char*)dat)[dindx])],
			(unsigned)((char*)dat)[dindx + 1],
			((char*)dat) + dindx 
		);
		dindx += (unsigned)* &((char*)dat)[dindx+1];
	} */
}


#endif /* VM_HEAP_H */
