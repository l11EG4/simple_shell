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

	count = get_line(&buff, &n, stdin);
	if (count == -1)
	{
		free(buff);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buff[count - 1] == '\n' || buff[count - 1] == '\t')
		buff[count - 1] = '\0';
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

/**
* checks - function
*@arg: argument
*@buff: arguemnt
*@exitstat:argument
* by: me and him
*Return: integer
*/
int checks(char **arg, char *buff, int exitstat)
{
	int n;

	if (_strncmp(arg[0], "env", 3) == 0)
	{
		if (arg[1] != NULL && _strncmp(arg[1], "-n", 2) == 0)
		{
			if (arg[2] != NULL)
				exec_one_var(arg[2]);
			else
				exec_no_var();
		}
		else
			_env();

		for (n = 0; arg[n]; n++)
			free(arg[n]);
		free(arg);
		free(buff);
		return (1);
	}
	else if (_strncmp(arg[0], "exit", 4) == 0)
	{
		if (arg[1] != NULL)
			exitstat = atoi(arg[1]);
		for (n = 0; arg[n]; n++)
			free(arg[n]);
		free(arg);
		free(buff);
		exit(exitstat);
	}
	else if (_strncmp(arg[0], "echo", 4) == 0)
	{
		_echoo(arg);
		for (n = 0; arg[n]; n++)
			free(arg[n]);
		free(arg);
		free(buff);
		return (1);
	}
	else
		return (0);
}
/**
* exec_no_var - env without var
*by: lailaOmega
*/
void exec_no_var(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		environ[i] = NULL;
	_env();
}
/**
* exec_one_var -with one var
* @var: arg
* by: l&Z
*/
void exec_one_var(const char *var)
{
	int i;
	char *var_c, *name, *value, *envv;

	for (i = 0; environ[i] != NULL; i++)
		environ[i] = NULL;
	var_c = _strdup(var);
	name = _strtok(var_c, "=");
	value = _strtok(var_c, "=");
	if (name != NULL && value != NULL)
	{
		envv =  malloc(_strlen(name) + _strlen(value) + 2);
		_print_str(envv);
		_print_str("=");
		_print_str(name);
		_print_str(value);
		environ[0] = envv;
	}
	_env();
	free(var_c);
}
