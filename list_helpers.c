#include "monty.h"

/**
 * *push_node - Calls Function
 * @stack: pointer to stack
 * @line_number: count of number of commands
 * Description: Function that adds a new node at the top of a stack
 *
 * Return: 0
 */
void push_node(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	(void) line_number;

	if (!is_num(data.n))
	{
		fprintf(stderr, "L%u: usage: push integer\n", data.l_num);
		free(data.line), free_stack(data.head), fclose(data.fp);
		exit(EXIT_FAILURE);
	}

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(data.line), free_stack(data.head), fclose(data.fp);
		exit(EXIT_FAILURE);
	}

	newNode->n = atoi(data.n);
	newNode->next = (*stack);
	newNode->prev = NULL;

	if (*stack)
		(*stack)->prev = newNode;
	(*stack = newNode);
}

/**
 * pall_node - Calls Function
 * @stack: pointer to stack
 * @line_number: count of number of commands
 * Description: Function that prints all elements of stack
 * Return: 0
 */
void pall_node(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int count;
	(void) line_number;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		count++;
	}
}

/**
 * free_stack - free a stack
 * @head: doubly linked list represented as a stack
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	free_stack(head->next);
	free(head);
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
