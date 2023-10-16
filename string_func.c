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

/**
 *_strdup - duplicate a string
 *@c: input pointer
 *Return: pointer
 */

char *_strdup(char *c)
{
int c_size;
static char *dup;
char *temp;
if (c == NULL)
return((char *)NULL);

c_size = _strlen(c);
dup = (char *)malloc(sizeof(char)*c_size+1);
if (dup == NULL)
return((char *)NULL);

temp= dup;
while (*c)
{
*temp = *c;
temp++;
c++;
}
*temp = '\0';
return(dup);
}
