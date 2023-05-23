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
	const char *delimiters = " \n", *tokens;
	int number_tokens = 0, i;
	char *line_copy;
	char **argv;

	/*--------Allocate space for line_copy-----------*/
	line_copy = malloc(sizeof(char) * _strlen(line));
	if (line_copy == NULL)
	{
		perror("memory allocation error");
		return (NULL);
	}
	/*-------Copy line into line_copy---------------*/
	_strcpy(line_copy, line);
	/*----------Split the input string to an array-----*/
	tokens = _strtok(line, delimiters);
	if (tokens == NULL)
		return (0);
	while (tokens != NULL)
	{
		number_tokens++;
		tokens = _strtok(NULL, delimiters);
	}
	number_tokens++;
	/*--Allocate space & stor each token in an array of strings(argv)--*/
	argv = malloc(sizeof(char *) * number_tokens);
	tokens = _strtok(line_copy, delimiters);
	for (i = 0; tokens != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(tokens));
		_strcpy(argv[i], tokens);
		tokens = _strtok(NULL, delimiters);
	}
	argv[i] = NULL;
	free(line_copy);
	return (argv);
}
