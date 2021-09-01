#include "main.h"
/**
 * count - counts commands and options entered by user
 * @buffer: given command
 * Return: Number of arguments
 */
int count(char *buffer)
{
	int pearls = 0;
	char *delimiter = " =:'\n''\t'";
	int i = 0;
	int j = 0;

	while (buffer[i] != '\0')
	{
		for (j = 0; delimiter[j] != '\0'; j++)
		{
			if (buffer[i] == delimiter[j])
			{
				pearls++;
				break;
			}
		}
		i++;
	}
	return (pearls + 1);
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
			free(token_necklace);
			return (NULL);
		}
		token = strtok(NULL, delim);
		counter++;
	}
	token_necklace[counter] = NULL;
	return (token_necklace);
}

