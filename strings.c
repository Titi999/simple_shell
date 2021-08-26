#include "main.h"

/**
 * _strlen - gives length of a string
 * @s: string
 * Return: returns length of string
 */
int _strlen(char *s)
{
	int l = 0;

	while (s[l] != '\0')
		l++;

	return (l);
}


/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: comparison of two strings
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}


/**
 * _strncmp - Compares two strings with n size
 * @s1: Given String 1
 * @s2: Given String 2
 * @n: Size to character compare
 * Return: 0 both strings are equals
 */
int _strncmp(char *s1,  char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
}


/**
 * _strcpy - copies string to another string
 * @dest: string 1
 * @src: string 2
 * Return: string copy
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; a <= _strlen(src); a++)
		dest[a] = src[a];
	return (dest);
}


/**
 * _strdup - function that returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string given as a parameter
 * @str: - Char string to be copied
 * Return: Char pointer to the duplicated string. Return NULL if insufficient
 * memory was available to array or if array is NULL
 */
char *_strdup(char *str)
{
	char *dup;
	int i, l;

	if (str == NULL)
		return (NULL);
	l = 0;
	for (i = 0; str[i] != '\0'; i++)
		l++;
	dup = malloc(sizeof(char) * l + 1);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < l ; i++)
		dup[i] = str[i];
	dup[l] = '\0';
	return (dup);
}

