#include "main.h"

/**
 * Description: _strcat - Concatenates two strings.
 * @dest: destination string
 * @src: source string
 * Return: Pointer to destination string.
 */

char *_strcat(char *dest, char *src)
{
	/* Initiate a loop counter for adding src elements to dest */
	int i;

	/* Calculate length of src and dest string */
	int length = 0;

	while (dest[length] != '\0')
	{
		length++;
	}

	/* Add src elements to end of dest */
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[length + i] = src[i];
	}

	/* Add null character to end of dest string */
	dest[length + i] = '\0';

	return (dest);
}
