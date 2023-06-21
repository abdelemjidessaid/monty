#include "monty.h"
global_var var;

/**
 * main - Entry point of monty interpreter.
 * @argc: arguments count.
 * @argv: array of char pointer, contains the arguments passed to program.
 * Return: 0 alwyas success.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
		monty_usage();

	var.file = fopen(argv[1], "r");
	if (!var.file)
		cannot_open_file(argv[1]);

	var.stack = &stack;

	read_file();

	/* free stack, array, line, header objects*/

	return (0);
}
