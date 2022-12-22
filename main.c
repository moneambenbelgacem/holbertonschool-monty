#include "monty.h"

int main(__attribute__((unused)) int argc, char *argv[])
{

	stack_t *stack = NULL;
	char *filename;
	FILE *fp;
	char line[MAX_LINE_LENGTH];
	char *opcode, *arg;
	int value, line_number = 1;

	filename = argv[1];
	fp = fopen(filename, "r");
	if ((fp == NULL))
	{
		if (argc != 2)
		{
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
		}
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LENGTH, fp) != NULL)
	{
		if (strlen(line) == 1)
		{
			line_number++;
			continue;
		}
		else
		{

			opcode = strtok(line, " \n\t\r");
			if (strcmp(opcode, "push") == 0)
			{
				arg = strtok(NULL, " \n\t\r");
				if (arg == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);

					continue;
				}
				value = atoi(arg);
				push(&stack, value);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(stack);
			}
			else
			{

				fprintf(stderr, "Error: invalid opcode\n");
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
	fclose(fp);
	
	return (1);
}