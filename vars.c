#include "shell.h"

/**
 * is_chain - a function that test the chain
 * @finf: a structure parameter
 * @abuff: buffer char
 * @c: address
 * Return:0 in otherwise condition and 1 if is chain delimeter
 */
int is_chain(info_t *finf, char *abuff, size_t *c)
{
	size_t h = *c;

	if (abuff[h] == '|' && abuff[h + 1] == '|')
	{
		abuff[h] = 0;
		h++;
		finf->cmd_buf_type = CMD_OR;
	}
	else if (abuff[h] == '&' && abuff[h + 1] == '&')
	{
		abuff[h] = 0;
		h++;
		finf->cmd_buf_type = CMD_AND;
	}
	else if (abuff[h] == ';')
	{
		abuff[h] = 0;
		finf->cmd_buf_type = CMD_CHAIN;
		abuff[h] = 0;
		finf->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*c = h;
	return (1);
}

/**
 * check_chain - a function.
 * @finf: the structure parameter
 * @abuff: buffer char
 * @ad: the current pointer in a buffer adress.
 * @d : a buf starting position
 * @l: buf length
 * Return: nothing
 */
void check_chain(info_t *finf, char *abuff, size_t *ad, size_t d, size_t l)
{
	size_t h = *ad;

	if (finf->cmd_buf_type == CMD_AND)
	{
		if (finf->status)
		{
			abuff[d] = 0;
			h = l;
		}
	}
	if (finf->cmd_buf_type == CMD_OR)
	{
		if (!finf->status)
		{
			abuff[d] = 0;
			h = l;
		}
	}

	*ad = h;
}

/**
 * replace_alias - the tokenized string get replaced in the alias
 * @finf: the structure parameter
 * Return: in otherwise 0 and 1 if its replaced
 */
int replace_alias(info_t *finf)
{
	int a;
	list_t *n;
	char *c;

	for (a = 0; a < 10; a++)
	{
		n = node_starts_with(finf->alias, finf->argv[0], '=');
		if (!n)
		{
			return (0);
		}
		free(finf->argv[0]);
		c = _strchr(n->str, '=');
		if (!c)
		{
			return (0);
		}
		c = _strdup(c + 1);
		if (!c)
		{
			return (0);
		}
		finf->argv[0] = c;
	}
	return (1);
}
/**
 * replace_vars - in the tokenized string the vars get replaced
 * @finf: a structure parameter
 * Return: 0 otherwise and 1 if replaced
 */
int replace_vars(info_t *finf)
{
	int d = 0;
	list_t *n;

	for (d = 0; finf->argv[d]; d++)
	{
		if (finf->argv[d][0] != '$' || !finf->argv[d][1])
			continue;

		if (!_strcmp(finf->argv[d], "$?"))
		{
			replace_string(&(finf->argv[d]),
				_strdup(convert_number(finf->status, 10, 0)));
			continue;
		}
		if (!_strcmp(finf->argv[d], "$$"))
		{
			replace_string(&(finf->argv[d]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		n = node_starts_with(finf->env, &finf->argv[d][1], '=');
		if (n)
		{
			replace_string(&(finf->argv[d]),
				_strdup(_strchr(n->str, '=') + 1));
			continue;
		}
		replace_string(&finf->argv[d], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - a function.
 * @o: old string address.
 * @p: the new string address.
 * Return: 0 otherwise and 1 if replaced
 */
int replace_string(char **o, char *p)
{
	free(*p);
	*o = p;
	return (1);
}

