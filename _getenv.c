#include "main.h"

char *_getenv(const char *name)
{
	char **g, *found = NULL, *token = NULL;
	int i = 0;

	g = environ;
	while (g[i])
	{
		found = strstr(g[i], name);
		if (found)
		{
			token = strtok(found, "=");
			token = strtok(NULL, "=");
			return (token);
		}
		i++;
	}
	return (NULL);
}
