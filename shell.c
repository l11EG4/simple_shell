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
	char *line;
	size_t n = 0;

	(void)argc;
	(void)argv;

	printf("%s", prmt);
	getline(&line, &n, stdin);
	printf("%s\n", line);

	free(line);
	return (0);
}

