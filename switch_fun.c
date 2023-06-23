#include "monty.h"

int but;
/**
* _stack - sets the format of the data to a stack (LIFO).
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _stack(stack_t **stack, unsigned int line_num)
{
(void)stack;
(void)line_num;
but = 0;
}

/**
* _queue - sets the format of the data to a queue (FIFO).
* @stack: a pointer for the stack
* @line_num: anumber of line in stack
*/

void _queue(stack_t **stack, unsigned int line_num)
{
(void)stack;
(void)line_num;
but = 1;
}
