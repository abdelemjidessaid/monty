#include "monty.h"

/**
 * pint_error - function that prints an error about pint instruction.
 * @line_number: number of current line.
 * Return: void.
*/
void pint_error(unsigned int line_number)
{
	fclose(var.file);
	free(var.line);
	free_stack();
	free_array(var.array);
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
	fclose(var.file);
	free(var.line);
	free_stack();
	free_array(var.array);
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * swap_error - function that prints an error about swap.
 * @line_number: number of current line.
 * Return: void.
*/
void swap_error(unsigned int line_number)
{
	fclose(var.file);
	free(var.line);
	free_stack();
	free_array(var.array);
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * add_error - function that prints an error about add.
 * @line_number: number of current line.
 * Return: void.
*/
void add_error(unsigned int line_number)
{
	fclose(var.file);
	free(var.line);
	free_stack();
	free_array(var.array);
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * sub_error - function that prints an error about sub instruction.
 * @line_number: number of current instruction's line.
 * Return: void.
*/
void sub_error(unsigned int line_number)
{
	fclose(var.file);
	free(var.line);
	free_stack();
	free_array(var.array);
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
