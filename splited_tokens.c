#include "shell.h"

/**
* split_input - split inputs to tokens
* @line: string
* by : laila & Mega
*
* Return: tokens
*/
char **split_input(char *line)
{
	const char *delimiters = " \n";
	const char *tokens;
	int number_tokens = 0, i;
	char *line_copy;
	char **argv;

	line_copy = _strdup(line);
	/*----------Split the input string to an array-----*/
	tokens = _strtok(line_copy, delimiters);
	if (tokens == NULL)
	{
		return (NULL);
	}
	while (tokens != NULL)
	{
		number_tokens++;
		tokens = _strtok(NULL, delimiters);
	}
	number_tokens++;
	/*--Allocate space & stor each token in an array of strings(argv)--*/
	argv = malloc(sizeof(char *) * number_tokens);
	tokens = _strtok(line, delimiters);
	for (i = 0; tokens != NULL; i++)
	{
		argv[i] = _strdup(tokens);
		tokens = _strtok(NULL, delimiters);
	}
	argv[i] = NULL;
	free(line_copy);
	return (argv);
}
