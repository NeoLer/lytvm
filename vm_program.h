
#ifndef VM_PROGRAM_H
#define VM_PROGRAM_H

#include "vm_stack.h"
#include "vm_heap.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct program
{
	char*    instrs;
	size_t   proglen;
	stack*   stack;
	heap*    heap;
	size_t   cursor;
} program;


program* init_prog(unsigned stack_size, unsigned heap_size)
{
	program* prog = (program*)malloc(sizeof(program));
	prog->stack   = s_new(stack_size);
	prog->heap    = h_new(heap_size);
	prog->cursor  = 0;
	return prog;
}

#endif /* VM_PROGRAM_H */