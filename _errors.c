#include "monty.h"

/**
 * malloc_error - function that prints a malloc error and exit with failure.
 * Return: void.
 */
void malloc_error(void)
{
	fclose(var.file);
	free(var.line);
	free_stack();
	free_array(var.array);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * cannot_open_file - function that prints error about opening file,
 * and exiting with a failure number.
 * @file_path: pointer to the file path.
 * Return: void.
 */
void cannot_open_file(char *file_path)
{
	fclose(var.file);
	free(var.line);
	free_stack();
	free_array(var.array);
	fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
}

/**
 * monty_usage - function that prints a monty usage error when monty used,
 * with wrong way.
 * Return: void.
 */
void monty_usage(void)
{
	fclose(var.file);
	free(var.line);
	free_stack();
	free_array(var.array);
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * push_error - function that prints an error of push, and exits with failure.
 * @line_number: number of line that contains the incorrect instruction.
 * Return: void.
*/
void push_error(unsigned int line_number)
{
	fclose(var.file);
	free(var.line);
	free_stack();
	free_array(var.array);
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * inst_error - function that prints an instruction error.
 * @line_number: instruction's line number.
 * @opcode: pointer to the opcode.
 * Return: void.
 */
void inst_error(unsigned int line_number, char *opcode)
{
	fclose(var.file);
	free(var.line);
	free_stack();
	free_array(var.array);
	fprintf(stderr, "L%d: unkown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
