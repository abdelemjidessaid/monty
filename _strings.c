#include "monty.h"

/**
 * word_count - function that returns the number of words in a string.
 * @line: pointer to the target string.
 * Return: number of words.
 */
int word_count(char *line)
{
	int count = 0;
	char *w, *dup = _strdup(line);

	w = strtok(dup, " \t\n");
	while (w)
	{
		count++;
		w = strtok(NULL, " \t\n");
	}

	return (count);
}

/**
 * _strdup - function that duplicates strings.
 * @str: pointer to the target string.
 * Return: address to the new string.
*/
char *_strdup(char *str)
{
	char *p;
	int i = 0;

	if (!str)
		return (NULL);
	p = malloc(sizeof(char) * BUF_SIZE);
	if (!p)
		malloc_error();
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';

	return (p);
}
