#include "monty.h"

/**
 * main - the entrance to the program
 * @av: the arguments vector
 * @ac: the args count
 *
 * Return: Always Zero
 */

int main(int ac, char **av)
{
ssize_t line_size;
stack_t *stack = NULL;
char **token, *line_buf = NULL;
size_t line_buf_size = 0;
int line_count = 1;
FILE *fp;
void (*f)(stack_t **stack, unsigned int line_number);
if (ac != 2)
print_error("USAGE: monty file%c", 'n');
fp = fopen(av[1], "r");
if (!fp)
print_error("Error: Can't open file %s\n", 's', av[1]);
while ((line_size = getline(&line_buf, &line_buf_size, fp)) != -1)
{
if (line_size == -1)
free(line_buf);
if (line_buf[0] == '\n')
{
line_count++;
continue;
}
token = break_line(line_buf);
f = get_opcode_func(line_count, token);
if (f == NULL)
exit(EXIT_FAILURE);
if (token[1] == NULL)
token[1] = "1";
f(&stack, atoi(token[1]));
line_count++;
free(token[0]);
free(token);
}
free(line_buf);
free_dlistint(stack);
stack = NULL;
line_buf  = NULL;
fclose(fp);
return (EXIT_SUCCESS);
}
