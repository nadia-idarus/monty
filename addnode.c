#include "monty.h"

/**
 * addNodeToStack - Adds a new node to the head of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @new_value: Value for the new node.
 * Return: No return value.
 */
void addNodeToStack(stack_t **stack_head, int new_value)
{
    stack_t *new_node, *current;

    // Store the current head of the stack
    current = *stack_head;

    // Allocate memory for the new node
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        exit(0);
    }

    // Update the previous pointer of the current head
    if (current)
        current->prev = new_node;

    // Set values for the new node
    new_node->n = new_value;
    new_node->next = *stack_head;
    new_node->prev = NULL;

    // Update the head of the stack to the new node
    *stack_head = new_node;
}

