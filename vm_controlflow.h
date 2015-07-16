
#ifndef VM_CONTROLFLOW_H
#define VM_CONTROLFLOW_H

#include "vm_stack.h"
#include "vm_program.h"

#include <stdlib.h>
#include <stdio.h>


/* Compare the top 2 elements in the stack.
   If they're equal, jump to the first location
   specified, otherwise jump to the second location. */
void compare(program* prog)
{
	unsigned old_cur = prog->cursor;

	if (s_pop(prog->stack) == s_pop(prog->stack))
	{
		prog->cursor = s_indx(prog->stack, -1);
	}
	else
	{
		prog->cursor = s_indx(prog->stack, -2);
	}

	/* No need for the 2 locations any more */
	s_pop(prog->stack);
	s_pop(prog->stack);

	s_push(prog->stack, old_cur);
}


/* Move the instruction pointer (cursor) to jump_to,
   storing the old position in the stack (for returns) */
inline void jump(program* prog, unsigned jump_to)
{
	s_push(prog->stack, prog->cursor);
	prog->cursor = jump_to;
}


/* Jump to the location specified at the top
   of the stack. This can be used as a return
   instruction, make sure to pop everything
   else correctly */
inline void ret(program* prog)
{
	prog->cursor = s_pop(prog->stack);
}

#endif /* VM_CONTROLFLOW_H */
