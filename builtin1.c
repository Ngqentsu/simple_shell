#include "shell.h"
/**
 * _myhistory - list of history.
 * @finf: potential arg.
 *  Return: 0
 */
int _myhistory(info_t *finf)
{
	print_list(finf->history);
	return (0);
}
/**
 * unset_alias - slias is set to string
 * @finf: structure parameter
 * @t: alias string
 * Return: 1 on error and 0 on success
 */
int unset_alias(info_t *finf, char *t)
{
	char *g, e;
	int r;

	g = _strchr(t, '=');
	if (!g)
		return (1);
	e = *g;
	*g = 0;
	r = delete_node_at_index(&(finf->alias),
		get_node_index(finf->alias, node_starts_with(finf->alias, t, -1)));
	*g = e;
	return (r);
}
/**
 * set_alias - a function that the string get set by alias
 * @finf: the structure parameter
 * @s: alias string
 * Return: 1 on error and 0 on success
 */
int set_alias(info_t *finf, char *s)
{
	char *g;

	g = _strchr(s, '=');
	if (!g)
		return (1);
	if (!*++g)
		return (unset_alias(finf, s));

	unset_alias(finf, s);
	return (add_node_end(&(finf->alias), s, 0) == NULL);
}
/**
 * print_alias - alias string get printed
 * @n: node of the alias
 * Return: its always 1 on error and 0 on success
 */
int print_alias(list_t *n)
{
	char *g = NULL, *x = NULL;

	if (n)
	{
		g = _strchr(n->str, '=');
		for (x = n->str; x <= g; x++)
			_putchar(*x);
		_putchar('\'');
		_puts(g + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - alias builtinn get mimics
 * @finf: potential arguments contained in a structure
 *  Return: 0 in all time
 */
int _myalias(info_t *finf)
{
	int a = 0;
	char *b = NULL;
	list_t *m = NULL;

	if (finf->argc == 1)
	{
		m = finf->alias;
		while (m)
		{
			print_alias(m);
			m = m->next;
		}
		return (0);
	}
	for (a = 1; finf->argv[a]; a++)
	{
		b = _strchr(finf->argv[a], '=');
		if (b)
			set_alias(finf, finf->argv[a]);
		else
			print_alias(node_starts_with(finf->alias, finf->argv[a], '='));
	}

	return (0);
}

