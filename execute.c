#include "main.h"
/**
 *
 *
 *
 */

int execute(char **args)
{
	int i;
	int size = 0;
	builtin_struct my_builtins[] = {
		{"exit", exit_func},
		{"env", env_func}
	};

	if (args[0] == NULL)
	{
		/* an empty command was entered.*/
		loop();
		return 1;
	}
	else
	{
		size = (sizeof(my_builtins) / sizeof(builtin_struct));

		for (i = 0; i < size; i++)
		{
			if (strcmp(args[0], my_builtins[i].b_cmd) == 0)
			{
				return (my_builtins[i].b_func(args[0]));
			}
		}
	}

	return (launch(args));
}

