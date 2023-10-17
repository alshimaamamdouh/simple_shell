#include "shell.h"
/**
 *get_command - Read a line of input from the user, tokenize it
 *and store tokens in a linked list
 *
 *@lineptr: A pointer to a buffer where the input line will be stored.
 *@head: A pointer to the head of the linked list where tokens will be stored
 *@flag: A pointer to a ssize_t variable that will hold
 *the result of the getline operation.
 *
 *Return: A pointer to the head of the linked list containing tokens.
 *If the input line is empty or if an error occurs
 *the function may return NULL
*/
list_t *get_command(char *lineptr, list_t *head, ssize_t *flag)
{
size_t n = 0;
ssize_t getline_result = 0;
char *token;
char *delim = " \t\n";
*flag = getline_result;
head = NULL;
getline_result = getline(&lineptr, &n, stdin);
if (getline_result == -1)
{
free(lineptr);
*flag = getline_result;
write(1, "exit\n", _strlen("exit\n"));
exit(0);
}
else
/* Check if the input line is empty (just Enter)*/
if (_strlen(lineptr) <= 1)
{
free(lineptr);
return (head);
}
/*tokenize*/
token = strtok(lineptr, delim);
while (token != NULL)
{
add_node_end(&head, token);
token = strtok(NULL, delim);
}
free(lineptr);
return (head);
}
