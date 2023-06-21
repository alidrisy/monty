#include "monty.h"

/**
* add_dnodeint - add new element to the stack
* @stack: a pointer for the stack
* @line_number: a new element to add
* Return: a new node
*/

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

/**
* free_list - free linked list
* @head: a pointer to link list
*/

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
