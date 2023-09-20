#include "main.h"

void execution(char *arg[], char *env[], char *path_env, char *program_name)
{
	char *directory = strtok(path_env, ":");

	while (directory != NULL)
	{
		char *path = malloc(string_length(directory) + string_length(arg[0]) + 2);

		string_copy(path, directory);
		string_concat(path, "/");
		string_concat(path, arg[0]);

		if (access(path, X_OK) == 0)
		{
			if (execve(path, arg, env) == -1)
			{
				command_not_found_error_handler(program_name, arg[0]);
			}
			else
			{
				free(path);
				return;
			}
		}

		free(path);
		directory = strtok(NULL, ":");
	}

	command_not_found_error_handler(program_name, arg[0]);
}

/**
 * fork_provider - Creates a child process and executes a command using execve
 *
 * @arg: The command and its arguments
 * @envp: The environment variables
 * @program_name: Pointer to the program name
 */
void fork_provider(char *arg[], char *envp[], char *program_name)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if (child_pid == 0)
	{
		char *path_env = NULL;
		int i;

		for (i = 0; envp[i] != NULL; i++)
		{
			if (string_compare(envp[i], "PATH=", 5) == 0)
			{
				path_env = envp[i] + 5;
				break;
			}
		}

		if (path_env == NULL)
		{
			command_not_found_error_handler(program_name, arg[0]);
		}

		execution(arg, envp, path_env, program_name);
	}
	else
	{
		int status;

		wait(&status);
	}
}

/**
 * path_specified_fork_provider - Creates a child process and
 * executes a command using execve without searching the PATH
 *
 * @arg: The command and its arguments
 * @program_name: Pointer to the program name
 */
void path_specified_fork_provider(char *arg[], char *program_name)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (execve(arg[0], arg, NULL) == -1)
		{
			command_not_found_error_handler(program_name, arg[0]);
		}
	}
	else
	{
		int status;

		wait(&status);
	}
}
