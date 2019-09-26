#include "monty.h"

/**
 * div_node - divide the first two nodes
 * @stack: pointer to stack
 * @line_number: count of number of commands
 */
void div_node(stack_t **stack, unsigned int line_number)
{
	int n_div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
				line_number);
		free(data.line), free_stack(data.head), fclose(data.fp);
		exit(EXIT_FAILURE);
	}
	n_div = (*stack)->n;
	pop_node(stack, line_number);
	(*stack)->n /= n_div;
}

/**
 * mod_node - mode the first two nodes
 * @stack: pointer to stack
 * @line_number: count of number of commands
 */
void mod_node(stack_t **stack, unsigned int line_number)
{
	int n_mod = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
				line_number);
		free(data.line), free_stack(data.head), fclose(data.fp);
		exit(EXIT_FAILURE);
	}
	n_mod = (*stack)->n;
	pop_node(stack, line_number);
	(*stack)->n %= n_mod;
}
