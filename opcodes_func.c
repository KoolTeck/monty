#include "monty.h"

/**
 * opc_push - pushes an element to the stack
 *
 * @stack: the memory address to the stack
 * @data: The line number of the opcode
 *
 * Return: nothing
 */
void opc_push(stack_t **stack, unsigned int data)
{
add_dnodeint(stack, data);
}


/**
 * opc_pal - prints the elements in a stack
 *
 * @stack: the memory address to the stack
 * @data: The line number of the opcode
 *
 * Return: nothing
 */
void opc_pal(stack_t **stack, unsigned int data)
{
(void)data;
print_dlistint(*stack);
}

/**
 * opc_pint - prints the top  element in a stack
 *
 * @stack: the memory address to the stack
 * @lNum: The line number of the opcode
 *
 * Return: nothing
 */
void opc_pint(stack_t **stack, unsigned int lNum)
{
print_top_int(*stack, lNum);
}

/**
 * opc_pint - removes the top  element in a stack
 *
 * @stack: the memory address to the stack
 * @lNum: The line number of the opcode
 *
 * Return: nothing
 */
void opc_pop(stack_t **stack, unsigned int lNum)
{
pop_top_int(stack, lNum);
}
