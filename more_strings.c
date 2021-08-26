#include "main.h"
/**
 * _strcat - concatenates two strings
 * @dest: string 1
 * @src: string 2
 * Return: concatenated string with overwritten null byte
 */

char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}
/**
 * _strstr - compares two strings at a given position
 * @x: string to be compared
 * @y: string to compare
 * Return: pointer to the first occurence
 */

char *_strstr(char *x, char *y)
{
	while (*x != '\0')
	{
		if ((*x == *y) && _strcmp(x, y))
			return (x);
		x++;
	}
	return (NULL);
}

