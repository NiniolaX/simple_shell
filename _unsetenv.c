#include <string.h>
#include "shell.h"

/**
 * _unsetenv - Removes an environment variable
 * @var: Environment variable name
 * Return: 1 on success, -1 on failure
 */
int _unsetenv(char *var)
{
	int varLen = _strlen(var), i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		/* If environment variable exists */
		if (_strncmp(var, environ[i], varLen) == 0)
		{
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			return (0);
		}

	}
	return (0);
}
