#include "monty.h"

/**
 * _mod - function that computes the rest of divition of
 * top element by the second.
 * @stack: pointer of pointer to stack.
 * @line_number: number of instruction's line.
 * Return: void.
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (!stack || !(*stack) || !(*stack)->next)
		mod_error(1, line_number);

	top = *stack;
	if (top->n == 0)
		mod_error(0, line_number);
	next = top->next;

	next->n %= top->n;
	next->prev = NULL;
	*stack = next;
	free(top);
}

/**
 * _pchar - function that convert the top element on stack and print
 * it as a character.
 * @stack: pointer of pointer to the stack.
 * @line_number: number of instruction's line.
 * Return: void.
*/
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int value;

	if (!stack || !(*stack))
		pchar_error(1, line_number);

	top = *stack;
	value = top->n;
	if (!is_ascii(value))
		pchar_error(0, line_number);
	printf("%c\n", value);
}

/**
 * _pstr - function that prints all elements of stack as characters,
 * and stops when stack is over or reach a value equals 0.
 * @stack: pointer of pointer to the stack.
 * @line_number: number of instruction's line.
 * Return: void.
*/
void _pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *top;
	int value;

	if (!stack)
	{
		printf("\n");
		return;
	}
	top = *stack;
	while (top)
	{
		value = top->n;
		if (value == 0 || !is_ascii(value))
			break;
		printf("%c", value);
		top = top->next;
	}
	printf("\n");
}
