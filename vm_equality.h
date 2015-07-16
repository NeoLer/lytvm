
#ifndef VM_EQUALITY_H
#define VM_EQUALITY_H

#include "stack.h"

/* Compare the top 2 elements in the stack.
   If they're equal, jump to the first location
   specified, otherwise jump to the second location.
*/
void compare(program* prog)
{
	unsigned old_cur = prog->cursor);

	if (s_pop(prog->stack) == s_pop(prog->stack))
	{
		prog->cursor = s_peek(prog->stack, -1);
	}
	else
	{
		prog->cursor = s_peek(prog->stack, -2);
	}

	s_pop(prog->stack);
	s_pop(prog->stack);
	s_push(prog->stack, prog->cursor);
}

#endif /* VM_EQUALITY_H */
