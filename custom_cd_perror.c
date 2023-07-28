#include "shell.h"

/**
 * custom_exit_perror - Handles errors to the exit command
 * @dir: Invalid directory
 * Return: void
 */
void custom_exit_perror(char *cmd, char *arg)
{
	char errMsg[150] = "./hsh: ";

	if (_strcmp(cmd, "cd"))
	{
		_strcat(errMsg, "cd: can't cd to ");
		_strcat(errMsg, arg);
		_strcat(errMsg, "\n");
	}
	else if (_strcmp(cmd, "exit"))
	{
		_strcat(errMsg, "exit: Illegal number: ");
		_strcat(errMsg, arg);
		_strcat(errMsg, "\n");
	}

	write(STDERR_FILENO, errMsg, _strlen(errMsg));
}
