#include "monty.h"

/**
* main - the main fun for the stack
* @ac: number of argument
* @av: apointer to argument
* Return: 0
*/

int main(int ac, char **av)
{
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit_fail(&stack);
	}
	open_file(&stack, av[1]);
	free_list(stack);
	return (0);
}
