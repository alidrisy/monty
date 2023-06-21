#include "monty.h"


/**
* exit_fail - exit the program
* @stack: a pointer to stack
*/

void exit_fail(stack_t **stack)
{
if (*stack)
free_list(*stack);
exit(EXIT_FAILURE);
}

/**
* is_numb - chech if number or not
* @arg: string contain integer
* Return: 1 if integer 0 else
*/

int is_numb(char *arg)
{
int i;
if (arg == NULL)
return (0);

i = 0;
while (arg[i])
{
if (arg[0] == '-')
{
i++;
continue;
}
if (!isdigit(arg[i]))
return (0);
i++;
}
return (1);
}
