#include "monty.h"

/**
* _push - pushes an element to the stack.
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _push(stack_t **stack, unsigned int line_num)
{
stack_t *new = NULL;
char *arg;
int num = 0;

new = malloc(sizeof(stack_t));
if (!new)
{
fprintf(stderr, "Error: malloc failed\n");
exit_fail(stack);
}
arg = strtok(NULL, "\n ");
if (is_numb(arg) == 1 && arg != NULL)
{
num = atoi(arg);
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", line_num);
exit_fail(stack);
}
if (but == 0)
{
add_dnodeint(stack, num);
}
if (but == 1)
{
add_dnodeint_end(stack, num);
}
free(new);
}

/**
* _pall - prints the value of the stack
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _pall(stack_t **stack, unsigned int line_num)
{
stack_t *new;
(void)line_num;

new = *stack;
while (new != NULL)
{
printf("%d\n", new->n);
new = new->next;
}
}

/**
* _pint - prints the value at the top of the stack
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _pint(stack_t **stack, unsigned int line_num)
{
stack_t *new;
new = *stack;
if (!new)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
exit_fail(stack);
}
else
printf("%d\n", new->n);
}

/**
* _pop - removes the top element of the stack.
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _pop(stack_t **stack, unsigned int line_num)
{
stack_t *new;
new = *stack;

if (!new)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
exit_fail(stack);
}
else
delete_dnodeint_at_index(stack, 0);
}

/**
* _nop - doesn’t do anything.
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _nop(stack_t **stack, unsigned int line_num)
{
	(void) line_num;
	(void) stack;
}
