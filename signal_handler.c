#include "shell.h"

/**
 * handle_sigint - This is a signal handler for SIGINT (Ctrl+C)
 * @sig: this reps the signal number
 *
 * Return: returns nothing
 */
void handle_sigint(int sig)
{
	(void) sig;
	_putchar('\n');
	prompt();
}

/**
 * handle_sigquit - This function is a signal handler for SIGQUIT (Ctrl+\)
 * @sig: reps a signal number
 *
 * Return: returns nothing
 */
void handle_sigquit(int sig)
{
	(void) sig;
	_puterror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - This is the function signal handler for SIGTSTP (Ctrl+Z)
 * @sig: reps a signal number
 *
 * Return: Nothing
 */
void handle_sigstp(int sig)
{
	(void) sig;
	_puts("\n");
	prompt();
}
