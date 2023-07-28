#include "shell.h"

/**
 * custom_perror_builtin - Handles errors to builtin commands
 * @cmd: Command
 * @arg: Argument
 * Return: void
 */
void custom_perror_builtin(char *cmd, char *arg)
{
	char errMsg[150] = "./hsh: ";

	if (_strcmp(cmd, "cd") == 0)
	{
		_strcat(errMsg, "1: cd: can't cd to ");
		_strcat(errMsg, arg);
		_strcat(errMsg, "\n");
	}
	else if (_strcmp(cmd, "exit") == 0)
	{
		_strcat(errMsg, "1: exit: Illegal number: ");
		_strcat(errMsg, arg);
		_strcat(errMsg, "\n");
	}

	write(STDERR_FILENO, errMsg, _strlen(errMsg));
}
