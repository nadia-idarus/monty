#include "monty.h"

/**
 * freeStack - Frees a doubly linked list representing a stack.
 * @stackHead: Pointer to the head of the stack.
 */
void freeStack(stack_t *stackHead)
{
    stack_t *temp;

    temp = stackHead;
    while (stackHead)
    {
        temp = stackHead->next;
        free(stackHead);
        stackHead = temp;
    }
}

