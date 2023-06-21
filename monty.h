#ifndef MONTY_H
#define MONTY_H


#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;



/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*instruct_fun)(stack_t **stack, unsigned int line_number);
void open_file(stack_t **stack, char *av);
instruct_fun get_fun(char *str);
void free_list(stack_t *head);
stack_t *add_dnodeint(stack_t **head, const int n);
int is_numb(char *arg);
void _pall(stack_t **stack, unsigned int line_num);
void _push(stack_t **stack, unsigned int line_num);
void exit_fail(stack_t **stack);
char *str_tok(char *str);
void _pint(stack_t **stack, unsigned int line_num);

#endif
