#include "shell.h"

/**
 * freeSA - This function aims to free up to three strings and two arrays.
 *
 * @s1: is string 1
 * @s2: is string 2
 * @s3: is string 3
 * @ar1: is array 1
 * @ar2: is array 2
 *
 * Return: function always returns void
 * Note: that the function recieves the address of
 * the pointers it must free
 */

void freeSA(char **s1, char **s2, char **s3, char ***ar1, char ***ar2)
{
	if (s1)
	{
		if (*s1)
			free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		if (*s2)
			free(*s2);
		*s2 = NULL;
	}
	if (s3)
	{
		if (*s3)
			free(*s3);
		*s3 = NULL;
	}
	if (ar1)
	{
		if (*ar1)
			free(*ar1);
		*ar1 = NULL;
	}
	if (ar2)
	{
		if (*ar2)
			free(*ar2);
		*ar2 = NULL;
	}

}


/**
 * parseString - this subject functio aims to parse a str
 * into an array that execve understands.
 *
 * @s: is a string to be recieved by getline
 * @delim: is a str of delimiters
 * Return: always retuns NULL if terminated array on success
 */

char **parseString(char *s, char *delim)
{
	int i, count_delim;
	char **ar, *tmp;

	if (!s && !delim)
		return (NULL);

	for (i = 0, count_delim = 0; s[i]; i++)
	{
		if (in_che(s[i], delim) == 1 && (s[i + 1] > 32 && s[i + 1] < 127))
			count_delim++;
	}

	ar = malloc(sizeof(char *) * (count_delim + 3));
	if (!ar)
		return (NULL);
	ar[0] = strtok(s, delim);

	for (tmp = strtok(NULL, delim), i = 1; tmp; tmp = strtok(NULL, delim))
		ar[i++] = tmp;

	ar[i] = NULL;
	return (ar);
}


/**
 * in_che - This function aims to check if a char is in a str.
 *
 * @c: is char
 * @s: is the string
 *
 * Return: It should return 1 for true, 0 for false
 */

int in_che(char c, char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (c == s[i])
			return (1);
	return (0);
}

/**
 * _signalhandler - signal handler in this case is a function
 * that is used to the handle Ctrl + C.
 *
 * @sig: is signal
 *
 * Return: alaways returns void
 */
void _signalhandler(__attribute__ ((unused)) int sig)
{
	write(STDOUT_FILENO, &"\n$ ", 3);
}
