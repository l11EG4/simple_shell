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
	pid_t pid;
	int stat;
	char *cmd;

	cmd = get_path(argv[0]);
	if (cmd == NULL)
	{
		_print_str("./Shell: Command not found\n");
		return (-1);
	}
	pid = fork();
	/*---------checks if fork failed-----------*/
	if (pid < 0)
	{
		perror("fork error");
		return (-1);
	}
	else if (pid == 0)
	{
	/*-------------child process---------------*/
		if (execve(cmd, argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
	/*--------------Parent process-----------*/
		if (waitpid(pid, &stat, 0) == -1)
		{
			perror("waitpid fail");
			return (-1);
		}
	}
	return (0);
}

