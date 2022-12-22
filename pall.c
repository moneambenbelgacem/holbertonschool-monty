#include "monty.h"
void pall(stack_t *stack) {
  stack_t *node = stack;
  while (node != NULL) {
    printf("%d\n", node->n);
    node = node->next;
  }
}