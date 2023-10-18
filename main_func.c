#include "shell.h"

/**
 * main - main function runs a very simple shell (a CLI)
 *
 * @ac: the argument count
 * @av: Is NULL terminated array of arguments as str
 *
 * Return: 0 on success (shell was exited with  "exit")
 */

int main(int __attribute__ ((unused)) ac, char **av)
{
	int child_pid, status, built_stat, index = 0, exit_status = 0,
			check_getline = 0, i = 1;
	size_t len = 0;
	char *str = NULL, **ar = NULL, **a_path = NULL;

	signal(SIGINT, _signalhandler);
	while (1)
	{
		(isatty(STDIN_FILENO)) ? write(STDOUT_FILENO, "$ ", 2) : 0;
		check_getline = getline(&str, &len, stdin);

		if (check_getline == -1)
		{
			free(str), str = NULL;
			break;
		}
		ar = parseString(str, " \\\t\n");
		built_stat = builtsins(ar);
		if (built_stat != 0)
		{
			if (built_stat == -1)
			{
				if (ar[1])
					exit_status = atoi_strToint(ar[1]);
				freeSA(&str, NULL, NULL, &ar, NULL);
				exit(exit_status);
			}
			freeSA(&str, NULL, NULL, &ar, NULL);
			continue;
		}
		a_path = parse_environ_Var(find_environ_Var("PATH=", &index));
		ar[0] = checkfor_exists(a_path, ar[0], av[0], i);
		if (ar[0])
		{
			child_pid = fork();
			(child_pid != 0) ? wait(&status) : execve(ar[0], ar, environ);
		}
		freeSA(&str, &ar[0], &a_path[0], &a_path, &ar), i++;
	}
	return (0);
}
