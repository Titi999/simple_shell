#include "main.h"

#define UNUSED __attribute__((unused))

/**
 * main - main function of a program
 * @UNUSED: Macro for unused parameters
 *
 * Return: none
 */
int main(int argc UNUSED, char **argv UNUSED)
{
	char *line = NULL;	 
	char **args = NULL;
	int term;
	size_t len = 0;


	term = isatty(STDIN_FILENO);
	while (1)
	{
		if (term)
			write(STDOUT_FILENO, "> ", 2);
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			if (term)
			{		
				_print("\n");
				exit(70);
			}
			exit(0);
		}
		/*
		*line = read_line();
		*/
		args = split(line);
		execute(args);
	}
	free(args);
	return (0);
}

