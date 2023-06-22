#include "monty.h"

/**
* add_dnodeint - add new element to the stack
* @head: a pointer for the stack
* @n: a new element to add
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
* add_dnodeint_end - add new element to the end of the stack
* @head: a pointer for the stack
* @n: a new element to add
* Return: a new node
*/

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
stack_t *new, *ne;

new = malloc(sizeof(stack_t));
if (new == NULL)
return (NULL);

new->n = n;
new->next = NULL;
new->prev = NULL;
if (*head == NULL)
{
*head = new;
return (new);
}
else
{
ne = *head;
while (ne->next != NULL)
{
ne = ne->next;
}
ne->next = new;
new->prev = ne;
}
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

/**
* delete_dnodeint_at_index - deletes the node at index index
* @head: a pointer to link list
* @index: is the index where the new node will delete
* Return: 1 or -1
*/

int delete_dnodeint_at_index(stack_t  **head, unsigned int index)
{
stack_t *new;
unsigned int x = 0;

new = *head;
if (*head == NULL)
return (-1);

if (index == 0 && new->next)
{
*head = new->next;
if (new->next == NULL)
return (-1);
new->next->prev = NULL;
free(new);
return (1); }
else if (index == 0 && new)
{
free(new);
*head = NULL;
return (1); }
while (new != NULL)
{
if (x == index)
{
new->prev->next = new->next;
if (new->next)
new->next->prev = new->prev;
free(new);
return (1);
}
new = new->next;
x++;
}
return (-1);
}
