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
	int status;

	if (argc != 2)
		monty_usage();

	var.file = fopen(argv[1], "r");
	if (!var.file)
		cannot_open_file(argv[1]);

	var.stack = &stack;

	read_file();
	status = fclose(var.file);
	free_stack();
	if (status == -1)
		exit(-1);

	return (0);
}

/**
 * free_stack - function that frees stack in the global var.
 * Return: void.
*/
void free_stack(void)
{
	stack_t *p, *tmp;

	if (var.stack)
	{
		p = *(var.stack);
		while (p)
		{
			tmp = p;
			p = p->next;
			free(tmp);
		}
		free(p);
	}
}
