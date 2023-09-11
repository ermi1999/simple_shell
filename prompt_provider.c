#include "main.h"

/**
 * tokenize_string_provider - Tokenizes the input string
 * and calls fork_provider
 * @input: The input string to be tokenized
 */
void tokenize_string_provider(char *input)
{
	char *tokenized_string = strtok(input, " ");
	char **arg = malloc((MAXIMUM_ARGS + 1) * sizeof(char *));
	int i = 0;

	while (tokenized_string != NULL && i < MAXIMUM_ARGS)
	{
		arg[i] = tokenized_string;
		tokenized_string = strtok(NULL, " ");
		i++;
	}
	arg[i] = NULL;
	fork_provider(arg);

	printf("#cisfun$ ");

	free(arg);
}

/**
 * prompt_provider - Provides the prompt and reads user input
 */
void prompt_provider(void)
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

		tokenize_string_provider(input);
	}
	free(input);
}
