#include "main.h"
/**
 * launch - executes a program
 * @args: pointer to command strings
 *
 * Return: 1 on success
 */
int launch(char **args)
{
	pid_t pid;
	/* int status */

	pid = fork();
	if (pid == 0)
	{
		/*Child process*/
		if (execve(args[0], args, NULL) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/*Error forking*/
		perror("fork Error:");
	}
	else
	{
		/*parent process*/
		wait(NULL);
	}
	return (1);
}

