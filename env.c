#include "main.h"
/**
 *  * env_func - Prints eviroment variables
 *   * Return: 0 on success
 *   */
int env_func(void)
{
	int counter = 0, length = 0;
	
	while (environ[counter] != NULL)
	{
		length = strlen(environ[counter]);
		write(STDOUT_FILENO, environ[counter], length);
		write(STDOUT_FILENO, "\n", 1);
		counter++;
	}
	return (1);
}

