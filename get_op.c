#include "monty.h"

/**
 *
 *
 *
 */
int (*get_op(char *opcode)) (stack_t **stack, unsigned int line_number)
{
	op_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; ops.opcode[i] != NULL ; i++)
		if (_cmpstrandlen(ops[i].opcode, opcode) == 0)
			return (ops[i].f);
	return (NULL);
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
	if (!_strcmp(s1, s2) && (_strlen(s1) == _strlen(s2)))
		return (0);
	else
		return (1);
}
