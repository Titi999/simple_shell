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
#endif
