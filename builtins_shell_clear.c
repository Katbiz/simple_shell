#include "shell.h"

/**
 * shell_clear - The main aim of this function is to
 * clear the terminal screen.
 *
 * @args: It is an array of arguments
 *
 * Return: returns 1 to continue executing,
 *         or 0 to exit.
*/
int shell_clear(char **args)
{
	(void)args; /* avoid "unsued parameter" warning */
	_puts("\033[2J\033[H");
	return (1);
}
