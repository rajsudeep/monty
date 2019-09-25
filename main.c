#include "monty.h"

/**
 * main - interpret lines of a bytecode file
 * @ac: number of command line input arguments
 * @av: list of arguments
 *
 * Return: EXIT_SUCCESS on success else EXIT_FAILURE
 */
int main(int ac, char **av)
{
	size_t len = 0;
	ssize_t read = 0;
	unsigned int i;
	void (*f)(stack_t **stack, unsigned int line_number);
	char *args[2];

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data.head = NULL;
	data.line = NULL;
	data.fp = fopen(av[1], "r");
	if (data.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	for (data.l_num = 1; (read = getline(&data.line, &len, data.fp)) != -1;
	     data.l_num++)
	{
		if (only_delims(data.line))
			continue;
		splitstr(data.line, args);
		data.n = args[1];
		f = get_op(args[0]);
		if (f == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				data.l_num, args[0]);
			exit(EXIT_FAILURE);
		}
		(*f)(&data.head, data.l_num);
	}
	free(data.line);
	free(data.head);
	fclose(data.fp);
	return (EXIT_SUCCESS);
}
