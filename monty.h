#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_LINE_LENGTH 100
#define STACK 0
#define QUEUE 1
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


typedef struct varglob
{
	int queue; 
	size_t stack_len;
}var_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_number);
stack_t *add_node(stack_t **stack, const int n);
void pall(stack_t **stack, unsigned int line_number);
void free_lineptr(int status, void *arg);
void free_stack(int status, void *arg);
void m_fs_close(int status, void *arg);
void get_op(char *op, stack_t **stack, unsigned int line_number);




#endif