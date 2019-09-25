#include "monty.h"

/**
 *
 *
 *
 */
void (*get_op(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push_node},
		{"pall", pall_node},
		{NULL, NULL}
	};
	int i;

	for (i = 0; ops[i].opcode != NULL ; i++)
		if (_cmpstrandlen(ops[i].opcode, opcode) == 0)
			return (*(ops[i]).f);
	return (NULL);
}
