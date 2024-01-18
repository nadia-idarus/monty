#include "monty.h"

/**
 * multiplyTopTwoElements - Multiplies the top two elements of the stack.
 * @stackHead: Pointer to the head of the stack.
 * @lineNumber: Line number in the file.
 * Return: No return value.
 */
void multiplyTopTwoElements(stack_t **stackHead, unsigned int lineNumber)
{
    stack_t *current;
    int length = 0, result;

    current = *stackHead;

    // Calculate the length of the stack
    while (current)
    {
        current = current->next;
        length++;
    }

    // Check if the stack has less than two elements
    if (length < 2)
    {
        fprintf(stderr, "L%d: can't mul

