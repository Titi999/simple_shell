#include "main.h"

/**
 *
 *
 *
 *
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

