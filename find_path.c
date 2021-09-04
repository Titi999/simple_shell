#include "main.h"

/**
 * find_path - finds the PATH variable in environ
 * Return: pointer position of the PATH variable
 */

char *find_path()
{
	char *path = NULL;
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], "PATH", 4) == 0)
		{
			path = malloc(sizeof(char *) * (_strlen(environ[i])));

			if (path == NULL)
			{
				free(path);
				exit(-1);
			}
			_strcpy(path, environ[i]);
			break;
		}
	}
	return (path);
}

/**
 * change_equal_sig - Change from a given strings = to : character
 * @str: given string
 * Return: Nothing
 */

void change_equal_sig(char *str)
{
	char **ptr_str = NULL;
	int i = 0;

	ptr_str = &str;
	while ((*(*ptr_str + i)) != '=')
	{
		(*(*ptr_str + i)) = ':';
		i++;
	}
	(*(*ptr_str + i)) = ':';
}

/**
 * _insert_path - Inserts the directory into given command
 * @args: given command
 * @path: tokenized path enviroment
 * Return: Full path command if exists or just a given command
 */

char *_insert_path(char **args, char **path)
{
	char *cwd = getcwd(NULL, 0);
	struct stat verify;
	int counter = 0, count_char = 0;
	char *tmp2 = NULL, *dirpath = NULL;

	if (_strstr(args[0], "/") || _strstr(args[0], "."))
	{
		free(cwd), cwd = NULL;
		tmp2 = malloc(sizeof(char *) * (_strlen(args[0])));
		_strcpy(tmp2, args[0]);
		return (tmp2);
	}
	else
	{
		while (path[counter] != NULL)
		{
			chdir(path[counter]);
			if (stat(args[0], &verify) == 0)
			{
				count_char = _strlen(path[counter]) + 1 + _strlen(args[0]);
				tmp2 = malloc(sizeof(char *) * count_char);
				_strcpy(tmp2, path[counter]);
				_strcat(tmp2, "/"), _strcat(tmp2, args[0]);
				break;
			}
			counter++;
		}
	}
	chdir(cwd);
	if (tmp2 == NULL)
	{
		free(cwd), cwd = NULL;
		free(tmp2), tmp2 = NULL;

		return (dirpath);
	}
	free(cwd), cwd = NULL;
	return (tmp2);
}

/**
 * getenvpath - Creates an array of pointers to the PATH directories
 * Return: Pointer to an array of tokenized directories
 */

char **getenvpath()
{
	char *tmp = NULL;
	int size_args = 0;
	char *delim = " :'\n''\t'";
	char **env_args = NULL;

	tmp = find_path();
	change_equal_sig(tmp); /*Change  PATH= for PATH:*/
	size_args = count(tmp);
	env_args = parsing(tmp, size_args, delim);
	if (env_args ==  NULL)
	{
		_free(2, env_args);
		env_args = NULL;
	}
	free(tmp);
	return (env_args);
}

/**
 * spaces_buster - Creates an array of pointers to the PATH directories
 * @buffer: given string
 * Return: Pointer to an array of tokenized directories
 */

int spaces_buster(char *buffer)
{
	int i = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] != 32)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

