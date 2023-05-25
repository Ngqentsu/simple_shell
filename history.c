#include "shell.h"
/**
 * get_history_file - file from history.
 * @finf: a structure parameter
 * Return: a history file that is allocated in the string
 */

char *get_history_file(info_t *finf)
{
	char *ba, *yo;

	yo = _getenv(finf, "HOME=");
	if (!yo)
	{
		return (NULL);
	}
	ba = malloc(sizeof(char) * (_strlen(yo) + _strlen(HIST_FILE) + 2));
	if (!ba)
	{
		return (NULL);
	}
	ba[0] = 0;
	_strcpy(ba, yo);
	_strcat(ba, "/");
	_strcat(ba, HIST_FILE);
	return (ba);
}
/**
 * write_history - a function.
 * @finf: a structure of the parameter
 * Return:in success it return 1 otherwise -1
 */
int write_history(info_t *finf)
{
	ssize_t redfun;
	char *filename = get_history_file(finf);
	list_t *no = NULL;

	if (!filename)
	{
		return (-1);
	}
	redfun = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (redfun == -1)
	{
		return (-1);
	}
	for (no = finf->history; no; no = no->next)
	{
		_putsfd(no->str, redfun);
		_putfd('\n', redfun);
	}
	_putfd(BUF_FLUSH, redfun);
	close(redfun);
	return (1);
}
/**
 * read_history - reads history.
 * @finf: struct of a parameter.
 * Return: 0 otherwise and histcount on success
 */
int read_history(info_t *finf)
{
	int e, final = 0, linecount = 0;
	ssize_t redfun, rdlen, fsize = 0;
	struct stat st;
	char *abuff = NULL, *filename = get_history_file(finf);

	if (!filename)
		return (0);

	redfun = open(filename, O_RDONLY);
	free(filename);
	if (redfun == -1)
		return (0);
	if (!fstat(redfun, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	abuff = malloc(sizeof(char) * (fsize + 1));
	if (!abuff)
		return (0);
	rdlen = read(redfun, abuff, fsize);
	abuff[fsize] = 0;
	if (rdlen <= 0)
		return (free(abuff), 0);
	close(redfun);
	for (e = 0; e < fsize; e++)
		if (abuff[e] == '\n')
		{
			abuff[e] = 0;
			build_history_list(finf, abuff + final, linecount++);
			final = e + 1;
		}
	if (final != e)
		build_history_list(finf, abuff + final, linecount++);
	free(abuff);
	finf->histcount = linecount;
	while (finf->histcount-- >= HIST_MAX)
		delete_node_at_index(&(finf->history), 0);
	renumber_history(finf);
	return (finf->histcount);
}
/**
 * build_history_list - a singly linked list.
 * @finf: a potential arguments.
 * @abuff: a buffer.
 * @linc: a history of a linecount.
 * Return: 0
 */
int build_history_list(info_t *finf, char *abuff, int linc)
{
	list_t *no = NULL;

	if (finf->history)
	{
		no = finf->history;
	}
	add_node_end(&no, abuff, linc);

	if (!finf->history)
	{
		finf->history = no;
	}
	return (0);
}
/**
 * renumber_history - a function.
 * @finf: potential arguments.
 * Return: the newhistcount returned.
 */
int renumber_history(info_t *finf)
{
	list_t *no = finf->history;
	int e = 0;

	while (no)
	{
		no->num = e++;
		no = no->next;
	}
	return (finf->histcount = e);
}

