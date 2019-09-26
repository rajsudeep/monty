#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct data_s - contains data
 * @n: string equivalent of a potential op input
 * @line: line interpreted and read from file
 * @fp: file to be read
 * @l_num: count of number of lines read
 * @head: global stack
 *
 * Description: contains information to use throughout
 * interpretation instructions
 */
typedef struct data_s
{
	char *n;
	char *line;
	FILE *fp;
	unsigned int l_num;
	stack_t *head;
} data_t;

data_t data;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* string helper functions */
int splitstr(char *line, char *tokens[]);
int only_delims(char *line);
int _cmpstrandlen(char *s1, char *s2);
int is_num(char *s);

/* op functions */
void (*get_op(char *opcode))(stack_t **stack, unsigned int line_number);
void push_node(stack_t **stack, unsigned int line_number);
void pall_node(stack_t **stack, unsigned int line_number);
void nop_nop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);

#endif /* MONTY_H */
