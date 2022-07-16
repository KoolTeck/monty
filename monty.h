#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/* error handler */
void print_error(char *format, char type, ...);

/*stack helpers */
stack_t *add_dnodeint(stack_t **head, unsigned int n);
void print_dlistint(stack_t *h);
void free_dlistint(stack_t *head);
void print_top_int(stack_t *head, unsigned int lnum);
void pop_top_int(stack_t **head, unsigned int lNum);

/* program functions */
void (*get_opcode_func(int lNum, char **token))(stack_t **, unsigned int);

char **break_line(char *line_buf);
void read_line(char **line_buf, size_t *buf_size, FILE *fp, stack_t **stk);

void opc_pal(stack_t **stack, unsigned int data);

void opc_push(stack_t **stack, unsigned int data);

void opc_pint(stack_t **stack, unsigned int lNum);

void opc_pop(stack_t **stack, unsigned int lNum);
#endif /* MONTY_H */
