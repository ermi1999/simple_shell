#include "main.h"

/**
 * command_not_found_error_handler -
 * Handles the error when a command is not found
 *
 * @program_name: The name of the program
 * @arg: The argument that was not found
 */
void command_not_found_error_handler(char *program_name, char *arg)
{
	char error_message[256];

	string_copy(error_message, program_name);
	string_concat(error_message, ": 1: ");
	string_concat(error_message, arg);

	string_concat(error_message, ": not found\n");
	write(STDERR_FILENO, error_message, string_length(error_message));

	exit(127);
}

/**
 * exit_error_handler - Handles the error
 * when an illegal number is provided to the exit command
 *
 * @program_name: The name of the program
 * @arg: The illegal number argument
 */
void exit_error_handler(char *program_name, char *arg)
{
	char error_message[256];

	string_copy(error_message, program_name);
	string_concat(error_message, ": 1: exit: Illegal number: ");
	string_concat(error_message, arg);
	string_concat(error_message, "\n");

	write(STDERR_FILENO, error_message, string_length(error_message));

	exit(2);
}
