#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * struct fnUnix_s - appel les fonctions du système ou autre...
 * @nom: word to a fn
 * @fp: fn ptr
 */
typedef struct fnUnix_s
{
	char *nom;
	int (*fp)(void);
} fnUnix_t;
extern char **environ;

void free_malloc(char **token, char *path, char *line, char *fullpath, int fp_malloc);
char *_which(char *cmd, char *fullpath, char *path_var);
char *_getenv(char *name);
/* liste all directory path */
char *_directory_path(char *path);
/* add new variable of environment or replace value */
int _setenv(const char *name, const char *value, int overwrite);
/* construct NAME=VALUE for environment variable */
char *build_var_env(const char *name, const char *value);
/* add or change value of environment variable */
int _setenv(const char *name, const char *value, int overwrite);
/* implicit declaration of getline so i define it*/
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int print_full_env(void);


#endif
