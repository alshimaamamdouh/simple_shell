#include "shell.h"
/**
 *main - main start from here
 *
 *@ac: integer type
 *@av: array of char
 *
 *Return: return 0
*/
int main(int ac, char **av)
{
int is_intractive = isatty(STDIN_FILENO);
if (ac == 2)
{
non_intractive_mode(av[1]);
}
else
{
intractive_mode(is_intractive);
}
return (0);
}
