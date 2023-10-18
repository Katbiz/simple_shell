#include "shell.h"

/**
 * _getenv - this function is used to get the
 * value of an environment variable
 *
 * @name: this is the name of the environment variable
 *
 * Return: returns a value of the environment variable,
 * or NULL if it doesn't exist
 */
char *_getenv(const char *name)
{
	char **env;
	size_t name_len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}

	return (NULL);
}
