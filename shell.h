#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdint.h>
#include "strings.h"
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/**
 * struct built_s - structure to identify which function to execute for your id
 * @id: function identifier.
 * @funct: pointer to function that return a char **.
 * @vfunct: pointer to function that return nothing.
 * @ifunct: pointer to funct that returns an int.
 */
typedef struct built_s
{
	char *id;
	char **(*funct)();
	void (*vfunct)();
	int (*ifunct)();
} built_t;


/*aux functions*/
void freeSA(char **s1, char **s2, char **s3, char ***ar1, char ***ar2);
char **parseString(char *s, char *delim);
int in_che(char c, char *s);
void _signalhandler(__attribute__ ((unused)) int sig);


/*builtin.c*/
int builtsins(char **ar);
void cd_funcxn(void);
char **unset_environ(char *v_name);
char **set_environ(char *v_name, char *v_value);

/*check_exists.c*/
char *checkfor_exists(char **ar_path, char *filename, char *exec_name, int index);

/*env.c*/
int _puts(int fd, char *s);
int print_environ(char **env);
int atoi_strToint(char *s);


/*get_path.c*/
char **parse_environ_Var(char *var);
int find_char_1(char *string, char searched_char);
char *find_environ_Var(char *searched_var, int *index);

/*simple_shell.c*/
int main(int __attribute__ ((unused)) ac, char **av);

/*strings.c*/
int strlength(char *str);
int strcm(char *str1, char *str2);
int _strnocmp(char *s1, char *s2, unsigned int n);
char *_strdble(char *str);
char *_stradd(char *s1, char *s2);
char *ltrim(char *s);
int _puts(int fd, char *s);

#endif
