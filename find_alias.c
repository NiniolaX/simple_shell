#include "shell.h"

/**
 * find_alias - Checks the alias linked list for a match
 * @cmd: Command to check for in alias list
 * Return: Pointer to alias value or NULL
 */
char *find_alias(char *cmd)
{
	alias_s *p = head;

	while (p != NULL)
	{
		if (_strcmp(p->name, cmd) == 0)
			return (p->value);
		p = p->next;
	}

	return (NULL);
}
