#include "monty.h"

/**
 * splitstr - splits string into corresponding words
 * @line: string to split
 * @tokens: buffer to place the words into
 *
 * Return: On success 0 else 1 for failure
 */
int splitstr(char *line, char *tokens[])
{
	int i;
	char *token;

	token = strtok(line, " \n\t");
	if (token[0] == '#')
	{
		nop_nop(&data.head, data.l_num);
		return (1);
	}
	for (i = 0; token != NULL && i < 2; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\t");
	}
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

/**
 * is_num - check if the characters of a string is a number
 * @s: string to test
 *
 * Return: If successful 1, else 0 on failure
 */
int is_num(char *s)
{
	int i = 0;

	if (s == NULL || s[0] == '\0')
		return (0);
	if (s[i++] == '-')
		if (s[i + 1] == '-' || s[i + 1] == '\0')
			return (0);
	for (; s[i] != '\0'; i++)
		if (isdigit(s[i]) == 0)
			return (0);
	return (1);
}
