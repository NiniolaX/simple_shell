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

/* Prototypes for custom std library functions */
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
const char *_strchr(const char *s, char c);
int _atoi(char *s);

/* Prototypes for other custom functions */
int linetoargs(char **cmdline, char ***av);
void free_args(char ***av);char *_getenv(const char *name);
int _printenv(char **environ);
char *which(char *cmd);
void signal_handler(int sig);
char *read_file(void);
void custom_perror(char *errormsg);
void custom_perror_inbuilt(char *cmd, char *arg);

#endif /* SHELL_H */
