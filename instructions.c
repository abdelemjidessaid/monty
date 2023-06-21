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
