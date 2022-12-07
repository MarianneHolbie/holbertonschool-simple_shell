#include "main.h"

/**
 * _getenv- return the value of the environment variable NAME
 * @name: environment variable NAME
 *
 * Return: pointer to value of name or NULL if failed
 */


char *_getenv(const char *name)
{
	int i = 0;
	char **g;
	char *value_name = NULL, *match = NULL, *path = NULL;
	unsigned int path_len;

	g = environ; /* pointer to char externe environ */

	while (g[i])
	{
		/* search line with NAME in environ */
		match = strstr(g[i], name);

		if (match)
		{
			/* split environ variable to get only part after = */
			value_name = strtok(match, "=");
			value_name = strtok(NULL, "\n");
			if (value_name == NULL)
				exit(0);
			/* calcul of len of path to allocate dynamic memory */
			path_len = strlen(value_name);
			path = malloc(sizeof(char) * path_len + 1);
			if (path == NULL)
				return (NULL);
			path = strcpy(path, value_name);

			return (path);
		}
		i++;
	}

	return (NULL);
}
