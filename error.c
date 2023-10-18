#include "shell.h"

/**
 * _puts - This function prints a string to
 * the standard output stream
 *
 * @str: It is the string to print
 *
 * Return: It returns void
 */
void _puts(char *str)
{
	size_t len;
	ssize_t num_written;

	len = _strlen(str);
	num_written = write(STDOUT_FILENO, str, len);
	if (num_written == -1)
	{
		perror("write");
	}
}

/**
 * _puterror - This prints out an error message
 * to the standard error stream
 *
 * @err: It is the error message to print
 *
 * Return: returns nothing
 */
void _puterror(char *err)
{
	size_t len;
	ssize_t num_written;

	len = _strlen(err);
	num_written = write(STDERR_FILENO, err, len);
	if (num_written == -1)
	{
		perror("write");
	}
}
