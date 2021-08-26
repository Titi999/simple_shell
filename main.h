#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
/**
 * struct builtin - struct
 * @b_cmd: pointer to string
 * @b_func: funcion returning pointer to function
 *
 */

typedef struct builtin
{
	char *b_cmd;
	int (*b_func)();
} builtin_struct;

void loop(void);
void no_nl(char *l);
char *read_line(void);
char **split(char *line);
int execute(char **args);
int (*find_builtins(char *user_input))();
int launch(char **args);
int env_func(void);
int exit_func(void);
int count(char *buffer);
char **parsing(char *buffer, int characters);

/* strings*/
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1,  char *s2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strstr(char *x, char *y);

/* path */
char *find_path();
void change_equal_sig(char *str);
char *_insert_path(char **args, char **path);
char **getenvpath();
#endif
