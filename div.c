#include "monty.h"

/**
 * f_div - Divides the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int stack_length = 0, result;

    current = *head;

    // Calculate the length of the stack
    while (current)
    {
        current = current->next;
        stack_length++;
    }

    // Check if the stack has less than 2 elements
    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't divide, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;

    // Check if dividing by zero
    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    // Perform the division and update the stack
    result = current->next->n / current->n;
    current->next->n = result;
    *head = current->next;
    free(current);
}

