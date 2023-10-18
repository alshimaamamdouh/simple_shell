#include "shell.h"
/**
 *print_prompt - print prompt of shell
 *
 *@is_intractive: int varible for print if = 1
*/
void print_prompt(int is_intractive)
{
char *prompt = "cisfun$ ";
int len = 0;
if (is_intractive)
{
while (prompt[len] != '\0')
len++;

write(1, prompt, len);
}
}
