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
char *_pathfbuff(char *arg, char *PATH, char *copy)
{
	char *concat, *token, *path = NULL;
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
			path = concat;
			pathfflag = 1;
			break;
		}
		if (l < count - 2)
		{
			len = _strlen(token);
			if (token[len + 1] == ':')
			{
				if (stat(arg[0], &M) == 0)
				{
					path = arg[0];
					pathfflag = 1;
					break;
				}
			}
		}
		l++;
		token = str(NULL, ":");
	}
	if (pathfflag == 0)
		path = arg[0];
	free(copy);
	return (path);
}

/**
* _proc_fork - int function
* @arc: parametre
* @buff: parametre
* @fpb: parametre
* Made by Laila and Mega
* Return: zero
*/

int _proc_fork(char **arc, char *buff, char *fpb)
{
	int a, stat, result, exitstat = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		result = execve(fpb, arc, environ);
		if (result == -1)
		{
			perror(arc[0]);
			for (a = 0; arc[a]; a++)
				free(arc[a]);
			free(arc);
			free(buff);
			exit(127);
		}
	}
	wait(&stat);
	if (WIFEXITED(stat))
	{
		exitstat = WEXITSTATUS(stat);
	}
	for (a = 0; arc[a]; a++)
		free(arc[a]);
	free(arc);
	free(buff);
	return (exitstat);
}
