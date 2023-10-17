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
if (ac == 2)
{
non_intractive_mode(av[1]);
}
else
{
intractive_mode();
}
return (0);
}
