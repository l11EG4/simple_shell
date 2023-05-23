#include "shell.h"

/**
* _echoo - handle variables replacement
* @arg:
*
* by: L&Z
* Return: integer
*/
int _echoo(char **arg)
{
	int pid;
	char *va_name, *va_value;

	if (arg[2])
		write(2, "too many arguments\n", 18);
	else
	{
		if (_strncmp("$$", arg[1], _strlen(arg[1])) == 0)
		{
			pid = getpid();
			_print_num(pid);
			_print_str("\n");
		}
		else if (_strncmp("$?", arg[1], _strlen(arg[1])) == 0)
		{
			_print_num(last_exit_stat);
			_print_str("\n");
		}
		else if (arg[1][0] == '$')
		{
			va_name = arg[1] + 1;/*to skip $ */
			va_value = get_env(va_name);
			if (va_value != NULL)
			{
				_print_str(va_value);
				_print_str("\n");
			}
			else
				_print_str("\n");
		}
		else
		{
			_print_str(arg[1]);
			_print_str("\n");
		}

	}
	return (0);
}
