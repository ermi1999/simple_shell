#include "main.h"

/**
 * change_directory - Changes the current working directory
 * @arg: The array of command arguments
 * @path: The path to change to
 * @program_name: The name of the program
 */
void change_directory(char **arg, char *path, char *program_name)
{
	char *current_directory;

	current_directory = malloc(PATH_MAX);
	if (current_directory == NULL)
	{
		perror("malloc error");
		exit(1);
	}

	if (getcwd(current_directory, PATH_MAX) == NULL)
	{
		perror("getcwd error");
		free(current_directory);
		exit(1);
	}

	if (chdir(path) == -1)
	{
		write(STDOUT_FILENO, current_directory, string_length(current_directory));
		write(STDOUT_FILENO, "\n", 1);
		cd_error_handler(program_name, arg[1]);
		free(current_directory);
		return;
	}

	if (setenv("OLDPWD", current_directory, 1) == -1)
	{
		perror("setenv error");
		free(current_directory);
		exit(1);
	}

	free(current_directory);
}


/**
 * cd_command_handler - Handles the cd command
 * @arg: The array of command arguments
 * @program_name: Pointer to the program name
 * @env: Pointer to an array of environment variables
 */
void cd_command_handler(char **arg, char *program_name, char **env)
{
	char *path = arg[1];

	if (path == NULL || string_compare(path, "~", string_length("~")) == 0)
	{
		path = get_env_variables(env, "HOME=");

		if (path == NULL)
		{
			cd_error_handler(program_name, arg[1]);
			return;
		}
	}
	else if (string_compare(path, "-", string_length("-")) == 0)
	{
		path = get_env_variables(env, "OLDPWD=");

		if (path == NULL)
		{
			cd_error_handler(program_name, arg[1]);
			return;
		}
		write(STDOUT_FILENO, path, string_length(path));
		write(STDOUT_FILENO, "\n", 1);
	}

	change_directory(arg, path, program_name);
}
