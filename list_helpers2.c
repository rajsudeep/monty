#include "monty.h"

/**
 * swap_node - swap the data within the first two nodes
 * @stack: pointer to stack
 * @line_number: count of number of commands
 */
void swap_node(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *tmp2 = tmp->next;
	int head_n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free(data.line), free_stack(data.head), fclose(data.fp);
		exit(EXIT_FAILURE);
	}
	head_n = tmp->n;
	tmp->n = tmp2->n;
	tmp2->n = head_n;
}

/**
 * nop_nop - does nothing
 * @stack: pointer to stack
 * @line_number: count of number of commands
 */
void nop_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
