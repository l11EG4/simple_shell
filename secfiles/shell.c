#include "shell.h"

/**
* main - int function
* made by Laila and Mega
* Return: Null
*/

int main(void)
{
	char *fpb = NULL, *copy = NULL, *buff = NULL;
	char *PATH = NULL;
	int exitstat = 0;
	char **arg;

	signal(SIGINT, SIG_IGN);
	PATH = get_env("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		arg = NULL;
		prompt();
		buff = _reaad();
		if (buff == NULL)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			break;
		}
		if (*buff != '\0')
		{
			arg = split(buff);
			if (arg == NULL)
			{
				free(buff);
				continue;
			}
			fpb = _pathfbuff(arg, PATH, copy);
			if (checks(arg, buff, exitstat) == 1)
				continue;
			exitstat = _proc_fork(arg, buff, fpb);
		}
		else
			free(buff);
	}
	free(PATH);
	return (0);
}
