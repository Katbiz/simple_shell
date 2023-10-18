#include "shell.h"

/**
 * free_error - This function is used to free alloc'd
 * pointers following system error
 *
 * @argv: It is apointer to a pointer to an array of pointers
 * @arg: This is a pointer to a pointer to an array of characters
 *
 * Return: It always returns void.
 */
void free_error(char **argv, char *arg)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * free_tokens - This funtion is used to free memory
 * allocated dynamically by tokenize()
 * @ptr: this is a pointer to allocated memory
 *
 * Return: returns void.
 */
void free_tokens(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free((ptr[i]));
	free(ptr);
}


/**
 * free_path - This function is used to Free the global
 * nvariable containing the PATH environment
 *              variable value
 *
 * Return: returns Nothing
 */
void free_path(void)
{
	if (environ != NULL)
	{
		size_t i = 0;

		while (environ[i] != NULL)
		{
			if (_strncmp(environ[i], "PATH=", 5) == 0)
			{
				free(environ[i]);
				environ[i] = NULL;
				break;
			}
			i++;
		}
	}
}
