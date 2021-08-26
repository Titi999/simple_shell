#include "main.h"

/**
 * no_nl - removes new line from a string
 * @l: pointer to string
 *
 * Return: void
 */

void no_nl(char *l)
{
	int i = 0;

	while (l[i])
	{
		if (l[i] == '\n')
		{
			l[i] = '\0';

			return;
		}
		i++;
	}
}

