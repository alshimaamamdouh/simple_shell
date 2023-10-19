#include "shell.h"

/**
 *_strlen - get length of string
 *
 *@str: string
 *
 *Return: lenght of string
*/
int _strlen(char *str)
{
int len = 0;

while (str[len] != '\0')
len++;

return (len);
}

/**
 *_strcmp - compare two strings
 *
 *@str: 1st string
 *@s: 2nd string
 *
 *Return: 1 if it the same, 0 if not equal
*/
int _strcmp(char *str, char *s)
{
int len_str = 0;
int len_s = 0;
int i;
if (str == NULL || s == NULL)
return (0);
else
{
while (str[len_str] != '\0')
len_str++;
while (s[len_s] != '\0')
len_s++;
for (i = 0; i < len_s; i++)
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
return (NULL);

c_size = _strlen(c);
dup = (char *)malloc(sizeof(char) * c_size + 1);
if (dup == NULL)
return (NULL);

temp = dup;
while (*c)
{
*temp = *c;
temp++;
c++;
}
*temp = '\0';
return (dup);
}

/**
 *_strcat - concatenates two strings
 *@dest: last string
 *@src: input string
 *
 * Return: string that concatenates two strings
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}
/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
