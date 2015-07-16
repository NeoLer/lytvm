
#include <stdio.h>
#include <stdlib.h>

#include "vm_files.h"

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		do_file(argv[1]);
		printf("Run success\n");
	}
	else
	{
		printf("Err: %s\n", "usage - lytvm prog.lvm");
	}
	return 0;
}
