#include "shell.h"
/**
 * _strncpy - a function.
 * @e : the string 
 * @sr : the place that we will copy from
 * @x: the number of characters to be copied.
 * Return: the string that is copied
 */
char *_strncpy(char *e, char *sr, int x)
{
	int a, b;
	char *d = e;

	a = 0;
	while (sr[a] != '\0' && a < x - 1)
	{
		e[a] = sr[a];
		a++;
	}
	if (a < x)
	{
		b = a;
		while (b < x)
		{
			d[b] = '\0';
			b++;
		}
	}
	return (d);
}
/**
 * _strncat - a function.
 * @e : the string.
 * @sr : the string
 * @x : the number of bytes that can be used
 * Return: the concatenated string
 */
char *_strncat(char *e, char *sr, int x)
{
	int a, b;
	char *d = e;

	a = 0;
	b = 0;
	while (e[a] != '\0')
		a++;
	while (sr[b] != '\0' && b < x)
	{
		e[a] = sr[b];
		a++;
		b++;
	}
	if (b < x)
		e[a] = '\0';
	return (d);
}
/**
 **_strchr - a function.
 *@str: the string to be measured
 *@h: the character we are looking for
 *Return: a pointer to the memory
 */
char *_strchr(char *str, char h)
{
	do {
		if (*str == h)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}

