#include "shell.h"

/***/
int _strlen(char *str)
{
int len = 0;

while (str[len] != '\0')
len++;

return (len);
}

/***/
int _strcmp(char *str, char *s)
{
int len_str = 0;
int len_s = 0;
int i;
if (str == NULL || s == NULL)
return (0);
else {
while (str[len_str] != '\0')
len_str++;
while (s[len_s] != '\0')
len_s++;
for (i = 0; i < len_s ; i++)
if (str[i] != s[i])
return (0);
}
return (1);
}
