#include "shell.h"
/***/
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

  // Check if the input line is empty (just Enter)                                                                                           
    if (_strlen(lineptr) <= 1) {
      free(lineptr);
      return head;
    }
//tokenize                                                                                                                                   
token = strtok (lineptr , delim);
 while (token != NULL)
    {
     add_node_end(&head,token);
     token = strtok(NULL,delim);
    }
free(lineptr);
return (head);
}
