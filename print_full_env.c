#include "main.h"

/**
 * print_full_env- function that print all environment variable
 *
 */

void print_full_env()
{
	int i = 0;
	char **g;

	g = environ;
	
	for (i = 0; g[i] != NULL; i++)
		printf("%s\n", g[i]);
}
