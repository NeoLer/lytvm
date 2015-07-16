
#ifndef VM_OPS_H
#define VM_OPS_H

typedef enum instr
{
	PUSH,
	POP,
	IF,    // Compare [Top] and [Top-1]. If they are equal, JMP to [Top-2] else [Top-3].
	JMP,   // Jump to instruction at [Top], put current instruction pointer on the stack
	SKIP,  // Do nothing
	RET,   // Jump to instruction at [Top]
	ALLOC, // Allocate [Top] bytes
	PUSHH, // Push Heap[[Top]] to the stack
	WRITE, // Write [Top] bytes to Heap[[t]]
	READ,
	SET,   // Set Heap[]
	CALL,
	CALLC, //
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
} instr;

#endif /* VM_OPS_H */
