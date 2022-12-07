#include "main.h"


/**
 * split_string- split getline in array of word
 * @line: string to split
 * @array: array to stock word
 **/

void split_string(char *line, char **array)
{
	char *delim = " \n\t\r", *ptr = NULL;
	int i = 0;

	if (line == NULL)
	{
		free(line);
		exit(0);
	}

	if (!strstr(line, "/"))
	{
		free(line);
		perror("No such file or directory");
		exit(0);
	}

	ptr = strtok(line, delim);
	array[0] = ptr;
	if (!*array)
		exit(0);
	i++;

	while (ptr != NULL)
	{
		ptr = strtok(NULL, delim);
		array[i] = ptr;
		i++;
	}
	/* add NULL element at end for exec function */
	array[i] = NULL;
	ptr = NULL; /* discard pointer ptr */
}

/**
 * execve_cmd- execute function associated
 * @array: string split
 *
 * Return: 0
 */
int execve_cmd(char **array)
{
	int status, retour_execv = 0;
	pid_t child_pid;

	if (array[0] == NULL)
		exit(0);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error");
		exit(1);
	}
	else if (child_pid == 0)
	{
		retour_execv = execve(array[0], array, environ);
		if (retour_execv == -1)
		{
			perror("Error");
			exit(1);
		}
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
	char *array[1024], *line = NULL;
	size_t len = 0;
	ssize_t nbrchar_read = 0;
	int i = 0;

	while (1)
	{
		nbrchar_read = getline(&line, &len, stdin);
		/* printf("$ "); */
		/* test get line function failed or not */
		if (nbrchar_read == -1)
		{
			free(line);
			line = NULL;
			exit(0);
		}
		if (feof(stdin) || !strstr(line, "/"))
		{
			free(line);
			exit(0);
		}
		split_string(line, array);
		i = execve_cmd(array);
		if (i != 0)
			exit(i);
	}
	free(line);
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
