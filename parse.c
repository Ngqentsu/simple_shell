#include "shell.h"

/**
 * is_cmd - exec cmd.
 * @finf : struct info.
 * @pa: path.
 * Return: 0 in the event of a false condition and 1 if the condition is true.
 */
int is_cmd(info_t *finf, char *pa)
{
	struct stat st;

	(void)finf;
	if (!pa || stat(pa, &st))
	{
		return (0);
	}

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - characters to be duplicated
 * @pa: string path
 * @strt: index of starting
 * @stp: index to stop
 * Return: pointer to return a new buffer
 */
char *dup_chars(char *pa, int strt, int stp)
{
	static char abuff[1024];
	int a = 0, c = 0;

	for (c = 0, a = strt; a < stp; a++)
	{
		if (pa[a] != ':')
		{
			abuff[c++] = pa[a];
		}
	}
	abuff[c] = 0;
	return (abuff);
}
/**
 * find_path - a function.
 * @finf: the struct info.
 * @pa: string path
 * @cemde: to find the cmd
 * Return: null or if the path if cmd found
 */
char *find_path(info_t *finf, char *pa, char *cemde)
{
	int k = 0, place_now = 0;
	char *pth;

	if (!pa)
	{
		return (NULL);
	}
	if ((_strlen(cemde) > 2) && starts_with(cemde, "./"))
	{
		if (is_cmd(finf, cemde))
		{
			return (cemde);
		}
	}
	while (1)
	{
		if (!pa[k] || pa[k] == ':')
		{
			pth = dup_chars(pa, place_now, k);
			if (!*pth)
				_strcat(pth, cemde);
			else
			{
				_strcat(pth, "/");
				_strcat(pth, cemde);
			}
			if (is_cmd(finf, pth))
				return (pth);
			if (!pa[k])
				break;
			place_now = k;
		}
		k++;
	}
	return (NULL);
}

