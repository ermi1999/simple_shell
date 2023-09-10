#include "main.h"

/**
 * fork_provder - Creates a child process and excutes a command using execve
 *
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
		int status;

		wait(&status);
	}
}
