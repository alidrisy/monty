#include "monty.h"


/**
* _swap - swaps the top two elements of the stack.
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _swap(stack_t **stack, unsigned int line_num)
{
stack_t *new;
int x;

new = *stack;
if (new == NULL || new->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
exit_fail(stack);
}
x = new->n;
new->n = new->next->n;
new->next->n = x;
}
