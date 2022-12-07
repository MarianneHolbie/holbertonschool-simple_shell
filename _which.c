#include "main.h"
#include <unistd.h>

/**
 * _which- search directory in PATH
 * @cmd: command search
 * @fullpath: full path of command it searched
 * @path_var: PATH variable
 * Return: pointer to path of the command searched
 */

char *_which(char *cmd, char *fullpath, char *path_var)
{
	unsigned int cmd_len, path_var_len, path_len;
	char *path_var_copy, *token;

	cmd_len = strlen(cmd); /* length of command */
	path_var_len = strlen(path_var); /* length of path variable */
	/* memory allocation for copy */
	path_var_copy = malloc(sizeof(char) *  path_var_len + 1);

	if (path_var_copy == NULL) /* test allocation */
	{
		exit(0);
		return (NULL);
	}
	strcpy(path_var_copy, path_var); /* copy Path var */
	token = strtok(path_var_copy, ":"); /* split Path var */
	if (token == NULL)
		token = strtok(NULL, ":");

	while (token != NULL)
	{
		path_len = strlen(token);
		fullpath = malloc(sizeof(char) * (path_len + cmd_len) + 2);
		if (fullpath == NULL)
			return (NULL);
		strcpy(fullpath, token);
		fullpath[path_len] = '/';
		strcpy(fullpath + path_len + 1, cmd);
		fullpath[path_len + cmd_len + 1] = '\0';
		/* check access to file and right of execution */
		if (access(fullpath, X_OK) != 0) /* if not executable */
		{
			free(fullpath);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else  /*end of while loop */
			break;
	}
	free(path_var_copy); /* free the copy */
	return (fullpath); /* return full path of cmd searche */
}
