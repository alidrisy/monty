#include "monty.h"

stack_t *add_dnodeint(stack_t **head, const int n)
{
stack_t *new = NULL;

if (head == NULL)
return (NULL);
new = malloc(sizeof(stack_t));

if (new == NULL)
return (NULL);

new->n = n;
if (*head == NULL)
{
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
