#include "shell.h"

/**
 * parse_environ_Var - this function is used to create an
 * array of tokens for an env variable
 *
 * @var: is a string from the environ array
 *
 * Return: returns NULL terminated array of strings 
 * (or NULL if malloc failed)
 */

char **parse_environ_Var(char *var)
{
        char *str, *tmp, **ar;
        int i, count_delim;

        str = _strdble(var);
        if (!str)
                return (NULL);

        for (i = 0, count_delim = 0; str[i]; i++)
                if (str[i] == ':')
                        count_delim++;

        ar = malloc(sizeof(char *) * (count_delim + 3));
        tmp = strtok(str, ":=");
        i = 0;
        ar[i++] = tmp;
        for (tmp = strtok(NULL, ":"); tmp; tmp = strtok(NULL, ":"))
                ar[i++] = tmp;
        ar[i] = NULL;

        return (ar);
}

/**
 * find_char_1 - the find_char_1 find the first occurrance
 * of a char in a str.
 *
 * @string:Is a string
 * @searched_char: is the char to search
 *
 * Return: index of char, or -1 if not found
 */

int find_char_1(char *string, char searched_char)
{
        int i;

        for (i = 0; string[i]; i++)
        {
                if (string[i] == searched_char)
                        return (i);
        }
        return (-1);
}


/**
 * find_environ_Var - The find_environ_Var find
 * a variable in environ.
 *
 * @searched_var: is searched variable ('key', if the string is
 * 'key=value')
 * @index: is pointer to int that whill be changed to the
 * index in the array where the variable lies
 *
 * Return: returns the found string
 */

char *find_environ_Var(char *searched_var, int *index)
{
        int i, j;

        for (i = 0; environ[i]; i++)
        {
                j = find_char_1(environ[i], '=');
                if (j < 0)
                        return (NULL);

                if (_strnocmp(environ[i], searched_var, (unsigned int) j) == 0)
                {
                        *index = i;
                        return (environ[i]);
                                        }
        }

        return (NULL);
}
