#include "main.h"

void exit_fail(stack_t **stack)
{
if (*stack)
free_list(*stack);
exit(EXIT_FAILURE);
}

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
