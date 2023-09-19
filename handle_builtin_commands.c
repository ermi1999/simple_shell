#include "main.h"
/**
 * env_variables - Prints environment variables
 * @env: The array of environment variables
 */
void env_variables(char **env)
{
	int i = 0;
​
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
​
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
​
			if (is_valid == -1)
			{
				exit_error_handler(program, arg[1]);
			}
			else
			{
				int status = is_valid;
​
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
​
	*handled = 0;
}
