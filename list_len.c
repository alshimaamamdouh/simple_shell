#include "shell.h"
/**
 *list_len - get length of linked list
 *
 *@h: head of linked list
 *
 *Return: lenght of linked list
*/
size_t list_len(const list_t *h)
{
const list_t *temp = h;
size_t count = 0;

while (temp != NULL)
{
temp = temp->next;
count++;
}

return (count);
}
