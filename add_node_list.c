#include "shell.h"
/**
 *add_node_end - add new point at the end to linked list
 *
 *@head: pointer to head of linked list
 *@str: string is added to linked list
 *
 *Return: pointer to linked list
*/
list_t *add_node_end(list_t **head, const char *str)
{
char *s;
int len;
list_t *new, *last;

new = malloc(sizeof(list_t));
if (new == NULL)
return (NULL);
s = strdup(str);
if (s == NULL)
{
free(new);
return (NULL);
}

len = _strlen(s);
new->str = s;
new->len = len;
new->next = NULL;

if (*head == NULL)
*head = new;
else
{
last = *head;
while (last->next != NULL)
last = last->next;
last->next = new;
}
return (*head);
}
