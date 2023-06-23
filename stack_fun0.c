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

/**
* _pchar - prints the char at the top of the stack.
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _pchar(stack_t **stack, unsigned int line_num)
{
stack_t *new;

new = *stack;
if (!new)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
exit_fail(stack);
}

if ((new->n >= 65 && new->n <= 90) || (new->n >= 97 && new->n <= 122))
{
printf("%c\n", new->n);
}
else
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
exit_fail(stack);
}
}

/**
* _pstr - prints the string starting at the top of the stack
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _pstr(stack_t **stack, unsigned int line_num)
{
stack_t *new;
(void)line_num;

new = *stack;

while (new != NULL)
{
if ((new->n >= 65 && new->n <= 90) || (new->n >= 97 && new->n <= 122))
{
printf("%c", new->n);
}
else
{
break;
}
new = new->next;
}
printf("\n");
}


/**
* _rotl - prints the string starting at the top of the stack
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _rotl(stack_t **stack, unsigned int line_num)
{
stack_t *new;
(void)line_num;

if (*stack == NULL)
return;

new = malloc(sizeof(stack_t));
if (new == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit_fail(stack);
}
if (*stack)
new->n = (*stack)->n;

delete_dnodeint_at_index(stack, 0);
add_dnodeint_end(stack, new->n);
free(new);
}


/**
* _rotr - prints the string starting at the top of the stack
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _rotr(stack_t **stack, unsigned int line_num)
{
stack_t *new, *ne;
int x;
(void) line_num;

x = 0;

if (*stack == NULL)
return;

new = malloc(sizeof(stack_t));
if (new == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit_fail(stack);
}

ne = *stack;
while (ne)
{
if (ne->next == NULL)
new->n = ne->n;

ne = ne->next;
x++;
}
delete_dnodeint_at_index(stack, x - 1);
add_dnodeint(stack, new->n);
free(new);
}
