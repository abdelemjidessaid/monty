#include "monty.h"

/**
 * _add - function that add top two numbers of stack to each other
 * and inserts the result as top instread of them.
 * @stack: pointer of pointer to stack.
 * @line_number: number of current instruction's line.
 * Return: void.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (!stack || !(*stack) || !(*stack)->next)
		add_error(line_number);

	top = *stack;
	next = top->next;
	next->n += top->n;
	*stack = next;
	free(top);
}

/**
 * _nop - function that do nothing.
 * @stack: pointer of pointer to stack.
 * @line_number: number of instruction's line.
 * Return: void.
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - function that subtract the top element of stack from the second.
 * @stack: pointer of pointer to stack.
 * @line_number: number of instruction's line.
 * Return: void.
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (!stack || !(*stack) || !(*stack)->next)
		sub_error(line_number);

	top = *stack;
	next = top->next;

	next->n -= top->n;
	next->prev = NULL;
	*stack = next;
	free(top);
}

/**
 * _div - function that divides the second top element by the top.
 * @stack: pointer of pointer to stack.
 * @line_number: number of instruction's line.
 * Return: void.
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (!stack || !(*stack) || !(*stack)->next)
		div_error(1, line_number);

	if ((*stack)->n == 0)
		div_error(0, line_number);

	top = *stack;
	next = top->next;

	next->n /= top->n;
	next->prev = NULL;
	*stack = next;
	free(top);
}
