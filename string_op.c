#include "simpleshell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 * Return: length
 */
int _strlen(char *s)
{
int i = 0;

while (s[i])
{
i++;
}
return (i);
}

/**
 * *_strcpy - copies the string pointed to by src
 * @src: source
 * @dest: destination
 * Return: char
 */
char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i] != '\0'; i++)
{
*(dest + i) = *(src + i);
}
*(dest + i) = '\0';
return (dest);
}

/**
 * *_strdup - returns a pointer to a newly allocated space in memory
 * @str: pointer to char
 * Return: Always 0 (Success)
 */
char *_strdup(char *str)
{
unsigned int i, j;
char *c;

if (str == NULL)
{
return (NULL);
}
i = 0;
while (str[i] != '\0')
{
i++;
}
c = malloc(sizeof(char) * (i + 1));
if (c == NULL)
return (NULL);
for (j = 0; j < i; j++)
c[j] = str[j];
return (c);
}

/**
 * *_strcat - concatenates two strings
 * @src: source
 * @dest: destination
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
int i = 0;
int j = 0;

while (dest[i] != '\0')
{
i++;
}
while (src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}
dest[i] = '\0';
return (dest);
}

/**
 * _puts -  prints a string
 * @str: the string
 * Return: void
 */
void _puts(char *str)
{
for (; *str != '\0'; str++)
{
_putchar(*str);
}
_putchar('\n');
}
