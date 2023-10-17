#include "shell.h"
/**
 *free_array - free allocated memory for array
 *
 *@array: array which is wanted to be free
 *@size: size of array
 *
 *Return: nothing
*/
void free_array(char **array, size_t size)
{
size_t i;
for (i = 0; i < size; i++)
{
free(array[i]);
}
free(array);
}
/**
 *linked_list_to_array - convert linked list to array
 *
 *@head: pointer to head of linked list
 *@size: size of linked list
 *
 *Return: pointer to array of char
*/
char **linked_list_to_array(list_t *head, size_t *size)
{
list_t *temp = head;
size_t i, len;
char **array;
if (head == NULL)
return (NULL);

len = list_len(head);
array = (char **)malloc((len + 1) * sizeof(char *));
if (array == NULL)
{
perror("ERROR:");
exit(1);
}
*size = len;
for (i = 0; i < len; i++)
{
array[i] = _strdup(temp->str);
temp = temp->next;
}
array[i] = NULL;
return (array);
}
