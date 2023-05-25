#include "shell.h"
/**
 **_memset - a function.
 *@c: memory area.
 *@f: fills with the byte
 *@b: the byte amount.
 *Return: to the memory s returned a pointer s
 */
char *_memset(char *c, char f, unsigned int b)
{
	unsigned int a;

	for (a = 0; a < b; a++)
		c[a] = f;
	return (c);
}
/**
 * ffree - a string
 * @ontoal: you can say a one string of alot of strings
 */
void ffree(char **ontoal)
{
	char **q = ontoal;

	if (!ontoal)
		return;
	while (*ontoal)
		free(*ontoal++);
	free(q);
}
/**
 * _realloc - a function that reallocates a couple of blocks of memory
 * @s: a pointer to the previous
 * @oz: previous block byte size
 * @nz: the new block byte size
 * Return: a pointer to be returned
 */
void *_realloc(void *s, unsigned int oz, unsigned int nz)
{
	char *b;

	if (!s)
		return (malloc(nz));
	if (!nz)
		return (free(s), NULL);
	if (nz == oz)
		return (s);

	b = malloc(nz);
	if (!b)
		return (NULL);

	oz = oz < nz ? oz : nz;
	while (oz--)
		b[oz] = ((char *)s)[oz];
	free(s);
	return (b);
}

