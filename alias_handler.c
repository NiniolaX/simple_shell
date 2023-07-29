#include "shell.h"
#include "main.h"
#include "memtracker.h"

alias_s *head;
alias_s *aliasTracker = NULL;
/**
 * print_alias - Prints an alias
 * @name: Name of alias
 * Return: 0 on success, -1 on fail
 */
void print_alias(char *name)
{
	alias_s *p = head;

	while (p != NULL)
	{
		if (_strcmp(p->name, name) == 0)
			_printf("%s='%s'\n", p->name, p->value);
		p = p->next;
	}
}

/**
 * print_all_aliases - Prints all aliases
 *
 * Return: Number of aliases printed
 */
void print_all_aliases(void)
{
	alias_s *p = head;
	int i = 0;

	while (p != NULL)
	{
		_printf("%s='%s'\n", p->name, p->value);
		p = p->next;
		i++;
	}
}

/**
 * add_alias - Adds new alias to alias struct
 * @aliasStr: String containing alias name and value
 * Return: 0 if succes, -1 on fail
 */
alias_s *add_alias(char *aliasStr)
{
	alias_s *new, *p = head;
	char *name, *value, *aliasStrcp = _strdup(aliasStr);
	char delim[] = "=";


	/* Split alias string int name and value */
	name = strtok(aliasStrcp, delim);
	value = strtok(NULL, delim);

	/* Check if alias exists */
	while (p != NULL)
	{
		if (_strcmp(p->name, name) == 0)
		{
			free(p->value);
			p->value = _strdup(value);
			memtracker[trackerSize] = p->value;
			trackerSize++;
			free(aliasStrcp);
			new = p;
			return (new);
		}
		p = p->next;
	}

	/* Allocate memory for new alias */
	new = malloc(sizeof(alias_s));
	if (new != NULL)
		aliasTracker = new;
	else
		return (NULL);

	/* Initialize new alias */
	new->name = _strdup(name);
	memtracker[trackerSize] = new->name;
	trackerSize++;
	new->value = _strdup(value);
	memtracker[trackerSize] = new->value;
	trackerSize++;
	new->next = NULL;

	free(aliasStrcp);
	aliasStrcp = NULL;

	/* If alias list is empty */
	if (head == NULL)
	{
		head = new;
		return (new);
	}

	/* If alias list exists */
	p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
	return (new);
}

/**
 * alias_handler - Handles alias commands
 * @av: Argument vector
 * Return: void
 */
void alias_handler(char **av)
{
	int i;
	
	/* If alias has no arguments */
	if (av[1] == NULL)
	{
		print_all_aliases();
		return;
	}
	/* If alias has two arguments */
	else if (av[2] == NULL)
	{
		if (_strchr(av[1], '=') == NULL)
		{
			print_alias(av[1]);
			return;
		}
		else
		{
			add_alias(av[1]);
			return;
		}
	}
	/* If has more than two arguments */
	else
	{
		for (i = 0; av[i] != NULL; i++)
		{
			if (_strchr(av[i], '=') == NULL)
			{
				print_alias(av[i]);
			}
			else
			{
				add_alias(av[i]);
			}
		}
		return;
	}
	return;
}
