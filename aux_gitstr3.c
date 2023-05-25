#include "main.h"

/**
 * rev_string - reverses a str.
 * @t: input string.
 * Return: no return.
 */
void rev_string(char *t)
{
	int count = 0, w, j;
	char *str, temp;

	while (count >= 0)
	{
		if (t[count] == '\0')
			break;
		count++;
	}
	str = t;

	for (w = 0; w < (count - 1); w++)
	{
		for (j = w + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}

