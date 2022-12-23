#include "monty.h"

var_t varglob;

int main( int argc, char *argv[])
{

	stack_t *stack = NULL;
	unsigned int line_count = 0;
	FILE *fp = NULL;
	char *lineptr = NULL, *op = NULL;
	size_t n = 0;

	varglob.queue = 0;
	varglob.stack_len = 0;

	if(argc != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1],"r");
	if (fp == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	on_exit(free_lineptr, &lineptr);
	on_exit(free_stack, &stack);
	on_exit(m_fs_close, fp);
	while (getline(&lineptr,&n,fp) != -1)
	{
		line_count++;
		op = strtok(lineptr,"\n\t\r ");
	}
	if (op != NULL && op[0] != '#')
		{
			get_op(op, &stack, line_count);
		}
	exit (EXIT_SUCCESS);
}