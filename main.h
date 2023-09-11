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

void fork_provider(char *arg[]);
void prompt_provider(void);

#endif
