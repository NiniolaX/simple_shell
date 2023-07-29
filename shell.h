#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include "main.h"

extern char **environ;
extern int status;
/**
 * struct alias - Stores all aliases available in the shell
 * @name: Alias name
 * @value: Alias value
 */
typedef struct alias
{
	char *name;
	char *value;
	struct alias *next;
} alias_s;
extern alias_s *head;
/* Prototypes for custom std library functions */
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _atoi(char *s);

/* Prototypes for other custom functions */
int linetoargs(char **cmdline, char ***av);
void free_args(char ***av);char *_getenv(const char *name);
int _printenv(void);
char *_getenv(const char *name);
int _setenv(char *var, char *value, int overwrite);
int _unsetenv(char *var);
char *which(char *cmd);
void signal_handler(int sig);
char *read_file(void);
void custom_perror(char *errormsg);
void custom_perror_builtin(char *cmd, char *arg);
void variable_replace(char ***av);
void alias_handler(char **av);
char *find_alias(char *cmd);
void free_tracked_memory_alias(void);

#endif /* SHELL_H */
