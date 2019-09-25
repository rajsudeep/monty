#include "monty.h"

/**
 * *push_node - Calls Function
 * @stack: pointer to pointer stack
 * @line_number: count...
 * Description: Function that adds a new node at the top of a stack
 *
 * Return: 0
 */
void push_node(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (!is_num(data.n))	
	{
		fprintf(stderr, "L%u: usage: push integer\n", data.l_num);
		free(data.line);
		fclose(data.fp);
		exit(EXIT_FAILURE);
	}

	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
		return;

	newNode->n = atoi(data.n);
	newNode->next = (*stack);
	newNode->prev = NULL;

	if (*stack)
		(*stack)->prev = newNode;
	(*stack = newNode);
	return;
}

/**
 * pall_node - Calls Function
 * @stack: Pointer to stack
 * @line_number: count...
 * Description: Function that prints all elements of stack
 * Return: 0
 */
void pall_node(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *tmp = *stack;
	int count;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		count++;
	}
}

/**
 * pop_nodes - Calls Function
 * @stack: Pointer to stack
 * @line_number: count...
 * Description: Function that deletes an element from a stack
 * Return: 0
 */
//void pop_nodes(stack_t **, unsigned int line_number)
//{
//	(void) line_number;

//}

/**
 * pint_node - Calls Function
 * @stack: Point to stack
 * @line_number: count...
 * Description: Function that prints value at the
 * top of the stack followed by newline
 * Return: 0
 */
//void pint_node(stack_t **stack, unsigned int line_number)
//{
//	(void) line_number;

//}

/**
 * swap_node - Calls Function
 * @stack: Point to stack
 * @line_number: count...
 * Description: Function that swaps two elements of stack
 * Return: 0
 */
//void swap_node(stack_t **stack, unsigned int line_number)
//{
//	(void) line_number;

//}
