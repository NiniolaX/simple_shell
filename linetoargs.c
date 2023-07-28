#include "shell.h"
#include "main.h"

/**
 * linetoargs - Builds the argument vector of a program
 * @cmdline: Address of command line to tokenize
 * @av: Pointer to argument vector
 * Return: void
 */
int linetoargs(char **cmdline, char ***av)
{
	int i, ac = 0;
	char *tok = NULL, *tok2 = NULL, *cmdlinecp;
	const char delim[] = " \n";

	if (cmdline == NULL || *cmdline == NULL || av == NULL)
	{
		perror("hsh: linetoargs:");
		return (-1);
	}

	/* Calculate argument count */
	cmdlinecp = _strdup(*cmdline);
	if (cmdlinecp == NULL)
	{
		perror("hsh: linetoargs:");
		return (-1);
	}
	tok = strtok(cmdlinecp, delim);
	if (tok == NULL)
	{
		free(cmdlinecp);
		return (-1);
	}
	while (tok)
	{
		ac++;
		tok = strtok(NULL, delim);
	}
	free(cmdlinecp);
	cmdlinecp = NULL;

	/* Build argument vector */
	*av = malloc(sizeof(char *) * (ac + 1));
	if (*av == NULL)
	{
		perror("hsh: linetoargs:");
		return (-1);
	}
	cmdlinecp = _strdup(*cmdline);
	if (cmdlinecp == NULL)
	{
		perror("hsh: linetoargs:");
		free(*av);
		av = NULL;
		return (-1);
	}
	tok2 = strtok(cmdlinecp, delim);
	for (i  = 0; tok2 != NULL && i < ac; i++)
	{
		(*av)[i] = _strdup(tok2);
		if ((*av)[i] == NULL)
		{
			perror("hsh: linetoargs:");
			free_args(av);
			free(cmdlinecp);
			cmdlinecp = NULL;
			return (-1);
		}
		tok2 = strtok(NULL, delim);
	}
	(*av)[ac] = NULL;
	free(cmdlinecp);
	cmdlinecp = NULL;

	return (ac);
}
