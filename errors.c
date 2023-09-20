#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int s = 0;

	if (!str)
		return;
	while (str[s] != '\0')
	{
		_eputchar(str[s]);
		s++;
	}
}

/**
writeCharToStderr - writes the character 'c' to stderr
@c: The character to be printed
Return: 1 on success. On error, -1 is returned, and errno is set appropriately.
*/
int _eputchar(char z)
{
	static int s;
	static char buf[WRITE_BUF_SIZE];

	if (z == BUF_FLUSH || s >= WRITE_BUF_SIZE)
	{
		write(2, buf, s);
		s = 0;
	}
	if (z != BUF_FLUSH)
		buf[s++] = z;
	return (1);
}

/**
writeCharToFileDescriptor - writes the character 'c' to the specified file descriptor 'fd'
@c: The character to print
@fd: The file descriptor to write to
Return: 1 on success. On error, -1 is returned, and errno is set appropriately.
*/
int _putfd(char z, int d)
{
	static int s;
	static char buf[WRITE_BUF_SIZE];

	if (z == BUF_FLUSH || s >= WRITE_BUF_SIZE)
	{
		write(d, buf, s);
		s = 0;
	}
	if (z != BUF_FLUSH)
		buf[s++] = z;
	return (1);
}

/**
printInputStringToFileDescriptor - prints a given input string to the specified file descriptor
@str: the string to be printed
@fd: the file descriptor to write to
Returns: the number of characters written
*/
int _putsfd(char *str, int d)
{
	int s = 0;

	if (!str)
		return (0);
	while (*str)
	{
		s += _putfd(*str++, d);
	}
	return (s);
}
