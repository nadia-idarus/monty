#include "monty.h"

/**
 * add_top_two_elements - Adds the top two elements of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 * Return: No return value.
 */
void add_top_two_elements(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current;
    int length = 0, sum;

    current = *stack_head;

    // Calculate the length of the stack
    while (current)
    {
        current = current->next;
        length++;
    }

    // Check if the stack has less than two elements
    if (length < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    // Perform the

