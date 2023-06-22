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
			opcode = array[0];
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
		free_array(array);
		count++;
	}
	free(line);
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
