#include "monty.h"

/**
 * commands - function that check the valid keywods of monty to add it
 * onto stack of operations.
 * @words: pointer of charsequence array that contains the keywors of each line
 * Return: void.
*/
void commands(char **words)
{
	unsigned int i;
	char *w;

	for (i = 0; words[i]; i++)
	{
		w = words[i];
		if (strcmp(w, "push"))
		{

		}
	}
}
