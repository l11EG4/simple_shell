#include "shell.h"

/**
 * split_input - tokenizes a string
 * @buf: buffer to store the input
 * Return: pointer to an array of strings
 */

char **split_input(char *buf)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
	{
		perror("Error");
		return (NULL);
	}
	token = strtok(buf, " \t\n");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
