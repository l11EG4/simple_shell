#include "shell.h"

/**
* _gentev - compare the 1st len characters of each environments
* Made by laila and Mega
* Return: Null
*/

char *_gentev(const char *name)
{
	extern char **environ;
	char **p = environ;
	size_t len = strlen(name);

	while (*P != NULL)
	{
		if (strncmp(name, *p, len) == 0 && (*p)[len] == '=')
		{
			return (&((*p)[len + 1]));
		}
		p++
	}
	return (NULL);
}
