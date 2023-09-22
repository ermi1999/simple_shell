#include "main.h"
/**
 * env_variables - Prints environment variables
 * @env: The array of environment variables
 */
void env_variables(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}

/**
 * set_env_variable - Sets an environment variable
 * @arg: The array of command arguments
 */
void set_env_variable(char **arg)
{
	if (arg[1] == NULL || arg[2] == NULL)
	{
		perror("unsetenv: Invalid syntax");
	}
	else
	{
		if (setenv(arg[1], arg[2], 1) != 0)
		{
			perror("Syntax: setenv MYVAR myvalue");
		}
	}
}

/**
 * unset_env_variable - Unsets an environment variable
 * @arg: The array of command arguments
 */
void unset_env_variable(char **arg)
{
	if (arg[1] == NULL)
	{
		perror("unsetenv: Invalid syntax");
	}
	else
	{
		if (unsetenv(arg[1]) != 0)
		{
			perror("Syntax: unsetenv MYVAR");
		}
	}
}

/**
 * exit_command_handler - handles exit command
 * @arg: The array of command arguments
 * @program: Pointer to the program name
 * @input: pointer to the getline input
*/

void exit_command_handler(char **arg, char *program, char *input)
{
	if (arg[1] != NULL)
	{
		int is_valid = string_to_int(arg[1]);

		if (is_valid == -1)
		{
			exit_error_handler(program, arg[1]);
		}
		else
		{
			int status = is_valid;

			free(arg);
			free(input);
			exit(status);
		}
	}
	else
	{
		free(arg);
		free(input);
		exit(0);
	}
}

/**
 * builtin - Handles built-in commands
 * @arg: The array of command arguments
 * @env: The array of environment variables
 * @handled: Flag if the argument is handled
 * @program: Pointer to the program name
 * @input: pointer to the getline input
 */
void builtin(char **arg, char **env, int *handled, char *program, char *input)
{
	if (string_compare(arg[0], "exit", string_length("exit")) == 0)
	{
		exit_command_handler(arg, program, input);
	}
	else if (string_compare(arg[0], "env", string_length("env")) == 0)
	{
		env_variables(env);
		*handled = 1;
		return;
	}
	else if (string_compare(arg[0], "setenv", string_length("setenv")) == 0)
	{
		set_env_variable(arg);
		*handled = 1;
		return;
	}
	else if (string_compare(arg[0], "unsetenv", string_length("unsetenv")) == 0)
	{
		unset_env_variable(arg);
		*handled = 1;
		return;
	}
	else if (string_compare(arg[0], "cd", string_length("cd")) == 0)
	{
		cd_command_handler(arg, program, env);
		*handled = 1;
		return;
	}
	*handled = 0;
}
