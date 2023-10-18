#include "shell.h"

/**
 * get_path - this function is used to return the value
 * of the PATH enviroment variable.
 *
 * Return: This function returns pointer to the value of $PATH.
 */
char *get_path(void)
{
	return (_getenv("PATH"));
}
