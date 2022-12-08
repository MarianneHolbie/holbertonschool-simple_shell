#include "main.h"
/**
 * free_array - on libere l'array
 * @array: le tableau a liberer
 */
void free_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

/**
 * split_string- split getline in array of word
 * @line: string to split
 * Return: array of word to split getline
 */
char **split_string(char *line)
{
	char *delim = " \n\t\r\a", *token = NULL, **array = NULL;
	int i = 0;

	token = strtok(line, delim);

	array = malloc(sizeof(char *) * (strlen(token) + 1));
	if (array == NULL)
		exit(0);

	while (token != NULL)
	{
		/* je fais une alloc pour la chaine de char */
		array[i] = strdup(token);

		token = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
	return (array);

}

/**
 * execve_cmd- execute function associated
 * @cmd: string split
 * @env: the env
 * Return: 0
 */
int execve_cmd(char **cmd, char **env)
{
	int status = 0;
	pid_t child_pid = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
		{
			perror("Error");
		}
		exit(0);
	}
	else
		wait(&status);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (status);
}

/**
 * main- loop shell prompt
 * @ac: number of arg
 * @av: array of arg
 * @env: the ENV var
 * Return:0
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL, **cmd = NULL;
	int i = 0;
	size_t buffsize = 1024;

	(void)ac;
	(void)av;

	line = malloc(sizeof(char) * buffsize);
	if (line == NULL)
	{
		perror("Malloc fail");
		return (1);
	}
	while (getline(&line, &buffsize, stdin) > 0) /* loop for shell prompt */
	{
		if (strstr(line, "exit"))
			break;

		cmd = split_string(line);
		_which(cmd);
		i = execve_cmd(cmd, env);
		if (i != 0) /* si le programme enfant s'est mal fini*/
		{
			free_array(cmd);
			break;
		}
		free_array(cmd);
	}
	free(line);
	return (i);
}
