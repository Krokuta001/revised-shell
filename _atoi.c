#include "shell.h"

/**
 * _hello - Prints "Hello, sir!" .
 *
 * Description: This function prints the greeting "Hello, sir!".
 */
void _hello(void)
{
    char *message = "Hello, sir!\n";
    int i = 0;

    while (message[i] != '\0')
    {
        _putchar(message[i]);
        i++;
    }
}

/**
 * main - Entry point of the program.
 *
 * Description: The function calls the `_hello`.
 *
 * Return: 0 (Success)
 */
int main(void)
{
    _hello();
    return (0);
}
