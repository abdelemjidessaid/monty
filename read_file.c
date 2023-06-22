#include "monty.h"

/**
 * read_file - function that a given reads file, line by line.
 * Return: void.
 */
void read_file(void)
{
	unsigned int count = 1;
	char *line, **array, *opcode;
	function f;

	line = malloc(sizeof(char) * BUF_SIZE);
	if (!line)
		malloc_error();

	while (fgets(line, sizeof(char) * BUF_SIZE, var.file))
	{
		array = split_line(line);
		if (array)
		{
			opcode = _strdup(array[0]);
			if (strcmp(opcode, "push") == 0)
			{
				if (!array[1])
					push_error(count);
				if (!is_num(array[1]))
					push_error(count);
				var.inst_code = atoi(array[1]);
			}

			f = find_function(opcode);
			if (f == NULL)
				inst_error(count, opcode);

			f(var.stack, count);
		}
		count++;
	}
	free(line);
}
