#include "shell.h"
void intractive_mode(int is_intractive, char **environ)
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
free(lineptr);
if (head != NULL)
{
argv = linked_list_to_array(head, &argc);
free_list(head);
if (_strcmp(argv[0], "exit"))
{
free_array(argv, argc);
exit(0); }
else if (_strcmp(argv[0], "env") && !argv[1])
{
free_array(argv, argc);
print_env(environ); }
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
free_array(argv, argc);
exit(0); } }
else
wait(&status);
free_array(argv, argc); } } }
if (is_intractive)
write(1, "exit\n", _strlen("exit\n")); }
