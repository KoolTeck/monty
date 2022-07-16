#include "monty.h"

/**
 * opc_mul - multiplies the top two elements in stack
 * @head: the head node
* @lnum: the line number from the file being read
 *
 * Return: nothing
 */
void opc_mul(stack_t **head, unsigned int lnum)
{
stack_t *current;
int temp;
if (*head == NULL || (*head)->next == NULL)
print_error("L%d: can't mul, stack too short\n", 'd', lnum);
current = *head;
temp = (*head)->n;
(*head)->next->n = (*head)->next->n * temp;
*head = (*head)->next;
free(current);
}
