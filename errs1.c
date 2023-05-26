#include "main.h"

/**
 * _eputs - A function that prints an input string
 * @str: string to be printed
 *
 * Return: NULL
 */

void _eputs(char *str)
{
	int y = 0;

	if (!str)
		return;
	while (str[y] != '\0')
	{
		_eputchar(str[y]);
		y++;
	}
}

/**
 * _eputchar - Writes the char c to stderr
 * @c: The char to be printed
 *
 * Return: 1 on success, -1 on error, and
 * errno is set appropriately.
 */

int _eputchar(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}

/**
 * _putfd - Writes the char c to given fd
 * @c: The char to be printed
 * @fd: filedescriptor to write to
 *
 * Return: 1 on success, -1 on error,
 * and errno is set appropriately.
 */

int _putfd(char c, int fd)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _putsfd - A function that prints an input string
 * @str: String to be printed
 * @fd: Filedescriptor to write to
 *
 * Return: The number of chars to put
 */

int _putsfd(char *str, int fd)
{
	int l = 0;

	if (!str)
		return (0);
	while (*str)
	{
		l += _putfd(*str++, fd);
	}
	return (l);
}
