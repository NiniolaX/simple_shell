# SIMPLE SHELL

## DESCRIPTION

- This is a simple command-line interpreter that provides a basic command execution environment.
- It allows you to interact with your operating system, execute commands, and perform various operations.

## FEATURES

1. Handles command name (i.e. ls, pwd, etc).
2. Handles command PATH (i.e. /bin/ls, /bin/pwd, etc).
3. Handles commands with arguments (i.e. cd -, /bin/ls -la).
4. Handles the 'exit' builtin that exits the shell.
5. Handles the Ctrl+C and Ctrl+D signals.
6. Handles the 'env' builtin that prints the current environment.
7. Handles arguments to the 'exit' builtin (i.e. exit 98).
8. Handles 'setenv' and 'unsetenv' builtin to modify current environment.
9. Handles 'cd' builtin to change directory.
10. Handles 'alias' builtin.
11. Handles variable replacement wiith '$'.
12. Handles comments with '#'.
13. Works in interactive and non-interactive mode.
14. Handles errors gracefully.

## HOW TO USE

1. **Compile the source files**:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \*.c -o hsh

2. **Run the shell program**:

This shell can be used in either interactive and non-interactive mode.

- *Interactive Mode*: To run commands from the CLI.

your_cli:# ./hsh
$ ls
add                Author.md         free_args.c   main.h             _printenv.c  README.md        shell.h     _strcmp.c  _strncmp.c   variable_replace.c
alias_handler.c    custom_perror2.c  _getenv.c     memtrackeralias.c  printf.c     runchecker.bash  _sprintf.c  _strcpy.c  test_ls_2
allowed_functions  custom_perror.c   hsh           memtracker.c       _putchar.c   _setenv.c        _strcat.c   _strdup.c  TEST_SUITE
_atoi.c            find_alias.c      linetoargs.c  memtracker.h       read_file.c  shell.c          _strchr.c   _strlen.c  _unsetenv.c
$ exit
your_cli:# echo "ls" | ./hsh

- *Non-Interactive Mode*: To run commands from a script.

your_cli:# echo "ls" | ./hsh
add                Author.md         free_args.c   main.h             _printenv.c  README.md        shell.h     _strcmp.c  _strncmp.c   variable_replace.c
alias_handler.c    custom_perror2.c  _getenv.c     memtrackeralias.c  printf.c     runchecker.bash  _sprintf.c  _strcpy.c  test_ls_2
allowed_functions  custom_perror.c   hsh           memtracker.c       _putchar.c   _setenv.c        _strcat.c   _strdup.c  TEST_SUITE
_atoi.c            find_alias.c      linetoargs.c  memtracker.h       read_file.c  shell.c          _strchr.c   _strlen.c  _unsetenv.c
your_cli:#

## ADDITIONAL NOTES:

This is a custom shell that isn't as complex as popular shells like bash, zsh, or csh. 
However, it serves as a simple starting point for experimenting with shell development. 
Future enhancements may include adding more advanced features and increasing its functionality.
