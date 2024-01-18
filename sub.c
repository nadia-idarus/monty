#include "monty.h"

/**
 * subtractTopTwoElements - Subtracts the top element from the second element.
 * @stackHead: Pointer to the head of the stack.
 * @lineNumber: Line number in the file.
 * Return: No return value.
 */
void subtractTopTwoElements(stack_t **stackHead, unsigned int lineNumber)
{
    stack_t *current;
    int difference, nodeCount;

    // Get the current head of the stack
    current = *stackHead;

    // Count the number of nodes in the stack
    for (nodeCount = 0; current != NULL; nodeCount++)
        current = current->next;

    // Check if the stack has less than two elements
    if (nodeCount < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        freeStack(*stackHead);
        exit(EXIT_FAILURE);
    }

    // Update the top of the stack with the subtraction result
    current = *stackHead;
    difference = current->next->n - current->n;
    current->next->n = difference;
    *stackHead = current->next;
    free(current);
}

