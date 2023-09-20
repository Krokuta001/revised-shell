#include "shell.h"

/**
convertStringToInteger - converts a string to an integer
@s: the string to be converted
Returns: 0 if no numbers are found in the string, the converted number otherwise,
     -1 on error
*/
int _erratoi(char *z)
{
	int j = 0;
	unsigned long int result = 0;

	if (*z == '+')
		z++;
	for (j = 0;  z[j] != '\0'; j++)
	{
		if (z[j] >= '0' && z[j] <= '9')
		{
			result *= 10;
			result += (z[j] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * printError - prints an error message
 * @info: the parameter and return information structure
 * @estr: string containing the specified error typ
 * Return: 0 if no errors occurred, -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * printDecimal - prints a decimal (integer) number (base 10)
 * @input: the input number
 * @fd: the file descriptor to write to
 * Return: the number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + current / j);
			count++;
		}
		current %= j;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/*
 * convertNumber - converter function, similar to itoa
 * @num: the number to convert
 * @base: the base for conversion
 * @flags: argument flags
 * Return: the converted string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * removeComments - function replaces the first instance of '#' with '\0'
 * @buf: address of the string to modify
 * Return: Always returns 0;
 */
void remove_comments(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}
