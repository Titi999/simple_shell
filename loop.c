#include "main.h"

void loop(void)
{
	char *line;
	char **args;
	int status;

	do
	{
		printf("> ");
		line = read_line();
		args = split(line);
		status = execute(args);
		
		free(line);
		free(args);
	}
	while (status);
}
