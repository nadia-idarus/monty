#include "monty.h"

/**
 * setQueueMode - Sets the queue mode, indicating to use a queue.
 * @stackHead: Pointer to the head of the stack.
 * @lineNumber: Line number in the file.
 * Return: No return value.
 */
void setQueueMode(stack_t **stackHead, unsigned int lineNumber)
{
    (void)stackHead;
    (void)lineNumber;
    bus.lifi = 1;
}

/**
 * addToQueue - Adds a new node to the end of the stack.
 * @new_value: Value for the new node.
 * @stackHead: Pointer to the head of the stack.
 * Return: No return value.
 */
void addToQueue(stack_t **stackHead, int new_value)
{
    stack_t *new_node, *current;

    current = *stackHead;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
    }

    new_node->n = new_value;
    new_node->next = NULL;

    if (current)
    {
        while (current->next)
            current = current->next;
    }

    if (!current)
    {
        *stackHead = new_node;
        new_node->prev = NULL;
    }
    else
    {
        current->next = new_node;
        new_node->prev = current;
    }
}

