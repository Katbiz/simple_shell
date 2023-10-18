#include "shell.h"

/**
 * shell_env - This fumction is used to print all the environment variables.
 *
 * Return: returns void.
 */
int shell_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}

	return (0);
}
