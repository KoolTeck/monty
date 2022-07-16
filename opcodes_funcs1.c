#include "monty.h"

/**
 * opc_push - adds a new node at the top of dlist
 *
 * @head: address of the head node
 * @n: the int data to add
 *
 * Return: nothing
 */
void opc_push(stack_t **head, unsigned int n)
{
stack_t *new;
new = malloc(sizeof(stack_t));
if (new == NULL)
print_error("Error: malloc failed", 'n', "\n");
new->n = n;
new->prev = NULL;
new->next = *head;
if (*head != NULL)
(*head)->prev = new;
*head = new;
}

/**
 * opc_pall - prints the elements in a doubly  inked list
 * @h: the head node
 * @lnum: the line number
 * Return: nothing
 */
void opc_pall(stack_t **h, unsigned int lnum)
{
stack_t *current = NULL;
(void)lnum;
current = *h;
if (current == NULL)
return;
while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
 * free_dlistint - frees a doubly linked list
 * @head: the head node
 *
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
stack_t *temp;
while (head != NULL)
{
temp = head;
head = head->next;
free(temp);
}
}

/**
 * opc_pint - prints the top element in stack
 * @head: the head node
* @lnum: the line number from the file being read
 *
 * Return: nothing
 */
void opc_pint(stack_t **head, unsigned int lnum)
{
if (*head == NULL)
print_error("L%d: can't pint, stack empty\n", 'd', lnum);
printf("%d\n", (*head)->n);
}


/**
 * opc_pop - removes the top node in d-list
 * @head: the head node
* @lnum: the line number from the file being read
 *
 * Return: nothing
 */
void opc_pop(stack_t **head, unsigned int lnum)
{
stack_t *temp = NULL;
temp = *head;
if (temp == NULL)
print_error("L%d: can't pop an empty stack\n", 'd', lnum);
*head = temp->next;
if (*head != NULL)
(*head)->prev = NULL;
free(temp);
}
