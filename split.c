#include "main.h"

/**
 * split - splits a string into specified substrings
 * @line: original string
 *
 * Return:pointer to pointer to substrings
 *
 */

char **split(char *line)
{
	int bufsize = 64, index = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	no_nl(line);
	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[index] = token;
		index++;
		if (index >= bufsize)
		{
			bufsize += 64;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				free(tokens_backup);
				fprintf(stderr, "lsh: allocation error\n");

				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " ");
	}
	tokens[index] = NULL;
	return (tokens);
}

