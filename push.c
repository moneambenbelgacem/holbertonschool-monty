#include "monty.h"
void push(stack_t **stack, int value) {
  stack_t *node = malloc(sizeof(stack_t));
  node->n = value;
  node->prev = NULL;
  node->next = *stack;
  if (*stack != NULL)
    (*stack)->prev = node;
  *stack = node;
}