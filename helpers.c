#include "monty.h"

/**
 * print_error - prints error message on stderr
 * @format: the formart of the error
 * @type: the format type
 *
 * Return: nothing
 */
void print_error(char *format, char type, ...)
{
va_list args;
char *s;
int d;
va_start(args, type);
if (type == 's')
{
s = va_arg(args, char *);
fprintf(stderr, format, s);
}
else if (type == 'd')
{
d = va_arg(args, int);
fprintf(stderr, format, d);
}
else
{
fprintf(stderr, format, '\n');
}
va_end(args);
exit(EXIT_FAILURE);
}
