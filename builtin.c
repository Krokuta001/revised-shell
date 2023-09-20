#include "shell.h"

#define MAX_INPUT_LENGTH 1024

int main()
{
    char input[MAX_INPUT_LENGTH];

    while (1)
    {
        printf("simple_shell$ "); // Display a prompt
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            // Handle end of file (Ctrl+D)
            printf("\n");
            break;
        }

        // Remove the newline character
        input[strlen(input) - 1] = '\0';

        // Fork a child process
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("Fork failed");
            exit(1);
        }
        else if (pid == 0)
        {
            // Child process
            execlp(input, input, (char *)NULL);

            // If execlp fails, it means the command is not found
            perror("Command not found");
            exit(1);
        }
        else
        {
            // Parent process
            wait(NULL); // Wait for the child process to finish
        }
    }

    return 0;
}
