#include "monty.h"

/**
 * handle_line - function that splits line into words and return it as array.
 * @line: pointer to the charsequence.
 * Return: array of words, NULL if it failed.
 */
char **handle_line(char *line)
{
	char **array, *word;
	int i = 0, count;

	if (!line)
		return (NULL);

	count = word_count(line);
	array = (char **) malloc((count + 1) * sizeof(char *));
	if (!array)
		malloc_error();

	word = strtok(line, " \t\n");
	while (word != NULL)
	{
		array[i++] = _strdup(word);
		word = strtok(NULL, " \t\n");
	}
	array[i] = NULL;

	return (array);
}

