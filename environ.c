#include "shell.h"
/**
 * _myenv - a function.
 * @finf: a structure.
 * Used to maintain constant function prototype.
 * Return: 0 Always
 */
int _myenv(info_t *finf)
{
	print_list_str(finf->env);
	return (0);
}

/**
 * _getenv - a function that get the value of a variablen in an eviron
 * @finf: potential arguments contained in as structure
 * @n: env var name
 * Return: a null value
 */
char *_getenv(info_t *finf, const char *n)
{
	list_t *no = finf->env;
	char *b;

	while (no)
	{
		b = starts_with(no->str, n);
		if (b && *b)
			return (b);
		no = no->next;
	}
	return (NULL);
}
/**
 * _mysetenv - a function.or modify the variable that is existed
 * @finf: a potential arguments contained in a structure
 *  Return: 0
 */
int _mysetenv(info_t *finf)
{
	if (finf->argc != 3)
	{
		_eputs("the number of argument is incorrect\n");
		return (1);
	}
	if (_setenv(finf, finf->argv[1], finf->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - a function that removes the environment variable
 * @finf: potential arguments contained in a structure
 *  Return: 0 in all time
 */
int _myunsetenv(info_t *finf)
{
	int v;

	if (finf->argc == 1)
	{
		_eputs("the arguments is too much.\n");
		return (1);
	}
	for (v = 1; v <= finf->argc; v++)
		_unsetenv(finf, finf->argv[v]);

	return (0);
}
/**
 * populate_env_list - a function that populates an env linked list
 * @finf: potential arguments contained in a structure
 * Return: 0 in all time
 */
int populate_env_list(info_t *finf)
{
	list_t *no = NULL;
	size_t s;

	for (s = 0; environ[s]; s++)
		add_node_end(&no, environ[s], 0);
	finf->env = no;
	return (0);
}

