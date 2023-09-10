#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	printf("#cisfun$ ");
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
		fork_provider(input);
		printf("#cisfun$ ");
	}
	free(input);
	return (0);
}
