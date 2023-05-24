#include "main.h"

/**
 * get_builtin - builtin.
 * @cmd: command.
 * Return: function ptr of the builtin cmd
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int l;

	for (l = 0; builtin[l].name; l++)
	{
		if (_strcmp(builtin[l].name, cmd) == 0)
			break;
	}

	return (builtin[l].f);
}

