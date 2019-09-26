#include "monty.h"

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
