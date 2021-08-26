#include "main.h"

/**
 * _print - prints a string
 * @src: The string to be printed
 * Return: Number of characters printed
 */
int _print(char *src)
{
	int len, ret;

	for (len = 0; src[len]; ++len)
		;

	ret = write(STDOUT_FILENO, src, len);
	if (ret != len)
	{
		write(STDERR_FILENO, "Error writing\n", 14);
		exit(71);
	}
	return (ret);
}
