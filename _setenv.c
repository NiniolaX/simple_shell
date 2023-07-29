#include <string.h>
#include "shell.h"

/**
 * _setenv - Sets a new value for an environment variable
 * @var: Environment variable name
 * @value: Environment variable value
 * @overwrite: Integer flag to overwrite or not
 * Return: 1 on success, -1 on failure
 */
int _setenv(char *var, char *value, int overwrite)
{
	int varLen = _strlen(var), valLen = _strlen(value), i, j;
	int envstrLen = varLen + valLen + 2;
	char *newVar = NULL, **environNew;

	for (i = 0; environ[i] != NULL; i++)
	{
		/* If environment variable exists */
		if (_strncmp(var, environ[i], varLen) == 0)
		{
			if (overwrite == 0)
				return (0);
			free(environ[i]);
			environ[i] = malloc(sizeof(char) * envstrLen);
			if (environ[i] == NULL)
			{
				perror("hsh: _setenv: ");
				return (-1);
			}
			_strcpy(environ[i], var);
			_strcat(environ[i], "=");
			_strcat(environ[i], value);
			return (0);
		}

		/* If environment variable does not exist */
		if ((environ[i + 1] == NULL) && (_strncmp(var, environ[i], varLen) != 0))
		{
			if (overwrite == 0)
				return (0);
			/* Build new environment variable array */
			environNew = malloc(sizeof(char *) * (i + 3));
			if (environNew == NULL)
			{
				perror("hsh: _setenv: ");
				return (-1);
			}
			/* Copy old environment variables into new env array */
			for (j = 0; environ[j] != NULL; j++)
			{
				environNew[j] = environ[j];
			}
			/* Construct new environment variable string */
			newVar = malloc(sizeof(char) * envstrLen);
			if (newVar == NULL)
			{
				printf("shell: _setenv: Memory allocation error\n");
				return (-1);
			}
			_strcpy(newVar, var);
			_strcat(newVar, "=");
			_strcat(newVar, value);
			environNew[j++] = newVar;
			environNew[j++] = NULL;

			environ = NULL;
			environ = environNew;
			return (0);
		}
	}
	return (-1);
}
