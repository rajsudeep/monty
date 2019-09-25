#include "monty.h"

/**
 * splitstr - splits string into corresponding words
 * @line: string to split
 * @tokens: buffer to place the words into
 *
 * Return: On success 0
 */
int splitstr(char *line, char *tokens[])
{
	int i;
	char *token;

	token = strtok(line, " \n");
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\t");
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

/**
 * _cmpstrandlen - compares two strings and compares the length of the strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: If strings are the "same" return 0 else 1
 */
int _cmpstrandlen(char *s1, char *s2)
{
	if (!strcmp(s1, s2) && (strlen(s1) == strlen(s2)))
		return (0);
	else
		return (1);
}

/**
 * is_num - check the characters of a string is a number
 * @str: string to test
 *
 * Return: If successful 1, else 0 on failure
 */
int is_num(char *s)
{
	int i = 0;

	if (s == NULL || s[0] == '\0')
		return (0);
	if (s[i] == '-')
	{
		if (s[i + 1] == '-')
			return (0);
		if (s[i + 1] == '\0')
			return (0);
		i++;
	}
	while (s[i] != '\0')
	{
		if (isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
