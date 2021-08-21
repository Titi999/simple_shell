#include "main.h"
/**
 *
 *
 *
 */

int execute(char **args)
{
	if (args[0] == NULL)
	{
		/* an empty command was entered.*/
		loop();
		return 1;
	}
	{
		find_builtins(args[0]);
	}

	return (launch(args));
}

