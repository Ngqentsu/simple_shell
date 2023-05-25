#include "main.h"

/**
 * get_len - Get the lenght of num.
 * @l: type int num.
 * Return: Lenght of a num.
 */
int get_len(int l)
{
	unsigned int l1;
	int lenght = 1;

	if (l < 0)
	{
		lenght++;
		l1 = l * -1;
	}
	else
	{
		l1 = l;
	}
	while (l1 > 9)
	{
		lenght++;
		l1 = l1 / 10;
	}

	return (lenght);
}
/**
 * aux_itoa - func converts int to str.
 * @l: type int number
 * Return: Str.
 */
char *aux_itoa(int l)
{
	unsigned int l1;
	int lenght = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (l < 0)
	{
		l1 = l * -1;
		buffer[0] = '-';
	}
	else
	{
		l1 = l;
	}

	lenght--;
	do {
		*(buffer + lenght) = (n1 % 10) + '0';
		l1 = l1 / 10;
		lenght--;
	}
	while (l1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, k;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (k = count - size; k < count; k++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}

