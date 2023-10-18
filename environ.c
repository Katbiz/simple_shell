#include "shell.h"

/**
 * _puts - _puts function's main aim is to print a string
 * @fd: is the file descriptor
 * @s: is a null-byte terminated string
 *
 * Return: returns a number of chars printed on success
 */
int _puts(int fd, char *s)
{
	char *buf = NULL;
	int i;

	i = strlength(s);
	if (i == -1)
		return (-1);
	buf = malloc(i);
	for (i = 0; s[i]; i++)
		buf[i] = s[i];
	i = write(fd, buf, i);
	free(buf);
	return (i);
}

/**
 * print_environ - print_environ function is used
 * to print the env to stdout.
 * @env: NULL terminated array of strings (environ)
 *
 * Return: this function 0 on success
 */

int print_environ(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		fprintf(stdout, "%s\n", env[i]);

	return (0);
}



/**
 * atoi_strToint - this it the function that converts a number
 * as str to an int
 *
 * @s:Is a number as string
 *
 * Return: this function number as int
 */

int atoi_strToint(char *s)
{
	int i = 0, res = 0, neg = 1;

	if (!s)
		exit(98);

	if (s[0] == '-')
	{
		i = 1;
		neg = -1;
	}
	for (; i < 10 && s[i]; i++)
	{
		if (s[i] >= 48 && s[i] < 58)
			res = res * 10 + (s[i] - '0');
		else
		{
			fprintf(stdout, "Can't atoi_strToint a non-numeric char\n");
			exit(0);
		}
	}
	return (res * neg);
}
