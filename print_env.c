#include "shell.h"

/**
 *print_env - print env
 *
 */

void print_env(void)
{
int i;
extern char **environ;
for (i = 0 ; environ[i] != 0; i++)
{
if (environ[i])
{
write(1, environ[i], _strlen(environ[i]));
write(1, "\n", _strlen("\n"));
}
else
{
write(1, "\n", _strlen("\n"));
}
}
}
