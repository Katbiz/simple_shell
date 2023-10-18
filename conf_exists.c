#include "shell.h"

/**
 * checkfor_exists - This function job is to check an executable exists in the
 * current dir, or in any of the directories specified in PATH
 * @filename: Is the name of file
 * @ar_path: Is the path array
 * @exec_name: Is the name of executable
 * @index: Is the number of line execution
 *
 * Return: This function returns a pathname that is
 * executable by execve, or NULL if not found
 */

char *checkfor_exists(char **ar_path, char *filename,
		char *exec_name, int index)
{
	struct stat check;
	char *res, *tmp;
	int i;

	if (!ar_path || !filename)
		return (NULL);

	for (i = 1; ar_path[i]; i++)
	{
		tmp = _stradd(ar_path[i], "/");
		res = _stradd(tmp, filename);
		free(tmp);
		if (stat(res, &check) == 0)
		{
			if (S_ISREG(check.st_mode) /*&& !access(res, X_OK)*/)
				return (res);
			fprintf(stderr, "%s: %d: %s: not found\n",
					exec_name, index, filename);
			return (NULL);
		}
		free(res);
	}

	if (stat(filename, &check) == 0)
	{
		if (S_ISREG(check.st_mode) && !access(filename, X_OK))
		{
			res = _strdble(filename);
			return (res);
		}
		fprintf(stderr, "%s: %d: %s: not found\n",
				exec_name, index, filename);

		return (NULL);
	}

	fprintf(stderr, "%s: %d: %s: not found\n",
			exec_name, index, filename);
	return (NULL);
}
