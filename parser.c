#include "shell.h"

/**
 * tokenize - This function is for parsing user input into arguments
 *            by splits an array string into tokens using a delimiter.
 *
 * @str: It is the string to be tokenized.
 * @delim: It is the delimiter used to split the string.
 *
 * Return: It is an array of pointers to the tokens,
 *         or NULL if an error occurs.
 */
char **tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **ret = NULL;
	int i = 0;

	token = strtok(str, delim);
	while (token)
	{
		ret = realloc(ret, sizeof(char *) * (i + 1));
		if (ret == NULL)
			return (NULL);

		ret[i] = malloc(_strlen(token) + 1);
		if (!(ret[i]))
			return (NULL);

		_strcpy(ret[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	/*increase the size of the array*/
	ret = realloc(ret, (i + 1) * sizeof(char *));
	if (!ret)
		return (NULL);

	ret[i] = NULL;
	return (ret);
}

/**
 * tokenize_input - This finction is for spliting user
 * input string into tokens with tokenize().
 *
 * @input: It is the user input string to be tokenized
 *
 * Return: It returns an array of pointers to the
 * tokens, or NULL if an error occurs
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *tmp = NULL;

	tmp = _strdup(input);
	if (tmp == NULL)
	{
		_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenize(tmp, " \t\r\n\a");
	free(tmp);

	return (tokens);
}
