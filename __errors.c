#include "monty.h"

/**
 * pint_error - function that prints an error about pint instruction.
 * @line_number: number of current line.
 * Return: void.
*/
void pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * pop_error - function that prints an error about pop instruction.
 * @line_number: number of current line.
 * Return: void.
*/
void pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}
