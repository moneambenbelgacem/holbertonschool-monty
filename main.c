#include "monty.h"

int main(__attribute__ ((unused)) int argc, char *argv[]) {

stack_t *stack = NULL;
char *filename;
FILE *fp;
char line[MAX_LINE_LENGTH];
char *opcode, * arg;
int value;

filename = argv[1];
fp = fopen(filename, "r");
if(fp == NULL)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
    exit(EXIT_FAILURE);
}

while(fgets(line,MAX_LINE_LENGTH,fp) != NULL)
{
	opcode = strtok(line, " \n");
	if(strcmp(opcode, "push") == 0){
		arg = strtok(NULL , " \n");
		value = atoi(arg);
		push(&stack , value);
	}else if (strcmp(opcode , "pall") == 0)
	{
		pall(stack);
	}else{
		 fprintf(stderr, "Error: invalid opcode\n");
      exit(EXIT_FAILURE);
	}
}
fclose(fp);
return (0);
}