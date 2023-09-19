#include "main.h"

/**
 * main - Entry point
 * @argv: Arguments to for the program
 * @argc: Argument count
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{

    if (argc < 0)
    {
        perror("Insufficient arguments");
    }

    prompt_provider(argv[0]);

    return (0);
}

