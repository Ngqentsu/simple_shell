#include "simpleshell.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: difference between s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
int i;

for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
{
if (s1[i] != s2[i])
{
return (s1[1] - s2[i]);
}
i++;
}
return (0);
}

/**
 * *_strstr - locates a substring
 * @needle: the substring
 * @haystack: the string
 * Return: pointer to the substring, or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
int i = 0;

if (*needle == 0)
{
return (haystack);
}

while (*haystack)
{
if (haystack[i] == needle[i])
{
while (haystack[i] == needle[i])
{
if (needle[i + 1] == '\0')
return (haystack);
i++;
}
}
haystack++;
}
return ('\0');
}
