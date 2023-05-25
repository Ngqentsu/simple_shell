#include "shell.h"
/**
 * bfree - a function.
 * @ad: a pointer.
 * Return: 0 in the otherwise case and 1 if free
 */
int bfree(void **ad)
{
	if (ad && *ad)
	{
		free(*ad);
		*ad = NULL;
		return (1);
	}
	return (0);
}

