#include "shell.h"
/***/
void free_array(char ** array,size_t size)
{
size_t i;
for (i = 0; i < size; i++)
{
free(array[i]);
}
free(array);
}
/***/
char **linked_list_to_array(list_t *head,size_t *size)
{
list_t *temp = head;
size_t i;

if (head == NULL)
return (NULL);
size_t len = list_len(head);
char** array = (char**)malloc((len) * sizeof(char*));
if (array == NULL)
{
perror("ERROR:");
exit(1);
}
*size = len;
for (i = 0; i < len; i++)
{
array[i] = strdup(temp->str);
temp =temp->next;
}
return (array);
}
