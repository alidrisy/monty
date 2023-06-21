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
new->next = *head;
new->prev = NULL;
*head = new;
return (new);
}
new->n = n;
(*head)->prev = new;
new->next = *head;
*head = new;
return (new);
}

void free_list(stack_t *head)
{
stack_t *new;

new = head;
while (head != NULL)
{
new = head->next;
free(head);
head = new;
}
head = NULL;
}
