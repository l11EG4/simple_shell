#include "shell.h"

/**
* _prompt - display prompt
* by: L&Z
*/
void _prompt(void)
{
	_print_str("$ ");
	fflush(stdout);
}

/**
* exe_cmd - execute the command entered
* @argv: tokens splited
* by: laila & mega
*
* Return: 0 at success, -1 if it failed
*/
int exe_cmd(char **argv)
{
	char *command = NULL;
	pid_t child_pid = 0;
	int status = 0;

	command = get_path(argv[0]);
	if (command == NULL)
		return (1);
	if (!access(command, X_OK))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(command, argv, environ) == -1)
			{
				perror(argv[0]);
				free(command);
				exit(1);
			}
		}
		else
			wait(&status);
	}
	return (status);
}
