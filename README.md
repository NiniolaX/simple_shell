# Simple Shell - Readme

## Introduction

This shell is a simple command-line interpreter that provides a basic command execution environment. It allows you to interact with your operating system, execute commands, and perform various operations.

## Features

- **Interactive Mode**: When you run the shell without any input redirection, it enters interactive mode. In this mode, the shell displays a prompt where you can enter commands directly. It reads and executes your commands interactively from the CLI.

- **Non-Interactive Mode**: When you run the shell with input redirected from a file or a script, it enters non-interactive mode. In this mode, the shell reads and executes commands from the input file without displaying a prompt. It is useful for running commands from a script file or automating tasks.

- **Command Execution**: The shell supports executing basic system commands, such as `ls`, `pwd`, `cd`, `echo`, and more.

- **Exit**: To exit the shell, simply type `exit` and press Enter.

## How to Use

### Compilation

Use a C compiler to compile the shell program.

```bash
gcc simple_shell.c -o shell


Running the Shell
Interactive Mode: Run the compiled program without any input redirection.

```
./shell

The shell will display a prompt (cisfun$) where you can enter commands interactively.

Non-Interactive Mode: Redirect input from a file or a script.

```
./shell < input_commands.txt

The shell will read and execute commands from the input file.

Commands
Enter commands at the prompt cisfun$ in interactive mode or provide them in the input file in non-interactive mode.


cisfun$ ls
cisfun$ pwd
cisfun$ echo Hello, world!
cisfun$ exit

Additional Notes
This is a custom shell that isn't as complex as popular shells like bash, zsh, or csh. 
It serves as a simple starting point for experimenting with shell development. 
Future enhancements may include adding more advanced features and increasing its functionality.
