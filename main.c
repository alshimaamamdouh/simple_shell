#include "shell.h"
/**
 *main - main start from here
 *
 *@ac: integer type
 *@av: array of char
 *@environ: shell environ
 *
 *Return: return 0
*/
int main(int ac, char **av, char **environ)
{
int is_intractive = isatty(STDIN_FILENO);
if (ac == 2)
{
non_intractive_mode(av[1]);
}
else
{
intractive_mode(is_intractive, environ);
if (is_intractive)
write(1, "exit\n\n [Disconnected...]", _strlen("exit\n\n [Disconnected...]"));

}
return (0);
}
