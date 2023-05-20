#include "shell.h"

/**
* _gentev - compare the 1st len characters of each environments
* Made by laila and Mega
* Return: Null
*/

char *get_env(const char *var)
{
	extern char **environ;
	char **p = environ;
	size_t len = _strlen(var);

	while (*p != NULL)
	{
		if (_strncmp(var, *p, len) == 0 && (*p)[len] == '=')
		{
			return (&((*p)[len + 1]));
		}
		p++;
	}
	return (NULL);
}
