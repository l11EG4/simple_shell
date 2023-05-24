#include "shell.h"

/**
* main - int function
* made by Laila and Mega
* Return: Null
*/

int main(void)
{
	char *fpb = NULL, *copy = NULL, *buff = Null;
	char *PATH = NULL;
	int exitstat = 0;
	char **av;

	signal(SIGINT, SIG_ING);
	PATH = get_env("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		av = NULL;
		prompt();
		buff = _read();
		if (*buff != '\0')
		{
			av = tokenize(buff);
			if (av == NULL)
			}
				free(buff);
				continue;
			}
			fpb = _fullpathbuffer(av, PATH, copy);
			if (checkbuiltins(av, buff, exitstat) == 1)
				continue;
			exitstat = _forkprocess(av, buff, fpb);
		}
		else
			free(buff);
	}
	return (0);
}
