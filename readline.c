#include "main.h"
/**
 * read_line - reads a line from stdin
 * Return: pointer to line
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0; /* have getline allocate a buffer for us*/

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);  /*We received an EOF*/
		}
		else
		{
			perror("lsh: getline\n");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

