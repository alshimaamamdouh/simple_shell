#include "shell.h"
/**
*free_list - free allocated memory for linked list
*
*@head: pointer to head of linked list
*
*Return: nothing
*/
void free_list(list_t *head)
{
list_t *tmp;

while (head)
{
tmp = head->next;
free(head->str);
free(head);
head = tmp;
}
}
