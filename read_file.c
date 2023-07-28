#include "shell.h"
#include "main.h"

/**
 * read_file - Reads command line from a file
 * Return: Pointer to command line on success, NULL on fail
 */

char *read_file(void)
{
	size_t buffsize = 1024, i = 0;
	int c;
	char *cmdline, *cmdlinecp;

	/* Allocate memory for command line */
	cmdline = malloc(sizeof(char) * buffsize);
	if (cmdline == NULL)
	{
		_printf("hsh: read_line: Memory allocation error\n");
		return (NULL);
	}

	while (1)
	{
		c = getchar();
		if (c == EOF)
		{
			free(cmdline);
			return (NULL);
		}
		else if (c == '\n')
		{
			cmdline[i] = '\0';
			return (cmdline);
		}
		else
			cmdline[i] = c;
		if (i + 1 == buffsize)
		{
			buffsize += buffsize;
			cmdlinecp = malloc(sizeof(char) * buffsize);
			if (cmdlinecp == NULL)
			{
				_printf("hsh: read_line: Memory allocation error");
				return (NULL);
			}
			strcpy(cmdlinecp, cmdline);
			free(cmdline);
			cmdline = NULL;
			cmdline = cmdlinecp;
		}
		i++;
	}

	/* Remove white spaces */
	i = _strlen(cmdline);
	while (i > 0 && (cmdline[i - 1] == ' ' || cmdline[i - 1] == '\n'
			|| cmdline[i - 1] == '\t'))
	{
		cmdline[i - 1] = '\0';
		i--;
	}

	return (cmdline);
}
