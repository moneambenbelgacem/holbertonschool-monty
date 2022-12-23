#include "monty.h"
void get_op(char *op, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t valid_ops[] = {
		{"push", push},
		{"pall", pall}
		};
		for( i = 0; valid_ops[i].opcode != NULL; i++)
		{
			if (strcmp(valid_ops[i].opcode, op) == 0)
			{
				valid_ops[i].f(stack, line_number);
			return;
			}
		}
		dprintf(STDOUT_FILENO,
		"L%u: unknown instruction %s\n",
		line_number, op);
	exit(EXIT_FAILURE);
}