
#ifndef VM_FILES_H
#define VM_FILES_H

#include "vm_manager.h"
#include "vm_program.h"
#include "vm_heap.h"

#include <stdio.h>
#include <stdlib.h>

#define FI_NINFO  3
#define FI_PLEN   0
#define FI_STACK  1
#define FI_HEAP   2


program* load_from_file(char* path)
{
	unsigned* pdat = (unsigned*)malloc(sizeof(unsigned) * FI_NINFO); /* program info */

	FILE *h;
	h = fopen(path, "rb");
	if (h == NULL)
	{
		fputs("Error opening file\n", stderr);
		exit(EXIT_FAILURE);
	}

	fread(pdat, sizeof(unsigned) * FI_NINFO, sizeof(unsigned), h);

	printf("%d\n", pdat[0]);
	char* pinstrs = (char*)malloc(pdat[0]);
	fread(pinstrs, pdat[0], sizeof(char), h);
	fclose(h);

	program* prog = (program*)malloc(sizeof(program));
	prog->proglen = pdat[0];
	prog->stack   = s_new(pdat[FI_STACK]);
	prog->heap    = h_new(pdat[FI_HEAP]);
	prog->instrs  = pinstrs;

	printf("instr: %d\n", pinstrs[0]);

	return prog;
}

void do_file(char* path)
{
	program* prog = load_from_file(path);
	complete_run(prog);
}

#endif /* VM_FILES_H */
