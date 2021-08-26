#include "main.h"

#define UNUSED __attribute__((unused))

/**
 * main - main function of a program
 * @UNUSED: Macro for unused parameters
 * @env: environment
 *
 * Return: none
 */
int main(int argc UNUSED, char **argv UNUSED, char **env UNUSED)
{
	char *line;
	char **args;
	int term;

	term = isatty(STDIN_FILENO);
	while (1)
	{
		if (term)
			_print("> ");
		line = read_line();
		args = split(line);
		execute(args);
	}
	free(line);
	free(args);
	return (0);
}

