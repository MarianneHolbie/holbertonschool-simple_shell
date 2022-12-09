#include "main.h"
#include <unistd.h>

/**
 * _which- search directory in PATH
 * @cmd: command search
 * Return: pointer to path of the command searched
 */

void _which(char **cmd)
{
	char *chemin[1024], *buffer = NULL, *path_split = NULL, *token = NULL;
	int count = 0, i = 0;

	path_split = strdup(_getenv("PATH"));
	/* split env */
	token = strtok(path_split, ":");
	while (token != NULL)
	{
		chemin[count] = token;
		count++;

		token = strtok(NULL, ":");
	}
	chemin[count] = NULL;

	if (**cmd != '/' && strncmp(*cmd, "./", 2) != 0)
	{
		/* boucle sur chaque dir */
		for (i = 0; chemin[i]; i++)
		{
			buffer = malloc(sizeof(char) * (strlen(chemin[i]) + 1
						+ strlen(cmd[0]) + 1));
			if (buffer == NULL || chemin == NULL)
				break;
			/* concat */
			strcpy(buffer, chemin[i]);
			strcat(buffer, "/");
			strcat(buffer, *cmd);
			/* check si ça existe */
			if (access(buffer, F_OK) == 0)
				break;
			/* on free pour la prochaine boucle */
			free(buffer);
			buffer = NULL;
		}
		/* on met le chemin pour l'execve*/
		free(cmd[0]);
		cmd[0] = buffer;
	}
	free(path_split);
}
