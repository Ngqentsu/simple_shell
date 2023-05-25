#include "shell.h"

/**
 * _myexit - to exit the shell
 * @info: a Structure that is containing potential arguments.
 *  Return: it exits with a given exit conditions
 *         (0) if it is info argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int ec;

	if (info->argv[1])
	{
		ec = _erratoi(info->argv[1]);
		if (ec == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of a process.
 * @info: a Structure that is containing potential arguments.
 *  Return: 0 Always
 */
int _mycd(info_t *info)
{
	char *t, *d, buff[1024];
	int changedir_r;

	t = getcwd(buff, 1024);
	if (!t)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		d = _getenv(info, "HOME=");
		if (!d)
			changedir_r =
				chdir((d = _getenv(info, "PWD=")) ? d : "/");
		else
			changedir_r = chdir(d);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(t);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		changedir_r =
			chdir((d = _getenv(info, "OLDPWD=")) ? d : "/");
	}
	else
		changedir_r = chdir(info->argv[1]);
	if (changedir_r == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buff, 1024));
	}
	return (0);
}

/**
 * _myhelp - a function that changes.
 * @info: a Structure that is containing potential arguments.
 *  Return: 0 Always
 */
int _myhelp(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}

