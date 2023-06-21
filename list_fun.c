#include "monty.h"

stack_t *add_dnodeint(stack_t **head, const int n)
{
stack_t *new;

new = malloc(sizeof(stack_t));

if (new == NULL)
return (NULL);


if (*head == NULL)
{
new->n = n;
new->next = NULL;
new->prev = NULL;
*head = new;
return (new);
}
(*head)->prev = new;
new->n = n;
new->next = *head;
new->prev = NULL;
*head = new;
return (new);
}

void free_list(stack_t *head)
{
stack_t *new;

while (head != NULL)
{
new = head->next;
free(head);
head = new;
}
}
