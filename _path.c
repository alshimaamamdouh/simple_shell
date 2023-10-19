#include "shell.h"
/**
 * *_path - add path to command
 * @cmd: pointer to command
 * @environ: shell environ
 * Return: command
 */
char *_path(char *cmd, char **environ)
{
char *path, *temp, *path_token, *final;
int cmd_length, path_length, f;
struct stat stat_buff;
path = _getenv("PATH", environ, &f);
if (path)
{
temp = _strdup(path);
cmd_length = _strlen(cmd);
path_token = strtok(temp, ":");
while (path_token != NULL)
{
path_length = _strlen(path_token);
final = malloc(cmd_length + path_length + 2);
_strcpy(final, path_token);
_strcat(final, "/");
_strcat(final, cmd);
_strcat(final, "\0");
if (stat(final, &stat_buff) == 0)
{
free(temp);
return (final);
}
else
{
free(final);
path_token = strtok(NULL, ":");
}
}
if (stat(cmd, &stat_buff) == 0)
{
return (cmd);
}
return (NULL);
}
return (NULL);
}
