#include "shell.h"

/**
 * interactive - returns true if shell is in the interactive mode
 * @info: structure of the address
 *
 * Return: 1 if its in  interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the  character is a delimeter
 * @k: the character  to check
 * @delim:  delimeter_ string
 * Return: 1 if its  true, 0 if false
 */
int is_delim(char k, char *delim)
{
	while (*delim)
		if (*delim++ == k)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic characters
 * @k: The character to input
 * Return: 1 if k is alphabetic, 0 otherwise
 */

int _isalpha(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int j, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (j = 0; s[j] != '\0' && flag != 2; j++)
	{
		if (s[j] == '-')
			sign *= -1;

		if (s[j] >= '0' && s[j] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
