#include "main.h"
/**
 * tokenize_string_provider - Tokenizes the input string
 * and calls fork_provider
 * @input: The input string to be tokenized
 * @env: The array of environment variables
 * @program_name: Pointer to the program name
 */
void tokenize_string_provider(char *input, char **env, char *program_name)
{
	char *tokenized_string = strtok(input, " ");
	char **arg = malloc((MAXIMUM_ARGS + 1) * sizeof(char *));
	int i = 0;
	int j;

	while (tokenized_string != NULL && i < MAXIMUM_ARGS)
	{
		arg[i] = tokenized_string;
		tokenized_string = strtok(NULL, " ");
		i++;
	}
	arg[i] = NULL;

	if (arg[0] != NULL)
	{
		int handled;

		builtin_commands(arg, env, &handled, program_name);
		if (handled)
		{
			free(arg);
			return;
		}
		for (j = 0; arg[0][j] != '\0'; j++)
		{
			if (arg[0][j] == '/')
			{
				break;
			}
		}
		if (arg[0][j] == '/')
		{
			path_specified_fork_provider(arg, program_name);
			free(arg);
			return;
		}
	}
	fork_provider(arg, env, program_name);

	free(arg);
}

/**
 * prompt_provider - Provides the prompt and reads user input
 * @program_name: Pointer to the program name
 */
void prompt_provider(char *program_name)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

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

		tokenize_string_provider(input, environ, program_name);
	}
	free(input);
}
