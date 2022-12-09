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

/* error strings */
#define ERROR_MALLOC "Cannot allocate memory with malloc\n"
#define ERROR_FORK "Cannot fork and create child process\n"
#define ERROR_PATH "No such file or directory\n"


/**
 * struct built_s - linked list of builtins
 * @name of builtin
 * @func: pointer to function
 * Description: struct for builtin functions
 */

typedef struct builtin_s
{
	char *name;
	int (*func)(void);
} builtin_t;

/* environment variable */
extern char **environ;


/* Function free all malloc */
void free_malloc(char **token, char *line, char *fullpath, int fp_malloc);
/* function like which */
char *_which(char *cmd, char *fullpath, char *path_var);
/* function like getenv */
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
/* function print env */
void print_full_env(char **envp);

/* function for builin */
int shell_env(void);
int shell_exit(void);
int builtin_execute(char **cmd);

#endif
