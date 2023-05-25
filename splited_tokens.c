#include "shell.h"

/**
* split - split inputs to tokens
* @buff: string
* by : laila & Mega
*
* Return: tokens
*/
char **split(char *buff)
{
	const char *delimiters = " \n";
	const char *tokens;
	int number_tokens = 0, i;
	char **argv;

	number_tokens = _split(buff);
	if (!number_tokens)
		return (NULL);
	argv = malloc((number_tokens + 1) * sizeof(char *));
	if (argv == NULL)
		exit(1);
	/*----------Split the input string to an array-----*/
	tokens = strtok(buff, delimiters);

	while (tokens != NULL)
	{
		argv[i] = _strdup(tokens);
		tokens = strtok(NULL, delimiters);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

/**
* _splites - function counter
* @str: argument
*
* by: laila and mega
* Return: integer
*/
int _splites(char *str)
{
	int srcflag = 1;
	int i, cmp = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && srcflag == 1)
		{
			cmp += 1;
			srcflag = 0;
		}
		if (str[i + 1] == ' ')
			srcflag = 1;
	}
	return (cmp);
}
