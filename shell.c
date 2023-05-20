#include "shell.h"

/**
* main - main_function
* @argc: argument
* @argv: argument
* by: Laila&Mega
*
* Return: always 0 , 1 if it fails
*/
int main(int argc, char **argv)
{
	char *prmt = "Laila&llEG4$ ", *line = NULL;
	size_t n = 0;
	ssize_t chars_read;
	char **splited_input;
	(void) argc;
	(void) argv;

	/*------create an infinite loop for the shel prompt-----*/
	while (1)
	{
		_print_str(prmt);
		chars_read = getline(&line, &n, stdin);
		if (chars_read == -1)
		{
			_print_str("\n============Exiting from shell...See you later==========\n");
			return (-1);
		}
		splited_input = split_input(line);
		if (splited_input == NULL)
		{
			_print_str("splited inputs failed\n");
			continue;
		}
		if (_strncmp(splited_input[0], "exit", 4) == 0)
		{
			_print_str("\n==Exiting from shell...yalah noud t*** chkon chdk==\n");
			break;
		}
		else if (_strncmp(splited_input[0], "env", 3 == 0))
			env();
		else
			exe_cmd(splited_input);/*execute cmd*/
		/*--------Free the allocated memory for eash splited input-----*/
		for (int i = 0; splited_input[i] != NULL; i++)
			free(splited_input[i]);
		free(splited_input);
	}
	free(line);

	return (0);
}

/**
* env - execute the command env built-in
* by: laila & mega
* Return: void
*/
void env(void)
{
	char **envi = environ;

	while (*envi)
	{
		_print_str(*envi);
		_print_str("\n");
		envi++;
	}
}
