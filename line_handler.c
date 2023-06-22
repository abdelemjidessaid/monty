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

	if (!line || strlen(line) == 0)
		return (NULL);
	count = word_count(line);
	if (count == 0)
		return (NULL);
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
	free(line);

	return (array);
}

/**
 * split_line - function that split lines to keywords using handle_line fuc.
 * @line: pointer to target line.
 * Return: array of keywords.
*/
char **split_line(char *line)
{
	if (line)
	{
		if (strlen(line) <= 1)
			return (NULL);
		return (handle_line(_strdup(line)));
	}
	return (NULL);
}

