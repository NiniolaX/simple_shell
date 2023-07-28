#include "shell.h"

/**
 * Description: _atoi - Converts a string to an integer.
 * @s: Character string to be converted to an integer.
 * Return: 0 if success.
 */

int _atoi(char *s)
{
	int i = 0;
	unsigned int integer = 0;/* unsigned int to hold larger int values */

	/* Check for sign */
	if (s[0] == '-')
		return (-1);

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			/* Converts the current char to ASCII */
			integer = integer * 10 + (s[i] - '0');
			i++;
		}
		else
			return (-1);
	}

	return (integer);
}
