/*
	Handles running programs etc.
*/

#ifndef VM_MANAGER_H
#define VM_MANAGER_H

#include "vm_ops.h"
#include "vm_stack.h"
#include "vm_heap.h"
#include "vm_controlflow.h"
#include "vm_arithmetic.h"
#include "vm_program.h"

#include <stdio.h>
#include <stdlib.h>

/* Progress a program by 1 cycle */
void step_program(program* prog)
{
	switch (prog->instrs[prog->cursor])
	{
		case SKIP:
			break;

		case PUSH:
			s_push(prog->stack, prog->instrs[++prog->cursor]);
			break;

		case POP:
			s_pop(prog->stack);
			break;

		case SET:
			h_set(prog->heap, s_pop(prog->stack), s_pop(prog->stack));

		case WRITE:
			h_write(prog->heap, s_pop(prog->stack), s_pop(prog->stack), s_pop(prog->stack), s_pop(prog->stack));

		case IF:
			compare(prog);
			break;

		case JMP:
			jump(prog, s_pop(prog->stack));
			break;

		case RET:
			ret(prog);
			break;

		case CALLC:
			break;

		case ADD:
			i_add(prog->stack);
			break;

		case SUB:
			i_sub(prog->stack);
			break;

		case MUL:
			i_mul(prog->stack);
			break;

		case DIV:
			i_div(prog->stack);
			break;

		case MOD:
			i_mod(prog->stack);
			break;

		default:
			printf("Unrecognised instruction: %i, quitting...\n", prog->instrs[prog->cursor]);
			exit(1);
	}
	++prog->cursor;
}

void complete_run(program* prog)
{
	printf("Running...\n");
	printf("Program: curs %d, len %d\n", prog->cursor, prog->proglen);
	for (prog->cursor = 0; prog->cursor < prog->proglen; ++prog->cursor) {
		// printf("Step %d\n", prog->cursor);
		step_program(prog);
	}
}

#endif /* VM_MANAGER_H */
