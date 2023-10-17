#include "shell.h"

/**
 *print_env - print env
 *
 */

void print_env(void)
{
char *env_info;
int env_offset, i;
extern char **environ;
char *c[7] = {"HOSTNAME", "LANGUAGE", "SHLVL",

	"HOME", "HOSTNAME", "TERM", "PATH"};
char *c_p[7] = {"USER=", "LANGUAGE=", "SHLVL=",

	"HOME=", "LOGNAME=", "TERM=", "PATH="};

for (i = 0; i < 7; i++)
{
env_info = _getenv(c[i], environ, &env_offset);
if (env_info)
{
write(1, c_p[i], _strlen(c_p[i]));
write(1, env_info, _strlen(env_info));
write(1, "\n", _strlen("\n"));
}
else
{
write(1, "", _strlen(""));
}
}
}
