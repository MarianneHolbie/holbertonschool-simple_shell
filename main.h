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

/*
 * struct Node- single linkes list
 * @str: string
 * @next: point to the next node
 * Descroption: singly linked list of node structure
 */

typedef struct node
{
        char *path_directory;
        struct node *next;
} node_t;


extern char **environ;

char *_which(char *cmd, char *fullpath, char *path_var);
char *_getenv(const char *name);
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
