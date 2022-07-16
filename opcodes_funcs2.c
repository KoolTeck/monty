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

/**
 * opc_add - adds the top two elements in stack
 * @head: the head node
* @lnum: the line number from the file being read
 *
 * Return: nothing
 */
void opc_add(stack_t **head, unsigned int lnum)
{
stack_t *current;
int temp;
if (*head == NULL || (*head)->next == NULL)
print_error("L%d: can't add, stack too short\n", 'd', lnum);
current = *head;
temp = (*head)->n;
(*head)->next->n = temp + (*head)->next->n;
*head = (*head)->next;
free(current);
}


/**
 * opc_nop - an opcode that does nothing
 * @head: the head node
* @lnum: the line number from the file being read
 *
 * Return: nothing
 */
void opc_nop(stack_t **head, unsigned int lnum)
{
(void)head;
(void)lnum;
}

/**
 * opc_sub - subtracts the top two elements in stack
 * @head: the head node
* @lnum: the line number from the file being read
 *
 * Return: nothing
 */
void opc_sub(stack_t **head, unsigned int lnum)
{
stack_t *current;
int temp;
if (*head == NULL || (*head)->next == NULL)
print_error("L%d: can't sub, stack too short\n", 'd', lnum);
current = *head;
temp = (*head)->n;
(*head)->next->n = (*head)->next->n - temp;
*head = (*head)->next;
free(current);
}


/**
 * opc_div - divides the top two elements in stack
 * @head: the head node
* @lnum: the line number from the file being read
 *
 * Return: nothing
 */
void opc_div(stack_t **head, unsigned int lnum)
{
stack_t *current;
int temp;
if (*head == NULL || (*head)->next == NULL)
print_error("L%d: can't div, stack too short\n", 'd', lnum);
if ((*head)->n == 0)
print_error("L%d: division by zero\n", 'd', lnum);
current = *head;
temp = (*head)->n;
(*head)->next->n = (*head)->next->n / temp;
*head = (*head)->next;
free(current);
}
