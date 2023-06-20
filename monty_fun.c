#include "main.h"

void open_file(stack_t **stack, char **av)
{
	int line_num = 0;
	char *buf = NULL, *str;
	size_t n = 0;
	instruction_t fun;
	FILE *x = fopen(av, "r");
	if (x == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av);
		exit_fail(stack);
	}

	while (getline(&buf, &n, x) != -1)
	{
		str = strtok(buf, "\n ");
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
	free_list(stack);
	if (fclose(x) == -1)
		exit_fail(stack);
}

instruct_fun get_fun(char *str)
{
	int i = 0;
	instruction_t instrct[] = {
		{"push", _push},
		{"pull", _pull},
		{NULL, NULL}
	};

	while (instrct[i].f != NULL && strcmp(instrct[i].opcode, str) != 0)
		i++;
	return (instrct[i].f);
}
