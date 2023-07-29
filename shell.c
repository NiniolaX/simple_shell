#include "shell.h"
#include "main.h"

char *cmdline = NULL;
/**
 * signal_handler - Handles the Ctrl+C signal
 * @sig: Signal
 * Return: void
 */
void signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		_putchar('\n');
		free(cmdline);
		exit(EXIT_SUCCESS);
	}
}

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
	while (environ[i])
	{
		if (_strncmp(name, environ[i], nameLen) == 0)
			return (environ[i] + nameLen + 1);
		i++;
	}
	return (NULL);
}

/**
 * which - Returns the full path of a command
 * @cmd: Command
 * Return: Command path on success, NULL if command is not found
 */
char *which(char *cmd)
{
	struct stat fileStat;
	char *cmdpath = NULL, *dir, *path = _getenv("PATH"), *pathcpy = NULL, c = '/';
	const char delim[] = ":\n";
	int cmdpathLen;

	/* Handle path command */
	if ((_strchr(cmd, c)) != NULL)
	{
		/* Check if command is in PATH */
		if (stat(cmd, &fileStat) == 0)
		{
			/* Check if file is executable */
			if (access(cmd, X_OK) == 0)
				return (_strdup(cmd));
			else
				return (NULL);
		}
		else
			return (NULL);
	}

	/* Handle command name */
	pathcpy = _strdup(path);
	if (pathcpy == NULL)
	{
		perror("hsh: ");
		return (NULL);
	}
	dir = strtok(pathcpy, delim);
	while (dir)
	{
		cmdpathLen = _strlen(dir) + _strlen(cmd) + 2;
		cmdpath = malloc(sizeof(char) * cmdpathLen);
		if (cmdpath == NULL)
		{
			perror("hsh: ");
			free(pathcpy);
			pathcpy = NULL;
			return (NULL);
		}
		_strcpy(cmdpath, dir);
		_strcat(cmdpath, "/");
		_strcat(cmdpath, cmd);
		/* Check if path is valid */
		if (stat(cmdpath, &fileStat) == 0)
		{
			free(pathcpy);
			pathcpy = NULL;
			if (access(cmdpath, X_OK) == 0)
				return (cmdpath);
			free(cmdpath);
			cmdpath = NULL;
		}
		free(cmdpath);
		cmdpath = NULL;
		dir = strtok(NULL, delim);
	}
	free(pathcpy);
	if (cmdpath)
	{
		free(cmdpath);
		cmdpath = NULL;
	}
	return (NULL);
}

/**
 * main - A command line interpreter
 * Return: 0 on success
 */
int main(void)
{
	int ac, readline, status = 0;
	char **av = NULL;
	char *executable = NULL;
	char exitstr[] = "exit", envstr[] = "env";
	size_t linesize = 0;
	pid_t pid;
	struct stat dirStat;

	/* Set environment variables */

	while (1)
	{
		/* Implement signal handler */
		signal(SIGINT, signal_handler);

		if (isatty(STDIN_FILENO) == 1)
		{
			/* Interactive mode */
			write(STDIN_FILENO, "$ ", 2);
			if (cmdline != NULL)
				free(cmdline);
			cmdline = NULL;
			linesize = 0;
			readline = getline(&cmdline, &linesize, stdin);
			if (readline == -1)
			{
				if (feof(stdin))
				{
					_putchar('\n');
					break;
				}
				perror("hsh: ");
				continue;
			}
			else if (readline == 1)
				continue;
		}
		else
		{
			/* Non-interactive mode */
			cmdline = read_file();
		}

		if (cmdline == NULL)
			break;

		/* Build av */
		ac = linetoargs(&cmdline, &av);
		if (ac == -1 || av == NULL)
		{
			free(cmdline);
			cmdline = NULL;
			continue;
		}
		/* Check if command is exit */
		if (_strcmp(av[0], exitstr) == 0)
		{
			if (av[1])
			{
				status = _atoi(av[1]);
				if (status == -1)
				{
					custom_perror_builtin("exit", av[1]);
					status = 2;
				}
			}
			break;
		}
		/* Check if env */
		if (_strcmp(av[0], envstr) == 0)
		{
			if (_printenv() == -1)
				status = 2;
			free(cmdline);
			cmdline = NULL;
			free_args(&av);
			continue;
		}
		if (_strcmp(av[0], "setenv") == 0)
		{
			if (av[1] != NULL && av[2] != NULL)
				_setenv(av[1], av[2], 1);
			free_args(&av);
			free(cmdline);
			cmdline = NULL;
			continue;
		}
		if (_strcmp(av[0], "unsetenv") == 0)
		{
			if (av[1] != NULL)
				_unsetenv(av[1]);
			free_args(&av);
			free(cmdline);
			cmdline = NULL;
			continue;
		}
		/* Check for cd */
		if (_strcmp(av[0], "cd") == 0)
		{
			if (av[1] == NULL)
				chdir(_getenv("HOME"));
			else if (_strcmp(av[1], "-") == 0)
				chdir(_getenv("OLDPWD"));
			else if (av[1])
			{
				if (stat(av[1], &dirStat) == 0)
					chdir(av[1]);
				else
				{
					custom_perror_builtin("cd", av[1]);
					status = 2;
				}
			}
			free(cmdline);
			cmdline = NULL;
			free_args(&av);
			continue;
		}
		/* Check if program is a current directory executable */
		if (_strncmp("./", av[0], 2) == 0)
		{
			if (access(av[0], F_OK | X_OK) == 0)
			{
				executable = _strdup(av[0]);
			}
			else
			{
				custom_perror(av[0]);
				status = 2;
				free(cmdline);
				cmdline = NULL;
				free_args(&av);
				continue;
			}
		}
		else
		{
			executable = which(av[0]);
			if (executable == NULL)
			{
				errno = ENOENT;
				custom_perror(av[0]);
				status = 127;
				free(cmdline);
				cmdline = NULL;
				free_args(&av);
				continue;
			}
		}

		/* Create new process */
		pid = fork();
		if (pid == -1)
		{
			perror("hsh: ");
			free(cmdline);
			cmdline = NULL;
			free_args(&av);
			if (executable)
			{
				free(executable);
				executable = NULL;
			}
			continue;
		}
		if (pid == 0)
		{
			execve(executable, av, environ);
			if (_strcmp(executable, "cd"))
				custom_perror_builtin(executable, av[1]);
			else
				perror("hsh: ");
			exit(2);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				status = WEXITSTATUS(status);
			free(cmdline);
			cmdline = NULL;
			free_args(&av);
			free(executable);
			executable = NULL;
		}
	}
	if (av)
		free_args(&av);
	if (cmdline)
	{
		free(cmdline);
		cmdline = NULL;
	}
	linesize = 0;
	if (executable)
		free(executable);
	return (status);
}
