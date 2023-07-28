#include "shell.h"
#include "main.h"

/**
 * free_args - Frees an array of strings
 * @av: Pointer to array of strings
 * Return: Void
 */
void free_args(char ***av)
{
	int i = 0;

	if ((*av) == NULL || av == NULL)
	{
		_printf("hsh: free_args: NULL pointer\n");
		return;
	}

	while ((*av)[i] != NULL)
	{
		free((*av)[i]);
		(*av)[i] = NULL;
		i++;
	}

	free(*av);
	*av = NULL;
}
