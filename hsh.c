#include "main.h"

/**
 * split_string- split getline in array of word
 * @line: string to split
 * @array: array to stock word
 * @nbrchar_read: nbr char read by function getline
 * Return: array of word to split getline
 **/


char **split_string(char *line, char **array, int nbrchar_read)
{
	char *delim = " \n\t\r", *token = NULL;
	int i = 0;

	if (line == NULL || nbrchar_read < 0)
	{
		free(line);
		exit(0);
	}

	token = strtok(line, delim);


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

		token = strtok(NULL, delim);
	}
	array[i] = NULL;
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
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (status);
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
		if (strcmp(line, "\n")) /* test if line = \n */
		{
			cmd = split_string(line, array, nbrchar_read);
			path = _getenv("PATH");

			fullpath = _which(cmd[0], fullpath, path);
			cmd[0] = fullpath;
			i = execve_cmd(cmd);
			if (i != 0) /* si le programme enfant s'est mal fini*/
			{
				free(line);
				exit(i);
			}
		}
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
