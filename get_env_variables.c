#include "main.h"

/**
 * get_env_variables - Retrieves the value of an environment variable
 * @env: The array of environment variables
 * @str: The environment variable to retrieve
 *
 * Return: The value of the environment variable or NULL if not found
 */
char *get_env_variables(char **env, char *str)
{
	char *environment_var;
	int i;

	environment_var = NULL;
	for (i = 0; env[i] != NULL; i++)
	{
		if (string_compare(env[i], str, string_length(str)) == 0)
		{
			environment_var = env[i] + string_length(str);
			break;
		}
	}

	return (environment_var);
}
