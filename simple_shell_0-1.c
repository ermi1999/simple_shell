#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * fork_provider - Creates a child process and executes a command using execve
 * @input: The command to be executed
 */
void fork_provider(char *input)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if (child_pid == 0)
	{
		char *args[2];

		args[0] = input;
		args[1] = NULL;

		if (execve(input, args, NULL) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
	{
		/* Parent process */
		int status;

		wait(&status);
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	printf("#cisfun$ ");
	while ((read = getline(&input, &len, stdin)) > 0)
	{
		/* Checking for end of file */
		if (read == 0)
		{
			printf("End of file reached.\n");
			break;
		}
		/* Remove newline character from the end of the line */
		if (input[read - 1] == '\n')
		{
			input[read - 1] = '\0';
		}
		fork_provider(input);
		printf("#cisfun$ ");
	}
	free(input);
	return (0);
}
