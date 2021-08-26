#include "main.h"
/**
 * execute - executes a program
 * @args: command tokkens pointer
 * Return: 0 or 1
 */

int execute(char **args)
{
	int i;
	int size = 0;
	char **paths = NULL;
	char *fullcommand = NULL;
	builtin_struct my_builtins[] = {
		{"exit", exit_func},
		{"env", env_func}
	};

	if (args[0] == NULL)
	{
		/* an empty command was entered.*/
		return (1);
	}

	size = (sizeof(my_builtins) / sizeof(builtin_struct));
	for (i = 0; i < size; i++)
	{
		if (strcmp(args[0], my_builtins[i].b_cmd) == 0)
		{
			return (my_builtins[i].b_func(args[0]));
		}
	}
	paths = getenvpath();
	fullcommand = _insert_path(args, paths);
	args[0] = fullcommand;
	return (launch(args));
}

