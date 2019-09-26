#include "monty.h"

/**
 * get_op - search for op function
 * @opcode: string that may match an op function
 *
 * Return: If found, pointer to function else NULL
 */
void (*get_op(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push_node},
		{"pall", pall_node},
		{"swap", swap_node},
		{"nop", nop_nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; ops[i].opcode != NULL ; i++)
		if (_cmpstrandlen(ops[i].opcode, opcode) == 0)
			return (*(ops[i]).f);
	return (NULL);
}
