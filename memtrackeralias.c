#include "shell.h"

/**
 * free_tracked_memory_alias - Frees alias_s linked list
 * Return: void
 */
void free_tracked_memory_alias(void)
{
	alias_s *p = head;
	alias_s *next;

	while (p != NULL)
	{
		free(p->name);
		free(p->value);
		next = p->next;
		free(p);
		p = next;
	}
	head = NULL;
}
