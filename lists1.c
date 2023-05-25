#include "shell.h"

/**
 * list_len - a function.
 * @n: first node pointer
 * Return: list size
 */
size_t list_len(const list_t *n)
{
	size_t y = 0;

	while (n)
	{
		n = n->next;
		y++;
	}
	return (y);
}
/**
 * list_to_strings - a function.
 * @ptr_1: first node pointer
 * Return: strings array
 */
char **list_to_strings(list_t *ptr_1)
{
	list_t *n = ptr_1;
	size_t a = list_len(ptr_1), b;
	char **ss;
	char *s;

	if (!ptr_1 || !a)
	{
		return (NULL);
	}
	ss = malloc(sizeof(char *) * (a + 1));
	if (!ss)
	{
		return (NULL);
	}
	for (a = 0; n; n = n->next, a++)
	{
		s = malloc(_strlen(n->str) + 1);
		if (!s)
		{
			for (b = 0; b < a; b++)
				free(ss[b]);
			free(ss);
			return (NULL);
		}
		s = _strcpy(s, n->str);
		ss[a] = s;
	}
	ss[a] = NULL;
	return (ss);
}
/**
 * print_list - all linked list printed.
 * @ptr_1: a first node pointer.
 * Return: list size
 */
size_t print_list(const list_t *ptr_1)
{
	size_t c = 0;

	while (ptr_1)
	{
		_puts(convert_number(ptr1->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(ptr_1->str ? ptr_1->str : "(nil)");
		_puts("\n");
		ptr_1 = ptr_1->next;
		c++;
	}
	return (c);
}
/**
 * node_starts_with - return string starting with prefix within a node
 * @n: list head pointer.
 * @rfx: match string.
 * @nc: match.
 * Return: null or you can say match node
 */
list_t *node_starts_with(list_t *n, char *rfx, char nc)
{
	char *z = NULL;

	while (n)
	{
		z = starts_with(n->str, rfx);
		if (z && ((nc == -1) || (*z == nc)))
		{
			return (n);
		}
		n = n->next;
	}
	return (NULL);
}
/**
 * get_node_index - a function.
 * @hp: list head pointer
 * @n: node pointer
 * Return: -1 or index of a node
 */
ssize_t get_node_index(list_t *hp, list_t *n)
{
	size_t c = 0;

	while (hp)
	{
		if (hp == n)
		{
			return (c);
		}
		hp = hp->next;
		c++;
	}
	return (-1);
}

