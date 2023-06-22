#include "monty.h"

/**
 * pint_error - function that prints an error about pint instruction.
 * Return: void.
*/
void pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}