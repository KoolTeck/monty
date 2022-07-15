#include "monty.h"

/**
 * get_opcode_func - gets the func associated with an  opcode
 * @lNum: the line num
 * @token: arr of str containing the opcodes
 *
 * Return: the address of the func or NULL on error
 */
void (*get_opcode_func(int lNum, char **token))(stack_t **, unsigned int)
{
int i, compare;
instruction_t instruction[] = {
{"push", opc_push},
{"pall", opc_pal},
{NULL, NULL}
};
compare = (strcmp(token[0], instruction[0].opcode)) == 0;
i = 0;
if (compare && (strcmp(token[1], "\0")) != 48)
{
if (token[1] == NULL || atoi(token[1]) == 0)
{
free(token[0]);
free(token);
fprintf(stderr, "L%d: usage: push integer\n", lNum
);
return (NULL);
}
}
while (instruction[i].opcode != NULL)
{
if ((strcmp(token[0], instruction[i].opcode)) == 0)
{
return (instruction[i].f);
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
