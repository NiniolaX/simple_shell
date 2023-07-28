#include <stdio.h>
#include "shell.h"

/**
 * _strlen - calculates for the lenght of a string
 *
 * @s: The function parameter
 *
 * Return: Always 0 (Success)
 *
 */

int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
