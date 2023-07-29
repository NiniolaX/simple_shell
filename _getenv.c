#include "shell.h"

/**
 * _getenv - Gets the value of an environment variable
 * @name: Name of environment variable
 * Return: Pointer to the value of the environment variable
 */
char *_getenv(const char *name)
{
	int i = 0, nameLen;

	if (name == NULL)
	{
		perror("hsh: ");
		return (NULL);
	}
	nameLen = _strlen(name);
	while (environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], nameLen) == 0)
			return (environ[i] + nameLen + 1);
		i++;
	}
	/* Environment variable not found */
	return (NULL);
}
