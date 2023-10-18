#include "shell.h"

/**
 * strlength - the strlength function calculates
 * the length of a string
 *
 * @str: string
 *
 * Return: returns the length of string.
 * if str == NULL, returns 0
 */

int strlength(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
		continue;
	return (i);
}

/**
 * strcm - The strcm function aims to compares two strings
 * @str1: is first string
 * @str2: is second string
 *
 * Return: will return 0 if equal, < 0 if str1 is less
 * than str2 and > 0 otherwise.
 */

int strcm(char *str1, char *str2)
{
	int i;

	if (!str1)
		return (strcm("", str2));
	if (!str2)
		return (strcm(str1, ""));

	for (i = 0; str1[i] && str2[i]; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (str1[i] - str2[i]);
}


/**
 * _strnocmp - The _strnocmp function is used compare
 * the first n chars of two strings.
 * @s1: is string 1
 * @s2: is string 2
 * @n: compare at most n chars
 *
 * Return: will return 0 if first n chars are equal, <0 if s1 is less than s2,
 * and >0 otherwise
 */

int _strnocmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;

	if (!s1)
		return (_strnocmp("", s2, n));
	if (!s2)
		return (_strnocmp(s1, "", n));

	for (i = 0; i < n && s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);

	return (s1[i] - s2[i]);
}

/**
 * _strdble - _strdble finction copy a string into another place in memory
 * @str: Is a string to copy
 *
 * Return: It is pointer to new string, or NULL if malloc fails
 */

char *_strdble(char *str)
{
	int i = 0;
	char *new = NULL;

	if (!str)
		return (NULL);

	for (i = 0; str[i]; i++)
		continue;

	new = malloc(i + 1);
	if (!new)
		return (NULL);

	new[i] = '\0';
	for (i = 0; str[i]; i++)
		new[i] = str[i];

	return (new);
}


/**
 * _stradd - _stradd function is used to concatenate two strings
 * and store the result in a new string.
 *
 * @s1: Is a first string
 * @s2: Is a second string
 *
 * Return: Always a returns a pointer to new
 * string, or NULL if malloc failed
 */

char *_stradd(char *s1, char *s2)
{
	int i = 0, j = 0;
	char *new = NULL;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = strlength(s1);
	j = strlength(s2);

	new = malloc(i + j + 1);
	if (!new)
		return (NULL);
	for (i = 0; s1[i]; i++)
		new[i] = s1[i];

	for (j = 0; s2[j]; j++)
		new[i + j] = s2[j];

	new[i + j] = '\0';
	return (new);
}
