#include "shell.h"

/**
 *print_env - print env
 *@environ: shell environ
 *
 */

void print_env(char **environ)
{
int i;
if (environ)
{
for (i = 0 ; environ[i] != 0; i++)
{
write(1, environ[i], _strlen(environ[i]));
write(1, "\n", _strlen("\n"));
}
}
}
