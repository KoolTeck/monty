#include "monty.h"

/**
 * add_dnodeint - adds a new node at the top of dlist
 *
 * @head: address of the head node
 * @n: the int data to add
 *
 * Return: Returns the new node or NULL on error
 */
stack_t *add_dnodeint(stack_t **head, unsigned int n)
{
stack_t *new;
new = malloc(sizeof(stack_t));
if (new == NULL)
return (NULL);
new->n = n;
new->prev = NULL;
new->next = *head;
if (*head != NULL)
(*head)->prev = new;
*head = new;
return (new);
}

/**
 * print_dlistint - prints the elements in a doubly  inked list
 * @h: the head node
 *
 * Return: nothing
 */
void print_dlistint(stack_t *h)
{
stack_t *current = NULL;
current = h;
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
 * print_top_int - prints the top element in stack
 * @head: the head node
* @lnum: the line number from the file being read
 *
 * Return: nothing
 */
void print_top_int(stack_t *head, unsigned int lnum)
{
if (head == NULL)
print_error("L%d: can't pint, stack empty\n", 'd', lnum);
printf("%d\n", head->n);
}


/**
 * pop_top_int - removes the top node in d-list
 * @head: the head node
* @lnum: the line number from the file being read
 *
 * Return: nothing
 */
void pop_top_int(stack_t **head, unsigned int lnum)
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
