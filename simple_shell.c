#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * split_string- split getline in array of word
 * @line: string to split
 * @array: array to stock word
 * @nbrchar_read: nbr char read by function getline
 **/



char **split_string(char *line, char **array, int nbrchar_read)
{
	char *delim = " \n", *token = NULL;
	int i = 0;

	if (line == NULL || nbrchar_read < 0)
	{
		free(line);
		exit(0);
	}

	for (i = 0; token != NULL; i++)
	{
		array[i] = malloc(sizeof(char *) * (strlen(token) + 2));
		if (array[i] == NULL)
		{
			free(line);
			(line = NULL);
			exit(0);
		}
		array[i] = token;
		printf("array[%d] = %s\n", i, array[i]);

		token = strtok(NULL, delim);
	}
	array[i] = NULL;
	printf("array[0] = %s\n", array[0]);
	line_copy = NULL;
	return (array);

}

/**
 * execve_cmd- execute function associated
 * @array: string split
 *
 * Return: 0
 */
int execve_cmd(char **array)
{
	char *cmd = NULL;
	int status;
	pid_t child_pid;

	if (array[0] == NULL)
		exit(0);

	if (array)
		cmd = array[0];

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd, array, environ) == -1)
			perror("Error");
	}
	else
		wait(&status);

	return (0);
}

/**
 * loop_getline- loop function getline
 *
 * Return: 0
 */


int loop_getline(void)
{
	char *array[1024], *line = NULL, *fullpath = NULL, *path = NULL, **cmd = NULL;
	size_t len = 0;
	ssize_t nbrchar_read;
	int i = 0;

	while (1) /* loop for shell prompt */
	{
		nbrchar_read = getline(&line, &len, stdin);
		printf("Nbr char read:%ld\n", nbrchar_read);

		if (nbrchar_read == -1)
		{
			free(line);
			line = NULL;
			return (-1);
		}

		if (feof(stdin))
		{
			free(line);
			printf("\n");
			exit(0);
		}

		cmd = split_string(line, array, nbrchar_read);

		printf("array[%d] = %s\n", i, cmd[i]);
		path = getenv("PATH");
		/*path = _getenv("PATH");*/
		/*if (path == NULL)
			exit(0);*/
		printf("PATH =%s\n", path);
		printf("cmd[0]=%s\n", cmd[0]);

		fullpath = _which(cmd[0], fullpath, path);
		printf("fullpath =%s\n", fullpath);

		cmd[0] = fullpath;
		printf("cmd[0] =%s\n", cmd[0]);

		execve_cmd(cmd);


		 line = NULL;
		 nbrchar_read = 0;

	}

	return (0);
}

/**
 * main- loop shell prompt
 *
 * Return:0
 */

int main(void)
{
	loop_getline();

	return (0);
}

