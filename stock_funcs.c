#include "shell.h"

void de_exit_(char *, char *);
void cd_funcxn(void);

/**
 * builtsins - The builtsins function aims to define which
 * built in should be executed
 *
 * @ar: is array of commands
 *
 * Return:It will return -1 if exit built-in should be executed, 1 if
 * built-in function returns void. Else 0.
 */
int builtsins(char **ar)
{
	int i, cnt_ar;
	built_t a_built[] = {
		{"exit", NULL, NULL, NULL},
		{"setenv", set_environ, NULL, NULL},
		{"unsetenv", unset_environ, NULL, NULL},
		{"env", NULL, NULL, print_environ},
		{"cd", NULL, cd_funcxn, NULL},
		{NULL, NULL, NULL, NULL}
	};

	for (cnt_ar = 0; ar[cnt_ar]; cnt_ar++)
		continue;

	for (i = 0; a_built[i].id; i++)
	{
		if (strcm(a_built[i].id, ar[0]) == 0)
		{
			/* this case is for exit built-in */
			if (!(a_built[i].funct) && !(a_built[i].vfunct) && !(a_built[i].ifunct))
				return (-1);
			/* this case are for functions that return nothing */
			else if (a_built[i].vfunct)
			{
				a_built[i].vfunct();
				return (1);
			}
			switch (a_built[i].id[0] + a_built[i].id[1])
			{
				case 216: /* this case is for setenv built-in */
					if (cnt_ar >= 2)
						a_built[i].funct(ar[1], ar[2]);
					break;
				case 227: /* this case is for unsetenv built-in */
					if (cnt_ar >= 2)
						a_built[i].funct(ar[1], ar[2]);
					break;
				case 211: /* this case is for env built-in */
					a_built[i].ifunct(environ);
					break;
			}
			return (1);
		}
	}
	return (0);
}


/**
 * cd_funcxn - This function's job is to write
 * cd_funcxn to stdout
 *
 * Return: It returns void always
 */

void cd_funcxn(void)
{
	write(STDOUT_FILENO, &"cd_funcxn\n", 7);
}


/**
 * unset_environ - unset_environ function aims to remove
 *a variable from the environment
 *
 * @v_name: Is a variable to be removed
 *
 * Return: It returns a pointer to new array (environ)
 */

char **unset_environ(char *v_name)
{
	fprintf(stdout, "unset: %s\n", v_name);
	return (NULL);
}


/**
 * set_environ - set_environ function's job is to add
 * (or modify) a variable in the environment.
 *
 * @v_name: Is name (key)
 * @v_value: Is value
 *
 * Return: This function returns pointer to variable
 */

char **set_environ(char *v_name, char *v_value)
{
	/*int a_len, index = 0;*/
	/*char **a_env = NULL;*/

	write(STDOUT_FILENO, v_name, strlength(v_name));
	write(STDOUT_FILENO, &"=", 1);
	write(STDOUT_FILENO, v_value, strlength(v_value));
	write(STDOUT_FILENO, &"\n", 1);
	return (NULL);
}
