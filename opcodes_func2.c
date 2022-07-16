#include "monty.h"

/**
 * opc_swap - swaps the top two elements in stack
 * @head: the head node
* @lnum: the line number from the file being read
 *
 * Return: nothing
 */
void opc_swap(stack_t **head, unsigned int lnum)
{
int temp;
if (*head == NULL || (*head)->next == NULL)
print_error("L%d: can't swap, stack too short\n", 'd', lnum);
temp = (*head)->n;
(*head)->n = (*head)->next->n;
(*head)->next->n = temp;
}
