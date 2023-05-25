#include "shell.h"
/**
 * _strlen - a function.
 * @r: the str.
 * Return: the integer length of the string
 */
int _strlen(char *r)
{
	int k = 0;

	if (!r)
	{
		return (0);
	}
	while (*r++)
	{
		k++;
	}
	return (k);
}
/**
 * _strcmp - A function that evaluates the similarity between the two strings.
 * @st1: the string 1
 * @st2: the string 2
 * Return: 0 if s1 = s2 and positive if s1 > s2 and negative if s2 > s1
 */
int _strcmp(char *st1, char *st2)
{
	int h = 0, a = 0;

	while (st1[a] != '\0' && st2[a] != '\0')
	{
		if (st1[a] != st2[a])
		{
			h = st1[a] - st2[a];
			return (h);
		}
		a++;
	}
	return (h);
}
/**
 * starts_with - a function that checks heystack start within the needle
 * @hays: th string that we will search for
 * @ndl: to find the substring
 * Return: NULL or the address of the next heystack
 */
char *starts_with(const char *hays, const char *ndl)
{
	while (*ndl)
		if (*ndl++ != *hays++)
		{
			return (NULL);
		}
	return ((char *)hays);

}

/**
 * _strcat - a function that concatenates the two strings
 * @e: the location where we join the string
 * @s: the sequence we will merge at the destination location
 * Return: the concatenated string
 */
char *_strcat(char *e, char *s)
{
	char *res = e;

	while (*e)
	{
		e++;
	}
	while (*s)
	{
		*e++ = *s++;
	}
	*e = *s;
	return (res);
}

