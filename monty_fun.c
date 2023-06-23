#include "monty.h"
#include <sys/types.h>

/**
* open_file - open the monty file and get lines
* @stack: a pointer for the stack
* @av: a pointer for the file
*/

void open_file(stack_t **stack, char *av)
{
	int line_num = 1;
	char *buf = NULL, *str;
	size_t n = 0;
	instruct_fun fun;
	int i;
	int c;
	FILE *x = fopen(av, "r");

	if (x == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av);
		exit_fail(stack);
	}

	while ((c = getline(&buf, &n, x)) != -1)
	{
		str = str_tok(buf);
		if (str == NULL || str[0] == '#')
		{
			line_num++;
			continue;
		}
		fun = get_fun(str);
		if (fun == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, str);
			exit_fail(stack);
		}
		fun(stack, line_num);
		line_num++;
	}
	free(buf);
	i = fclose(x);
	if (i == -1)
		exit(-1);
}

/**
* get_fun - get the command
* @str: the name of the command
* Return: the function
*/

instruct_fun get_fun(char *str)
{
	int i = 0;
	instruction_t instrct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"mul", _mul},
		{"mod", _mod},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	while (instrct[i].f != NULL && strcmp(instrct[i].opcode, str) != 0)
		i++;
	return (instrct[i].f);
}

/**
* str_tok - get the content line by line
* @str: the string of content
* Return: string
*/

char *str_tok(char *str)
{
	char *s;

	s = strtok(str, "\n ");
	if (s == NULL)
		return (NULL);
	return (s);
}
