#include "shell.h"

/**
 * hsh - main shell loop.
 * @finf: info structure and the parameter.
 * @av: the vector argument.
 * Return: 1 on error code and 0 on success
 */
int hsh(info_t *finf, char **av)
{
	ssize_t s = 0;
	int tobltin_r = 0;

	while (s != -1 && tobltin_r != -2)
	{
		clear_info(finf);
		if (interactive(finf))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		s = get_input(finf);
		if (s != -1)
		{
			set_info(finf, av);
			tobltin_r = find_builtin(finf);
			if (tobltin_r == -1)
				find_cmd(finf);
		}
		else if (interactive(finf))
			_putchar('\n');
		free_info(finf, 0);
	}
	write_history(finf);
	free_info(finf, 1);
	if (!interactive(finf) && finf->status)
		exit(finf->status);
	if (tobltin_r == -2)
	{
		if (finf->err_num == -1)
			exit(finf->status);
		exit(finf->err_num);
	}
	return (tobltin_r);
}
/**
 * find_builtin - built command has to be found.
 * @finf: the return information.
 * Return: -1 , 0, 1, -2 depend on the condition
 */
int find_builtin(info_t *finf)
{
	int b, bltin_r = -1;
	builtin_table bltintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (b = 0; bltintbl[b].type; b++)
		if (_strcmp(finf->argv[0], bltintbl[b].type) == 0)
		{
			finf->line_count++;
			bltin_r = bltintbl[b].func(finf);
			break;
		}
	return (bltin_r);
}

/**
 * find_cmd - a function that fixed in the path a command
 * @finf: the return information structure and the parameter
 * Return: nothing
 */
void find_cmd(info_t *finf)
{
	char *pth = NULL;
	int a, c;

	finf->path = finf->argv[0];
	if (finf->linecount_flag == 1)
	{
		finf->line_count++;
		finf->linecount_flag = 0;
	}
	for (a = 0, c = 0; finf->arg[a]; a++)
		if (!is_delim(finf->arg[a], " \t\n"))
			c++;
	if (!c)
		return;

	pth = find_path(finf, _getenv(finf, "PATH="), finf->argv[0]);
	if (pth)
	{
		finf->path = pth;
		fork_cmd(finf);
	}
	else
	{
		if ((interactive(finf) || _getenv(finf, "PATH=")
			|| finf->argv[0][0] == '/') && is_cmd(finf, finf->argv[0]))
			fork_cmd(finf);
		else if (*(finf->arg) != '\n')
		{
			finf->status = 127;
			print_error(finf, "not found\n");
		}
	}
}

/**
 * fork_cmd - a function.
 * @finf: the return info struct and parameter.
 * Return: nothing
 */
void fork_cmd(info_t *finf)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(finf->path, finf->argv, get_environ(finf)) == -1)
		{
			free_info(finf, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(finf->status));
		if (WIFEXITED(finf->status))
		{
			finf->status = WEXITSTATUS(finf->status);
			if (finf->status == 126)
				print_error(finf, "Permission denied\n");
		}
	}
}

