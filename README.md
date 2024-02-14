# Simple shell

### This is a simple version of UNIX command interpreter.

> This command interpreter doesn't handle all unix commands there are some command that isn't implemented yet.

#### usage

- interactive mode
    ```shell
    $ ./hsh
     ls
     AUTHORS               custom_string_manipulation.c  error_handler.c   get_env_variables.c        hsh     main.h             README.md
     cd_command_handler.c  custom_string_to_int.c        fork_providers.c  handle_builtin_commands.c  main.c  prompt_provider.c
    
    ```

- none interactive mode
    ```shell
    $ echo "ls" | ./hsh
    AUTHORS               custom_string_manipulation.c  error_handler.c   get_env_variables.c        hsh     main.h             README.md
    cd_command_handler.c  custom_string_to_int.c        fork_providers.c  handle_builtin_commands.c  main.c  prompt_provider.c
    ```

