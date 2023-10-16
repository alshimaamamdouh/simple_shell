#include "shell.h"
/***/
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
