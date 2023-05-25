#include "shell.h"

/**
 *_eputs - input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	if (str == NULL)
		return;

	for (; *str != '\0'; str++)
		_eputchar(*str);
}

/**
 * _eputchar - writes the character c to stderr
 * @d: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char d)
{
	static char buf[WRITE_BUF_SIZE];
	static int buf_len;

	if (buf_len >= WRITE_BUF_SIZE || d == BUF_FLUSH)
	{
		write(STDERR_FILENO, buf, buf_len);
		buf_len = 0;
	}

	if (d != BUF_FLUSH)
		buf[buf_len++] = d;

	return (1);
}


/**
 * _putfd - writes the char c to given fd.
 * @ch: The character to print.
 * @fd: filedescriptor.
 *
 * Return: On success 1.
 */
int _putfd(char ch, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || j > WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
		buf[j++] = ch;
	return (1);
}
/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int k = 0;

	if (!str)
		return (0);
	for (k = 0; str[k]; k++)
		_putfd(str[k], fd);
	return (k);
}

