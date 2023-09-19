#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

#define MAXIMUM_ARGS 5
extern char **environ;


void fork_provider(char *arg[], char *envp[], char *program_name);
void path_specified_fork_provider(char *arg[], char *program_name);
void prompt_provider(char *program_name);
void command_not_found_error_handler(char *program_name, char *arg);
void exit_error_handler(char *program_name, char *arg);
void builtin_commands(char **arg, char **env, int *handled, char *program);

/*string manipulation*/
int string_compare(const char *string_one, const char *string_two, size_t n);
char *string_copy(char *dest, const char *src);
size_t string_length(const char *str);
char *string_concat(char *dest, const char *src);
int string_to_int(char *str);

#endif
