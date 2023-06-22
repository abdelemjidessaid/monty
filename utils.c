#include "monty.h"

/**
 * is_num - function that check a string if it contains a number of not.
 * @num: pointer to the target string.
 * Return: 1 if number, 0 otherwise.
*/
int is_num(char *num)
{
	int i;

	if (num)
	{
		for (i = 0; num[i]; i++)
			if (num[i] < '0' || num[i] > '9')
				return (0);
	}
	else
		return (1);

	return (1);
}

/**
 * find_function - function that returns the wanted callback function pointer.
 * @opcode: the command included.
 * Return: the function that could handle the included command, NULL otherwise.
*/
function find_function(char *opcode)
{
	instruction_t fs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL}
	};
	int i = 0;

	while (fs[i].opcode)
	{
		if (strcmp(fs[i].opcode, opcode) == 0)
			break;
		i++;
	}

	return (fs[i].f);
}
