#include "monty.h"

/**
 *
 *
 *
 */
int main(int ac, char **av)
{
	FILE *fp;
	size_t len = 0;
	ssize_t read = 0;
	char *line = NULL;
	int linenumber;
	char **args;

	fp = fopen(av[1], "r");
	read = getline(&line, &len, fp);
	for (linenumber = 1; read != -1; linenumber++)
	{
		args = strtow(line, " \t\r\n\v\f");
		if (strcmp(args[0], "push") == 0)
			printf("Success!");
	}
	if (read == -1)
		exit(EXIT_FAILURE); /* fprintf ADD */

	return (EXIT_SUCCESS);
}

char **strtow(char *str, char *delim)
{
	int i = 0, j = 0, k = 0, wordcount = 0, strlength = 0, tmplength = 0;
	char **words;

	if (str == NULL || strlen(str) == 0)
		return (NULL);
	strlength = strlen(str);
	wordcount = count_words(str, delim);
	if (wordcount == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (wordcount + 1));
	if (words == NULL)
		return (NULL);
	for (i = 0; i < strlength; i++)
	{
		if (_strpbrk(delim, str[i]) == 0)
		{
			for (k = i, tmplength = 0; str[k] != '\0' &&
				     _strpbrk(delim, str[k]) == 0; k++)
				tmplength++;
			words[j] = malloc(sizeof(char) * (tmplength + 1));
			if (words[j] == NULL)
			{
				free(words);
				for (k = 0; k <= j; k++)
					free(words[k]);
				return (NULL);
			}
			k = 0;
			while (str[i] != '\0' && _strpbrk(delim, str[i]) == 0)
			{
				words[j][k] = str[i];
				i++;
				k++;
			}
			words[j][k] = '\0';
			j++;
		}
	}
	words[j] = NULL;
	return (words);
}

int _strpbrk(char *s, char accept)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == accept)
			return (1);
	}

	return (0);
}

int count_words(char *str, char *delim)
{
	int i;
	int count = 0, word = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (_strpbrk(delim, str[i]) == 0 && word == 0)
		{
			count++;
			word = 1;
		}
		else if (_strpbrk(delim, str[i]) == 1)
		{
			word = 0;
		}
	}

	return (count);
}
