#include "shell.h"
void intractive_mode(int is_intractive)
{
int status, val;
list_t *head = NULL;
char *lineptr = NULL;
pid_t child_pid;
char **argv;
size_t argc = 0;
ssize_t flag;
while (1)
{
print_prompt(is_intractive);
head =  get_command(lineptr, head, &flag);
if (flag == -1)
break;
if (head != NULL)
{
argv = linked_list_to_array(head, &argc);
if (_strcmp(argv[0], "exit"))
{
free_list(head);
free_array(argv, argc);
free(lineptr);
write(1, "exit\n", _strlen("exit\n"));
exit(0); }
else if (_strcmp(argv[0], "env"))
print_env();
else
{
child_pid = fork();
if (child_pid == -1)
exit(1);
if (child_pid == 0)
{
val = execve(argv[0], argv, NULL);
if (val == -1)
{
perror("./shell");
free_list(head);
free_array(argv, argc);
exit(0); } }
else
wait(&status);
free_list(head);
free_array(argv, argc); } } }
if (is_intractive)
write(1, "exit\n", _strlen("exit\n")); }
