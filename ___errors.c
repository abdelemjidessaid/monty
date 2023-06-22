#include "monty.h"

/**
 * div_error - function that prints errors about subtraction instruction.
 * @type: type of error.
 * @line_number: number of current instruction's line.
 * Return: void.
*/
void div_error(int type, unsigned int line_number)
{
	if (type == 1)
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	else if (type == 0)
		fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
}
