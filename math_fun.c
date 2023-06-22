#include "monty.h"

/**
* _add - adds the top two elements of the stack.
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _add(stack_t **stack, unsigned int line_num)
{
stack_t *new = NULL;

new = *stack;
if (new == NULL || new->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
exit_fail(stack);
}
new->next->n = new->n + new->next->n;
*stack = new;
delete_dnodeint_at_index(stack, 0);
}


/**
* _sub - subtracts the top element from the second
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _sub(stack_t **stack, unsigned int line_num)
{
stack_t *new = NULL;

new = *stack;
if (new == NULL || new->next == NULL)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
exit_fail(stack);
}
new->next->n = new->next->n - new->n;
delete_dnodeint_at_index(stack, 0);
}

/**
* _div - divides the second top element by the top element
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _div(stack_t **stack, unsigned int line_num)
{
stack_t *new = NULL;

new = *stack;
if (new == NULL || new->next == NULL)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
exit_fail(stack);
}
if (new->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_num);
exit_fail(stack);
}
new->next->n = new->next->n / new->n;
delete_dnodeint_at_index(stack, 0);
}


/**
* _mul - multiplies the second top element with the top element
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _mul(stack_t **stack, unsigned int line_num)
{
stack_t *new = NULL;

new = *stack;
if (new == NULL || new->next == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
exit_fail(stack);
}
new->next->n = new->next->n * new->n;
delete_dnodeint_at_index(stack, 0);
}

/**
* _mod - computes the rest of the division
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _mod(stack_t **stack, unsigned int line_num)
{
stack_t *new = NULL;

new = *stack;
if (new == NULL || new->next == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
exit_fail(stack);
}
if (new->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_num);
exit_fail(stack);
}
new->next->n = new->next->n % new->n;
delete_dnodeint_at_index(stack, 0);
}
