#include "monty.h"

/**
 * read_line - reads a line from an opened file
 * @line_buf: the buffer
 * @buf_size: the size of the line buffer
 * @fp: the opened file
 * @stk: the stack mem address
 *
 * Return: nothing
 */
void read_line(char **line_buf, size_t *buf_size, FILE *fp, stack_t **stk)
{
char **token;
ssize_t line_size;
int param, line_count = 1;
void (*f)(stack_t **stack, unsigned int line_number);
while ((line_size = getline(line_buf, buf_size, fp)) != -1)
{
if (line_size == -1)
free(line_buf);
if (*line_buf[0] == '\n')
{
line_count++;
continue;
}
token = break_line(*line_buf);
if (strcmp(token[0], "nop") == 0)
continue;
f = get_opcode_func(line_count, token);
if (f == NULL)
exit(EXIT_FAILURE);
if (token[1] == NULL)
{
param = line_count;
}
else
{
param = atoi(token[1]);
}
f(stk, param);
line_count++;
free(token[0]);
free(token);
}
}

/**
 * get_opcode_func - gets the func associated with an  opcode
 * @lNum: the line num
 * @token: arr of str containing the opcodes
 *
 * Return: the address of the func or NULL on error
 */
void (*get_opcode_func(int lNum, char **token))(stack_t **, unsigned int)
{
int i, push_err = 0;
instruction_t instruct[] = {
{"push", opc_push},
{"pall", opc_pall},
{"pint", opc_pint},
{"pop", opc_pop},
{"swap", opc_swap},
{"add", opc_add},
{NULL, NULL}
};
push_err = check_p_arg(token, instruct[0].opcode, lNum);
if (push_err)
return (NULL);
i = 0;
while (instruct[i].opcode != NULL)
{
if ((strcmp(token[0], instruct[i].opcode)) == 0)
{
return (instruct[i].f);
}
i++;
}
fprintf(stderr, "L%d: unknown instruction", lNum);
fprintf(stderr, " %s\n", token[0]);
free(token[0]);
free(token);
return (NULL);
}


/**
 * break_line - breaks line buffer into an arr of strings
 * @line_buf: the buffer to break
 *
 * Return: the arr or NULL on error
 */
char **break_line(char *line_buf)
{
size_t i, found = 0;
char *token, *opcode;
char **argv = malloc(sizeof(char *) * strlen(line_buf
));
token = strtok(line_buf, " ");
opcode = malloc(sizeof(char) * strlen(token));
if (argv == NULL || opcode == NULL)
return (NULL);
i = 0;
while (token[i])
{
if (token[i] == '\n')
{
found = 1;
break;
}
i++;
}
if (found)
{
for (i = 0; i < (strlen(token)) - 1; i++)
{
opcode[i] = token[i];
}
opcode[i] = '\0';
argv[0] = strdup(opcode);
}
else
{
argv[0] = strdup(token);
}
token = strtok(NULL, " ");
argv[1] = token;
free(opcode);
return (argv);
}

/**
 * check_p_arg - checks the push opcode arg for error
 * @opcode: the corresponding opcode
 * @token: the buff containing opcode and arg
 * @lNum: the number line
 *
 * Return: Always 1 or 0;
 */

int check_p_arg(char **token, char *opcode, int lNum)
{
int compare;
compare = (strcmp(token[0], opcode)) == 0;
if (compare && (strcmp(token[0], "\0")) != 48)
{
if (token[1] == NULL || atoi(token[1]) == 0)
{
free(token[0]);
free(token);
fprintf(stderr, "L%d: usage: push integer\n", lNum
);
return (1);
}
}
return (0);
}
