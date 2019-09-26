#include "monty.h"

/**
 * swap_node - swap the data within the first two nodes
 * @stack: pointer to stack
 * @line_number: count of number of commands
 */
void swap_node(stack_t **stack, unsigned int line_number)
{
	int head_n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free(data.line), free_stack(data.head), fclose(data.fp);
		exit(EXIT_FAILURE);
	}
	head_n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = head_n;
}

/**
 * add_node - add together the first two nodes
 * @stack: pointer to stack
 * @line_number: count of number of commands
 */
void add_node(stack_t **stack, unsigned int line_number)
{
	int n_sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n",
                        line_number);
                free(data.line), free_stack(data.head), fclose(data.fp);
                exit(EXIT_FAILURE);
        }
	n_sum = (*stack)->n;
	pop_node(stack, line_number);
	n_sum += (*stack)->n;
	(*stack)->n = n_sum;
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
