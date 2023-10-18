#include "shell.h"
void intractive_mode(int is_intractive)
{
int status;
list_t *head = NULL;
char *lineptr = NULL;
int val;
pid_t child_pid;
char **argv;
size_t argc = 0;
ssize_t flag;
while (1)
{
/* print propmt */
if (is_intractive)
print_prompt();
/*get command and tokenize*/
head =  get_command(lineptr, head, &flag);
/*if press ctrl+D*/
if (flag == -1)
break;
if (head != NULL)
{
/*create argv array*/
argv = linked_list_to_array(head, &argc);
/*ask about built in exit command*/ 
if (_strcmp(argv[0], "exit"))
{
free_list(head);
free_array(argv, argc);
free(lineptr);
exit(0);

}
else if (_strcmp(argv[0], "env"))
{
print_env();

}
else
{
/*child process*/
child_pid = fork();
if (child_pid == -1)
exit(1);
if (child_pid == 0)
{
/*execute command like /bin/ls*/ 
val = execve(argv[0], argv, NULL);
if (val == -1)
{
perror("ERROR");
free_list(head);
free_array(argv, argc);
exit(0); }
}
else
/*parent*/ 
wait(&status);
/*free memory*/
free_list(head);
free_array(argv, argc); 
}
}
}
write(1, "exit\n", _strlen("exit\n"));
}
