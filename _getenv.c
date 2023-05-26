#include "shell.h"

/**
* get_env - char function
* @nam: prm
* Made by Laila and Mega
* Return: NULL
*/

char *get_env(const char *nam)
{
	int a, result;

	for (a = 0; environ[a]; a++)
	{
		result = _PATHstrcmp(nam, environ[a]);
		if (result == 0)
		{
			return (environ[a]);
		}
	}
	return (NULL);
}

/**
* _env - print the environ
* Made by Laila and Mega
* Return: zero
*/

int _env(void)
{
	int a;

	for (a = 0; environ[a] != NULL; a++)
		_puts(environ[a]);
	return (0);
}
