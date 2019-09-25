#include "monty.h"

/**
 * *push_node - Calls Function
 * @stack: pointer to pointer stack
 * @line_number: count...
 * Description: Function that adds a new node at the top of a stack
 * Return: 0
 */
void push_node(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	int n = 8;

	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
		return;

	newNode->n = n;
	newNode->next = (*stack);
	newNode->prev = NULL;

	if (*stack)
		(*stack)->prev = newNode;
	(*stack = newNode);
	//printf("%i \n", newNode->n);
	return;
}

/**
 * pall_nodes - Calls Function
 * @stack: Pointer to stack
 * @line_number: count...
 * Description: Function that prints all elements of stack
 * Return: 0
 */
void pall_nodes(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	int count;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
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
