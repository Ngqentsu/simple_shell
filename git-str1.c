#include "shell.h"
/**
 * _strcpy - a function.
 * @e: the location where we insert the string
 * @s: the origin from which we replicate the string
 * Return: the copied string to destination
 */
char *_strcpy(char *e, char *s)
{
	int a = 0;

	if (e == s || s == 0)
	{
		return (e);
	}
	while (s[a])
	{
		e[a] = s[a];
		a++;
	}
	e[a] = 0;
	return (e);
}
/**
 * _strdup - a function.
 * @t: the string to be checked and to be duplicated
 * Return: the duplicated string
 */
char *_strdup(const char *t)
{
	char *res;
	int leng = 0;

	if (t == NULL)
	{
		return (NULL);
	}
	while (*t++)
	{
		leng++;
	}
	res = malloc(sizeof(char) * (leng + 1));
	if (!res)
	{
		return (NULL);
	}
	for (leng++; leng--;)
	{
		res[leng] = *--t;
	}
	return (res);
}
/**
 *_puts - a function.
 *@s: the string that will be printed
 * Return: there is nothing to be returned
 */
void _puts(char *s)
{
	int e = 0;

	if (!s)
	{
		return;
	}
	while (s[e] != '\0')
	{
		_putchar(s[e]);
		e++;
	}
}
/**
 * _putchar - a function that print out a single character.
 * @cha: The printed character.
 * Return: 1 in case of success
 * erno is set approbiately and -1 in the case of error
 */
int _putchar(char cha)
{
	static int z;
	static char abuff[WRITE_BUF_SIZE];

	if (cha == BUF_FLUSH || z >= WRITE_BUF_SIZE)
	{
		write(1, abuff, z);
		z = 0;
	}
	if (cha != BUF_FLUSH)
	{
		abuff[z++] = cha;
	}
	return (1);
}

