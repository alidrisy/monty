#include "monty.h"


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
add_dnodeint(stack, num);
free(new);
}

void _pull(stack_t **stack, unsigned int line_num)
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

