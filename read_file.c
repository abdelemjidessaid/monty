#include "monty.h"

/**
 * read_file - function that a given reads file, line by line.
 * Return: void.
 */
void read_file(void)
{
	unsigned int count = 1;
	char *opcode;
	function f;

	var.line = malloc(sizeof(char) * BUF_SIZE);
	if (!var.line)
		malloc_error();

	while (fgets(var.line, sizeof(char) * BUF_SIZE, var.file))
	{
		var.array = split_line(var.line);
		if (var.array)
		{
			opcode = var.array[0];
			if (strcmp(opcode, "push") == 0)
			{
				if (!var.array[1])
					push_error(count);
				if (!is_num(var.array[1]))
					push_error(count);
				var.inst_code = atoi(var.array[1]);
			}

			f = find_function(opcode);
			if (f == NULL)
				inst_error(count, opcode);

			f(var.stack, count);
		}
		free_array(var.array);
		count++;
	}
	free(var.line);
}

/**
 * free_array - function that frees the array used in read_file function.
 * @array: array of strings.
 * Return: void.
*/
void free_array(char **array)
{
	int i = 0;

	if (!array)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
