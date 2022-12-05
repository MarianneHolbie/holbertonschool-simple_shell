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
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error");
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (execve(array[0], array, environ) == -1)
		{
			perror("Error");
			exit(1);
		}
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
	char *array[1024], *line = NULL;
	size_t len = 0;
	ssize_t nbrchar_read = 0;

	while (1)
	{
		nbrchar_read = getline(&line, &len, stdin);
		/* printf("$ "); */
		/* test get line function failed or not */
		if (nbrchar_read == -1)
		{
			free(line);
			exit(0);
		}
		if (feof(stdin))
		{
			free(line);
			exit(0);
		}
		split_string(line, array);

		execve_cmd(array);
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
