#include "shell.h"
/**
 * _erratoi - a function.
 * @s : the string that will be converted
 * Return: -1 on error and 0 if no number in string and otherwise the number
 */
int _erratoi(char *s)
{
	int b = 0;

	unsigned int long res = 0;

	if (*s == '+')
	{
		s++;
	}
	for (b = 0; s[b] != '\0'; b++)
	{
		if (s[b] >= '0' && s[b] <= '9')
		{
			res *= 10;
			res += (s[b] - '0');
			if (res > INT_MAX)
			{
				return (-1);
			}
		}
		else
		{
			return (-1);
		}
	}
		return (res);
}
/**
 * print_d - a function.
 * @input : is the input
 * @fd : the filedescriptor
 * Return: the number of character.
 */
int print_d(int input, int fd)
{
	int b, cnt = 0;
	unsigned int _abc_, now;
	int (*__putchar)(char) = _putchar;

	if (fd == STDERR_FILENO)
	{
		__putchar = _eputchar;
	}
	if (input < 0)
	{
		_abc_ = -input;
		__putchar('-');
		cnt++;
	}
	else
	{
		_abc_ = input;
	}
	now = _abc_;
	for (b = 1000000000; b > 1; b /= 10)
	{
		if (_abc_ / b)
		{
			__putchar('0' + now / b);
			cnt++;
		}
		now %= b;
	}
	__putchar('0' + now);
	cnt++;

	return (cnt);
}
/**
 * print_error - print a error message
 * @info : return info.
 * @estr : a str.
 * Return: 0 if no number in string and otherwise it return a number
 * and -1 in error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * convert_number - a function.
 * @flags: flags argument.
 * @n: is a number.
 * @base: is a base.
 * Return: a string is returned
 */
char *convert_number(long int n, int base, int flags)
{
	static char *ray;
	char sin = 0;
	static char buf[50];
	char *ptr;
	unsigned long a = n;

	if (!(flags & CONVERT_UNSIGNED) && n < 0)
	{
		a = -n;
		sin = '-';
	}
	ray = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';

	do	{
		*--ptr = ray[a % base];
		a /= base;
	} while (a != 0);

	if (sin)
		*--ptr = sin;
	return (ptr);
}
/**
 * remove_comments - a function.
 * @abuff : the address.
 * Return: 0 always
 */
void remove_comments(char *abuff)
{
	int a;

	for (a = 0; abuff[a] != '\0'; a++)
	{
		if (abuff[a] == '#' && (!a || abuff[a - 1] == ' '))
		{
			abuff[a] = '\0';
			break;
		}
}
}

