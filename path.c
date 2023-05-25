#include "shell.h"

/**
* _splitPATH - int function
* @str: prm
* Made by Laila and Mega
* Return: num Path
*/

int _splitPATH(char *str)
{
	int a;
	int wordcount = 0;
	int searchflag = 1;

	for (a = 0; str[a]; a++)
	{
		if (str[a] != ':' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		if (str[a + 1] == ':')
		{
			searchflag = 1;
		}
	}
	return (wordcount);
}

/**
* _PATHstrcmp - int function
* @s1: prm
* @s2: prm
* Made by Laila and Mega
* Return: zero
*/

int _PATHstrcmp(const char *s1, const char *s2)
{
	int a;

	for (a = 0; s2[a] != '='; a++)
	{
		if (s1[a] != s2[a])
			return (-1);
	}
	return (0);
}

/**
* _con_cat - charcter function
* @av: vrbl
* @tok: vrbl
* @tmp: vrbl
* Made by Laila and Mega
* Return: zero
*/

char *_con_cat(char *tmp, char **av, chat *tok)
{
	int len = 0;

	_memset(tmp, 0, 256);
	len = _strlen(tok) + _strlen(av[0]) + 2;
	_strcat(tmp, tok);
	_strcat(tmp, "/");
	_strcat(tmp, av[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}
