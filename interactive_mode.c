#include "shell.h"
/**
 *intractive_mode - run shell in intractive mode
 *
 *@is_intractive: integer cheacks if it is interactive or not
 *@environ: enviroment variables
*/
void intractive_mode(int is_intractive, char **environ)
{
int status, val;
char *cmd;
list_t *head = NULL;
char *lineptr = NULL;
pid_t child_pid;
char **argv;
size_t argc = 0;
ssize_t flag;
void (*cmd_func)(char **, size_t, char **);
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
if (is_builtin(argv[0]))
{
cmd_func = ex_builtin(argv[0]);
cmd_func(argv, argc, environ); }
else
{
child_pid = fork();
if (child_pid == -1)
exit(1);
if (child_pid == 0)
{
cmd = _path(argv[0], environ);
val = execve(cmd, argv, NULL);
if (val == -1)
{
perror("./shell");
free_array(argv, argc);
exit(0); } }
else
wait(&status);
free_array(argv, argc); } } } }
