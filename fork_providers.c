#include "main.h"

/**
 * execution - Executes a command using execve
 *
 * @arg: The command and its arguments
 * @env: The environment variables
 * @path_env: The PATH environment variable
 * @program_name: Pointer to the program_name
 */
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
 * @env: The environment variables
 * @program_name: Pointer to the program name
 */
void fork_provider(char *arg[], char *env[], char *program_name)
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

		path_env = get_env_variables(env, "PATH=");

		if (path_env == NULL)
		{
			command_not_found_error_handler(program_name, arg[0]);
		}

		execution(arg, env, path_env, program_name);
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
