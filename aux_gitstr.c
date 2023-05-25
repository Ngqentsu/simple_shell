#include "main.h"

/**
 * _strcat - concatenate two strs
 * @dest: char ptr
 * @src: const char ptr.
 * Return: the destination.
 */
char *_strcat(char *dest, const char *src)
{
	int o;
	int j;

	for (o = 0; dest[o] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[o] = src[j];
		o++;
	}

	dest[o] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copies str.
 * @dest: Type char ptrr
 * @src: Type char ptr the src of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{

	size_t b;

	for (b = 0; src[b] != '\0'; b++)
	{
		dest[b] = src[b];
	}
	dest[b] = '\0';

	return (dest);
}
/**
 * _strcmp - Function that compares two strings.
 * @s1: type str1.
 * @s2: type str2.
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int o;

	for (o = 0; s1[o] == s2[o] && s1[o]; o++)
		;

	if (s1[o] > s2[o])
		return (1);
	if (s1[o] < s2[o])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a char,
 * @s: str.
 * @c: char.
 * Return: the ptr to the first occurrence of the character.
 */
char *_strchr(char *s, char f)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == f)
			return (s + i);
	if (*(s + i) == f)
		return (s + i);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
	int i, k, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (k = 0; *(accept + k) != '\0'; k++)
		{
			if (*(s + i) == *(accept + k))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}

