#include "shell.h"

/**
 * _strdup - This function duplicate a string in new memory.
 * @str: This is a string pointer
 * Return: returns a pointer to malloc
 */

char *_strdup(char *str)
{

	int i, len = 0;

	char *sptr;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	sptr = (char *) malloc(len * sizeof(char) + 1);
	if (sptr == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		sptr[i] = str[i];
	}
	sptr[i++] = '\0';

	return (sptr);
}
