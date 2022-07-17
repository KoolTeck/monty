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
void opc_push(stack_t **head, unsigned int n);
void opc_pall(stack_t **h, unsigned int lnum);
void free_dlistint(stack_t *head);
void opc_pint(stack_t **head, unsigned int lnum);
void opc_pop(stack_t **head, unsigned int lNum);
void opc_swap(stack_t **head, unsigned int lnum);
void opc_add(stack_t **head, unsigned int lnum);
void opc_nop(stack_t **head, unsigned int lnum);
void opc_sub(stack_t **head, unsigned int lnum);
void opc_div(stack_t **head, unsigned int lnum);
void opc_mul(stack_t **head, unsigned int lnum);
void opc_mod(stack_t **head, unsigned int lnum);
void opc_pchar(stack_t **head, unsigned int lnum);

/* program functions */
void (*get_opcode_func(int lNum, char **token))(stack_t **, unsigned int);

char **break_line(char *line_buf);
void read_line(char **line_buf, size_t *buf_size, FILE *fp, stack_t **stk);
int check_p_arg(char **token, char *opcode, int lNum);

#endif /* MONTY_H */
