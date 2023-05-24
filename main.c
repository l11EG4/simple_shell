#include "shell.h"
/**
 * C_andler - handles the SIGINT signal
 * @sig_num: signal number
 * Return: void
 */

void C_handler(int sig_num)
{
	(void)sig_num;
	signal(SIGINT, C_handler);
	fflush(stdout);
}
void C_handler(int sig_num);
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
	char *line = NULL;
	char **splited_input;
	ssize_t chars_read;
	size_t n = 0;

	(void)argc;
	(void)argv;

	signal(SIGINT, C_handler);
	while (1)
	{
		_prompt();
		chars_read = getline(&line, &n, stdin);
		if (chars_read == -1)
		{
			if(isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		splited_input = split_input(line);
		if (splited_input == NULL)
		{
			continue;
		}
		check_input(splited_input);
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
