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
 * builtin_commands - Handles built-in commands
 * @arg: The array of command arguments
 * @env: The array of environment variables
 * @handled: Flag if the argument is handled
 * @program: Pointer to the program name
 */
void builtin_commands(char **arg, char **env, int *handled, char *program)
{
	if (string_compare(arg[0], "exit", string_length("exit")) == 0)
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

				exit(status);
			}
		}
		else
		{
			exit(0);
		}
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

	*handled = 0;
}
