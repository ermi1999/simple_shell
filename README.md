# Simple_shell

### Here is a discription of what each function is doing
*  tokenize_string_provider:
	Tokenizes the input string and calls fork_provider
*  prompt_provider:
	Provides the prompt and reads user input
set_env_variable:
	 Sets an environment variable
*  fork_provider:
	Creates a child process and executes a command using execve
*  path_specified_fork_provider:
	Creates a child process and executes a command using execve without searching the PATH
*  string_compare:
	Compare two strings up to a specified number of characters
* string_copy:
	Copy a string from source to destination
*  string_length:
	Calculate the length of a string
*  string_concat:
	Concatenate two strings
*  is_valid_integer:
	Checks if a string represents a valid integer
*  get_env_variables:
	Retrieves the value of an environment variable
*  env_variables:
	Prints environment variables
*  change_directory:
	Changes the current working directory
