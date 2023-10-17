#include "shell.h"
void intractive_mode(void)
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
  //print propmt
print_prompt();
//get command and token
head =  get_command(lineptr, head, &flag);
//if press ctrl+D
if (flag == -1)
break;
if (head != NULL)
{
  // create argv array
argv = linked_list_to_array(head, &argc);
//ask about built in exit command 
if (_strcmp(argv[0], "exit"))
{
free_list(head);
free_array(argv, argc);
free(lineptr);
exit(0); 
}
else if(_strcmp(argv[0], "env"))
{
char * env_info;
int env_offset;
extern char **environ;
env_info = _getenv("HOSTNAME", environ, &env_offset);
write(1, "USER=", _strlen("USER="));
write(1, env_info, _strlen(env_info));
write(1, "\n", _strlen("\n"));
env_info = _getenv("LANGUAGE", environ, &env_offset);
write(1, "LANGUAGE=", _strlen("LANGUAGE="));
write(1, env_info, _strlen(env_info));
write(1, "\n", _strlen("\n"));
env_info = _getenv("SHLVL", environ, &env_offset);
write(1, "SHLVL=", _strlen("SHLVL="));
write(1, env_info, _strlen(env_info));
write(1, "\n", _strlen("\n"));
env_info = _getenv("HOME", environ, &env_offset);
write(1, "HOME=", _strlen("HOME="));
write(1, env_info, _strlen(env_info));
write(1, "\n", _strlen("\n"));
env_info = _getenv("HOSTNAME", environ, &env_offset);
write(1, "LOGNAME=", _strlen("LOGNAME="));
write(1, env_info, _strlen(env_info));
write(1, "\n", _strlen("\n"));
env_info = _getenv("TERM", environ, &env_offset);
write(1, "TERM=", _strlen("TERM="));
write(1, env_info, _strlen(env_info));
write(1, "\n", _strlen("\n"));
env_info = _getenv("PATH", environ, &env_offset);
write(1, "PATH=", _strlen("PATH="));
write(1, env_info, _strlen(env_info));
write(1, "\n", _strlen("\n"));	
}
else
{
// child process
child_pid = fork();
if (child_pid == -1)
exit(1);
if (child_pid == 0)
{
  //execute command like /bin/ls 
val = execve(argv[0], argv, NULL);
if (val == -1)
  {perror("ERROR");
free_list(head);
free_array(argv, argc);
//free(lineptr);
 exit(0); }
 }
else
   //parent 
wait(&status);
//free memory
free_list(head);
free_array(argv, argc); 
}
}
}
write(1, "exit\n", _strlen("exit\n"));
}
