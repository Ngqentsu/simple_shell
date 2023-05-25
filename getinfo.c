#include "shell.h"
/**
 * clear_info - a function.
 * @info: address of the structure
 */
void clear_info(info_t *info)
{
	info->argc = 0;
	info->argv = NULL;
	info->arg = NULL;
	info->path = NULL;
}
/**
 * set_info - a function.
 * @info: address.
 * @av: a vector of the argument
 */
void set_info(info_t *info, char **av)
{
	int b = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (b = 0; info->argv && info->argv[b]; b++)
			;
		info->argc = b;

		replace_alias(info);
		replace_vars(info);
	}
}
/**
 * free_info - a function.
 * @info: adress.
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}

