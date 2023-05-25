#include "shell.h"

/**
* prompt - prompt
* by: l&z
* Return: integer
*/
int prompt(void)
{
	char *prmt = "$ ";
	ssize_t count = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		count = write(STDOUT_FILENO, prmt, 2);
		if (count == -1)
			exit(0);
	}
	return (0);
}
/**
* _pathfbuff - function path
* @arg: argument
* @PATH: argument
* @copy: arguemnt
* by: laila and mega
* Return: ptr
*/
char *pathfbuff(char *arg, char *PATH, char *copy)
{
	char *concat, *token, *pathfbuff = NULL;
	int pathfflag = 0, len = 0;
	int len = 0, l = 0, count = 0;
	struct stat M;
	static char temp[256];

	copy = NULL;
	copy = _strdup(PATH);
	count = _splitPATH(copy);
	token = strtok(copy, ": =");
	while (token != NULL)
	{
		concat = _con_cat(temp, arg, token);
		if (stat(concat, &M) == 0)
		{
			pathfbuff = concat;
			pathfflag = 1;
			break;
		}
		if (l < count - 2)
		{
			len = _strlen(token);
			if (token[token + 1] == ':')
			{
				if (stat(arg[0], &M) == 0)
				{
					pathfbuff = arg[0];
					pathfflag = 1;
					break;
				}
			}
		}
		l++;
		token = str(NULL, ":");
	}
	if (pathfflag == 0)
		pathfbuff = arg[0];
	free(copy);
	return (pathfbuff);
}
