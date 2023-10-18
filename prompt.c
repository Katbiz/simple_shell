#include "shell.h"

/**
 * prompt - This function prints shell prompt to stdin stream.
 *
 * Return: returns nothing.
 */
void prompt(void)
{
	_puts(PROMPT);
	fflush(stdout);
}
