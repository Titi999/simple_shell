#include "main.h"
/**
 * count - counts commands and options entered by user
 * @buffer: given command
 * Return: Number of arguments
 */
int count(char *buffer)
{
	int i = 0;
	
	while (buffer[i] != '\0')
	{
		i++;
	}
	return (++i);
}

/**
 * parsing - Function that splits a given string
 * @buffer: Given string
 * @characters: number of elements
 * @delim: delimiters
 * Return: Tokenized string
 */

char **parsing(char *buffer, int characters, char *delim)
{
	int counter = 0;
	char *token = NULL;
	char **token_necklace = malloc(sizeof(char *) * characters);

	if (token_necklace == NULL)
	{
		return (NULL);
	}
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		token_necklace[counter] = _strdup(token);
		if (token_necklace[counter] == NULL)
		{
			_free(2, token_necklace);
			return (NULL);
		}
		token = strtok(NULL, delim);
		counter++;
	}
	token_necklace[counter] = NULL;
	return (token_necklace);
}

