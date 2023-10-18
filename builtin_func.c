#include "shell.h"
/**
 *is_builtin - check if the command built in or not
 *
 *@cmd: command which is cheacked
 *
 *Return: return 1 if is builtin command
 * 0 if not
*/
int is_builtin(char *cmd)
{
int i;
built_in_command b_command[] = {
{"env", env_command},
{"exit", exit_command},
};
for (i = 0; i < 2; i++)
if (_strcmp(b_command[i].command, cmd))
return (1);
return (0);
}
/**
*ex_builtin - execute built in function
*
*@cmd: command
*
*Return: pointer to function which is executed
*/
void (*ex_builtin(char *cmd))(char **, size_t, char **)
{
int i, result;
built_in_command b_command[] = {
{"env", env_command},
{"exit", exit_command},
};
for (i = 0; i < 2; i++)
{
result = _strcmp(b_command[i].command, cmd);
if (result)
return (b_command[i].func);
}
return (NULL);
}
/**
 *exit_command - execute exit command
 *
 *@arr: pointer to array to be freed
 *@s: size of array
 *@env: enviroment vaiables
*/
void exit_command(char **arr, size_t s, char **env __attribute__((unused)))
{
free_array(arr, s);
exit(0);
}
/**
 *env_command - execute env command
 *
 *@arr: pointer to array to be freed
 *@s: size of array
 *@env: enviroment vaiables
*/
void env_command(char **arr, size_t s, char **env __attribute__((unused)))
{
free_array(arr, s);
print_env(env);
}
