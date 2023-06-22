#include "monty.h"

/**
 * _push - function that pushs a number to the stack.
 * @stack: array of charsequences.
 * @line_number: number of the instruction.
 * Return: void.
 */
void _push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	insert_start(stack, var.inst_code);
}

/**
 * _pall - function that prints all values included onto stack.
 * @stack: pointer of pointer to stack.
 * @line_number: instruction's line number.
 * Return: void.
 */
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *p;

	if (!stack || !(*stack))
		return;

	p = *stack;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}

/**
 * pint - function that prints the top element in stack.
 * @stack: pointer of pointer to the stack.
 * @line_number: number of current line.
 * Return: void.
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	if (stack)
	{
		p = *stack;
		if (!p)
		{
			pint_error(line_number);
			exit(EXIT_FAILURE);
		}
		printf("%d\n", p->n);
	}
	else
		pint_error(line_number);
}


/**
 * _pop - function that removes the top element of stack.
 * @stack: pointer of pointer to the stack.
 * @line_number: number of current line.
 * Return: void.
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *p, *tmp;

	if (!stack)
		pop_error(line_number);
	p = *stack;
	if (!p)
		pop_error(line_number);

	tmp = p->next;
	if (!tmp)
	{
		*stack = NULL;
		free(p);
		return;
	}
	tmp->prev = NULL;
	*stack = tmp;
	free(p);
}
