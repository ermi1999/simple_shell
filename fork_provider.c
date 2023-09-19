#include "main.h"

/**
 * execution - Executes a command using execve
 *
 * @arg: The command and its arguments
 * @envp: The environment variables
 * @path_env: The PATH environment variable
 */
void execution(char *arg[], char *envp[], char *path_env, int *line_number)
{

    char *directory = strtok(path_env, ":");

    while (directory != NULL)
    {
        char *full_path = malloc(string_length(directory) + string_length(arg[0]) + 2);
        string_copy(full_path, directory);
        string_concat(full_path, "/");
        string_concat(full_path, arg[0]);

        if (access(full_path, X_OK) == 0)
        {
            if (execve(full_path, arg, envp) == -1)
            {
                printf("%s: %d: %s: not found\n", arg[0], (*line_number), arg[0]);
                (*line_number)++; // Increment line number
                exit(1);
            }
            else
            {
                // Command executed successfully
                free(full_path);
                return;
            }
        }

        free(full_path);
        directory = strtok(NULL, ":");
    }

    printf("%s: %d: %s: not found\n", arg[0], (*line_number), arg[0]);
    (*line_number)++; // Increment line number
    exit(1);
}

/**
 * fork_provider - Creates a child process and executes a command using execve
 *
 * @arg: The command and its arguments
 * @envp: The environment variables
 */
void fork_provider(char *arg[], char *envp[], int *line_number)
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork error");
        exit(1);
    }
    else if (child_pid == 0)
    {
        char *path_env = NULL;
        int i;

        for (i = 0; envp[i] != NULL; i++)
        {
            if (string_compare(envp[i], "PATH=", 5) == 0)
            {
                path_env = envp[i] + 5;
                break;
            }
        }

        if (path_env == NULL)
        {
            printf("PATH environment variable not found.\n");
            exit(1);
        }

        execution(arg, envp, path_env, line_number);
    }
    else
    {
        int status;
        wait(&status);
    }
}

/**
 * path_specified_fork_provider - Creates a child process and executes a command using execve
 * without searching the PATH
 *
 * @arg: The command and its arguments
 */
void path_specified_fork_provider(char *arg[])
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork error");
        exit(1);
    }
    else if (child_pid == 0)
    {
        if (execve(arg[0], arg, NULL) == -1)
        {
            perror("./shell");
            exit(1);
        }
    }
    else
    {
        int status;
        wait(&status);
    }
}
