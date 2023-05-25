#include "shell.h"
/**
* _reaad - function reader
*
* by: l&z
* Return: ptr
*/
char *_reaad(void)
{
	int i = 0;
	ssize_t count = 0;
	size_t n = 0;
	char *buff = NULL;

	count = getline(&buff, &n, stdin);
	if (count == -1)
	{
		free(buff);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buff[count - 1] == '\n' || buff[count - 1] == '\t')
		buff[count - 1] = '\n';
	for (i = 0; buff[i]; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ')
		{
			buff[i] = '\0';
			break;
		}
	}
	return (buff);
}
