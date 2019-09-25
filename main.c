#include "monty.h"

int splitstr(char *line, char *tokens[])
{
        int i;
        char *token;

        token = strtok(line, " \n");
        for (i = 0; token != NULL; i++) {
                tokens[i] = token;
                token = strtok(NULL, " \n");
        }
        tokens[i] = NULL;
        return (0);
}

/**
 * only_delims - Check if line consists of only delimiters
 * @line: The line to check
 *
 * Return: 1 if true, 0 if false
 */
int only_delims(char *line)
{
	int i, j, delim_found;
	char delim[] = " \t\r\n\v\f";

	for (i = 0; line[i] != '\0'; i++)
	{
		delim_found = 0;
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (line[i] == delim[j])
				delim_found = 1;
		}
		if (!delim_found)
			return (0);
	}

	return (1);
}

int main(int ac, char **av)
{
	FILE *fp;
	size_t len = 0;
	ssize_t read = 0;
	char *line = NULL;
	int linenumber;
	char *args[2];

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	for (linenumber = 1; (read = getline(&line, &len, fp)) != -1; linenumber++)
	{
		if (only_delims(line))
			continue;
		splitstr(line, args);
		if (strcmp(args[0], "push") == 0)
			printf("Success!\n");
		printf("%d\n", linenumber);
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
