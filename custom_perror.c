#include "shell.h"

/**
 * custom_perror - Prints formatted input to stderror
 * @cmd: Command
 * Return: void
 */
void custom_perror(char *cmd)
{
	char errMsg[150] = "./hsh: 1: ";
	char *err;

	switch (errno)
	{
		case EACCES:
			err = "Permission denied";
			break;
		case ENOENT:
			err = "not found";
			break;
		case ENOTDIR:
			err = "Not a directory";
			break;
		case EISDIR:
			err = "Is a directory";
			break;
		case EFAULT:
			err = "Bad address";
			break;
		case ELOOP:
			err = "Too many symbolic links";
			break;
		case ENOMEM:
			err = "Memory allocation error";
			break;
		case EINVAL:
			err = "Illegal number";
			break;
		default:
			err = "Unknown error";
			break;
	}

	_strcat(errMsg, cmd);
	_strcat(errMsg, ": ");
	if (errno == ENOENT && _strcmp(cmd, "_getenv") == 0)
		_strcat(errMsg, "variable not found");
	else
		_strcat(errMsg, err);
	_strcat(errMsg, "\n");

	write(STDERR_FILENO, errMsg, _strlen(errMsg));
}
