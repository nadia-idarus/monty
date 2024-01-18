#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *line_content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int line_counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_line > 0)
    {
        line_content = NULL;
        read_line = getline(&line_content, &size, file);
        bus.content = line_content;
        line_counter++;

        if (read_line > 0)
        {
            execute(line_content, &stack, line_counter, file);
        }

        free(line_content);
    }

    free_stack(stack);
    fclose(file);

    return (0);
}

