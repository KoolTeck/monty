#include "monty.h"

/**
 * main - the driver program
 * @av: the arguments vector
 * @ac: the args count
 *
 * Return: Always Zero
 */

int main(int ac, char **av)
{
stack_t *stack = NULL;
char *line_buf = NULL;
size_t line_buf_size = 0;
FILE *fp;
if (ac != 2)
print_error("USAGE: monty file%c", 'n');
fp = fopen(av[1], "r");
if (!fp)
print_error("Error: Can't open file %s\n", 's', av[1]);
read_line(&line_buf, &line_buf_size, fp, &stack);
free(line_buf);
free_dlistint(stack);
stack = NULL;
line_buf  = NULL;
fclose(fp);
return (EXIT_SUCCESS);
}
