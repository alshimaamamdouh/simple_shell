#include "shell.h"
void print_prompt(void)
{
char *prompt = "cisfun $ ";
int len = 0;

while (prompt[len] != '\0')
len++;

write(1, prompt, len);
}
