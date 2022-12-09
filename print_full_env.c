#include "main.h"

/**
 * print_full_env- function that print all environment variable
 *
 * Return: 0 if no error
 */

int print_full_env(void)
{
	int i = 0;
	char **g;

	g = environ;

	for (i = 0; g[i] != NULL; i++)
		printf("%s\n", g[i]);

	return (0);
}
