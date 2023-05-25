#include "main.h"

/**
 * cmp_env_name - compares env variables names.
 * @nenv: name of the en variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - get an environment variable
 * @name: name.
 * @_environ: variable of environment
 *
 * Return: value of the environ variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int w, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (w = 0; _environ[w]; w++)
	{
		/* If name and env are equal */
		mov = cmp_env_name(_environ[w], name);
		if (mov)
		{
			ptr_env = _environ[w];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - prints the eviron var.
 *
 * @datash: relevant to data.
 * Return: 1 or 0.
 */
int _env(data_shell *datash)
{
	int k, j;

	for (k = 0; datash->_environ[k]; k++)
	{

		for (j = 0; datash->_environ[k][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[k], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}

