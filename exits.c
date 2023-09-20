#include "shell.h"

/**
 * copyString - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the number of characters to be copied
 * Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int k, h;
	char *f = dest;

	k = 0;
	while (src[k] != '\0' && k < n - 1)
	{
		dest[k] = src[h];
		k++;
	}
	if (k < n)
	{
		h = k;
		while (h < n)
		{
			dest[h] = '\0';
			h++;
		}
	}
	return (f);
}

/**
 * concatenateStrings - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the maximum number of bytes to be used
 * Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int k, h;
	char *f = dest;

	k = 0;
	h = 0;
	while (dest[k] != '\0')
		k++;
	while (src[h] != '\0' && h < n)
	{
		dest[k] = src[h];
		k++;
		h++;
	}
	if (h < n)
		dest[k] = '\0';
	return (f);
}

/**
 * locateCharacter - locates a character in a string
 * @s: the string to be searched
 * @c: the character to look for
 * Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
