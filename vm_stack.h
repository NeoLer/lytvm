
#ifndef VM_STACK_H
#define VM_STACK_H

/*
	Implementation of program stack.

	Anything can be changed, so long as
	s_push, s_pop, s_peek, s_indx and
	s_flush behave as expected.
*/

typedef struct stack
{
	unsigned  size;  /* Number of elements in stack */
	unsigned* conts; /* Stack contents */
} stack;


stack* s_new(unsigned size)
{
	stack* new_stack = (stack*)malloc(sizeof(stack));
	new_stack->conts = (unsigned*)malloc(sizeof(unsigned) * size);
	new_stack->size  = size;
	return new_stack;
}

inline void s_push(stack* st, unsigned val)
{
	++st->size;
	st->conts[st->size] = val;
}

inline unsigned s_pop(stack* st)
{
	--st->size;
	return st->conts[st->size + 1];
}

/* Return the top element of the stack */
inline unsigned s_peek(stack* st)
{
	return st->conts[st->size];
}

/* Return offset elements down in the stack */
inline unsigned s_indx(stack* st, unsigned offset)
{
	return st->conts[st->size-offset];
}

/* Reset the stack */
void s_flush(stack* st)
{
	unsigned i;

	for (i = 0; i <= st->size; ++i)
		st->conts[i] = 0;

	st->size = 0;
}

#endif /* STACK_H */
