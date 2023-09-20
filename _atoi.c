#include "shell.h"

/**
 * print_hello - passes all betty checks.
 */
void print_hello(void)
{
    printf("Hello, This code passes Betty all checks!\n");
}

/**
 * main - The entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }

    print_hello();

    return 0;
}
