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
#include <signal.h>

/**
 * struct node - single linkes list
 * @path_directory: string
 * @next: point to the next node
 * Description: singly linked list of node structure
 */

typedef struct node
{
	char *path_directory;
	struct node *next;
} node_t;


extern char **environ;
int kill(pid_t pid, int sig);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/* free l'array */
void free_array(char **array);
/* permet de faire un malloc sur une chaien de char*/
char *strdup(const char *s);
/* modifie le cmd avec le chemin absolue*/
void _which(char **cmd);
/* recup l'env */
char *_getenv(char *name);
/* liste all directory path */
char *_directory_path(char *path);
/* create linked list of path directory */
node_t *_linkedlist_dir(char *path);
/* add new variable of environment or replace value */
int _setenv(const char *name, const char *value, int overwrite);
/* construct NAME=VALUE for environment variable */
char *build_var_env(const char *name, const char *value);
/* add or change value of environment variable */
int _setenv(const char *name, const char *value, int overwrite);

#endif
