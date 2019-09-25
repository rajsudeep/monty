#include "monty.h"

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
		if ((f = get_op(args[0])) == NULL)
			fprintf(stderr, "L%u: unknown instruction %s\n",
				data.l_num, args[0]);
		(*f)(&data.head, data.l_num);
	}
	free(data.line);
	fclose(data.fp);
	return (EXIT_SUCCESS);
}
