
#ifndef VM_ARITHMETIC_H
#define VM_ARITHMETIC_H

#include "vm_stack.h"

inline void i_add(stack* stack)
{
	stack->conts[stack->size-1] += stack->conts[stack->size];
}

inline void i_sub(stack* stack)
{
	stack->conts[stack->size-1] -= stack->conts[stack->size];
}

inline void i_mul(stack* stack)
{
	stack->conts[stack->size-1] *= stack->conts[stack->size];
}

inline void i_div(stack* stack)
{
	stack->conts[stack->size-1] /= stack->conts[stack->size];
}

inline void i_mod(stack* stack)
{
	stack->conts[stack->size-1] = stack->conts[stack->size-1] % stack->conts[stack->size];
}

/* Square top of stack */
inline void i_squ(stack* stack)
{
	stack->conts[stack->size] *= 2;
}


#endif /* VM_ARITHMETIC_H */
