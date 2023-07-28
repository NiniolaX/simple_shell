#include "shell.h"

/**
 * _strncmp - Compares first n bytes of a string to another
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes/characters to compare
 * Return: 0 if strings are same, non-zero if not
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i = 0;

	/* Compare each element of s1 with s2 */
	for (i = 0; (s1[i] != '\0' || s2[i] != '\0') && i < n; i++)
	{
		/* Return 0 if s1 and s2 are the same */
		if (s1[i] == s2[i])
		{
			if (s1[i + 1] == '\0' || s2[i + 1] == '\0' || i + 1 == n)
				return (0);
		}
		else if (s1[i] < s2[i] || s2[i] < s1[i])
			break;
	}
	/* Return differene bwtween strings if they aren't same */
	return (s1[i] - s2[i]);
}
