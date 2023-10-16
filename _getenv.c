#include "shell.h"

/**
 * _getenv - gets environ
 * @environ: builtin 
 * @name: icut pointer
 * @offset: icut pointer
 * Return: final or null
 */

char *_getenv(const char *name, char **environ, int *offset)
{
int n, i;
const char *c;
char **p, *cp;
if (name == NULL || environ == NULL)
return (NULL);

for (c = name; *c && *c != '='; ++c)
;

n = c - name;
for (p = environ; (cp = *p) != NULL; ++p) 
{
for (c = name, i = n; i && *cp; i--)
if (*cp++ != *c++)
break;

if (i == 0 && *cp++ == '=') 
{
*offset = p - environ;
return (cp);
}
}
return (NULL);
}

