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
	char *prmt = "Laila&llEG4$ ";
	char *line = NULL;
	size_t n = 0;
	ssize_t chars_read;
	char **splited_input;
	int i;
	(void)argc;
	(void)argv;

	/*------create an infinite loop for the shel prompt-----*/
	while (1)
	{
		_print_str(prmt);
		chars_read = getline(&line, &n, stdin);
		/*-----Checks if the getline failed or we use the CTRL + D------*/
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
		/*-----calling function to execute cmd----------*/
		exe_cmd(splited_input);

		/*--------Free the allocated memory for eash splited input-----*/
		for (i = 0; splited_input[i] != NULL; i++)
		{
			free(splited_input[i]);
		}
		free(splited_input);
	}
	free(line);

	return (0);
}

