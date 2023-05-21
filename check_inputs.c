#include "shell.h"

/**
* check_input - checks the user input
* @splited_input: tockens
* by: me & him
*/
void check_input(char **splited_input)
{

	if (_strncmp(splited_input[0], "exit", 4) == 0)
	{
		if (splited_input[1] != NULL)
		{
			int status = atoi(splited_input[1]);

			_print_str("\n===Exiting from shell...Yalah noud *** chkon chdk");
			_print_num(status);
			_print_str("==\n");
			exit(status);
		}
		else
		{
			_print_str("\n==Exiting from shell.... yalah lbab al7bab==\n");
			exit(0);
		}
	}
	else if (_strncmp(splited_input[0], "env", 3) == 0)
	{
		env();/*execute the built-in env*/
	}
	else
	{
		exe_cmd(splited_input);/*execute cmd*/
	}
}


