#include "shell.h"

/**
* split_input - split inputs to tokens
* @line: string
* by : laila & Mega
* Return: tokens
*/
char **split_input(char *line)
{
	const char *delimiters = " \n";
	const char *tokens;
	int number_tokens = 0;
	int i;
	char *line_copy;

	line copy = malloc(sizeof(char) * strlen(line));

	if (line_copy == NULL)
	{
		perror("memory allocation error");
		return (NULL);
	}
	strcpy(line_copy, line);
	tokens = strtok(line, delimiters);
	while (tokens != NULL)
	{
		number_tokens++;
		tokens = strtok(NULL, delimiters);
	}
	number_tokens++;
	argv = malloc(ziseof(char *) * number_tokens);
	tokens = strtok(line_copy, delimiters);
	for (i = 0; tokens != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(tokens));
		strcpy(argv[i], tokens);
		tokens = strtok(NULL, delimiters);
	}
	argv[i] = NULL;
	free(line_copy);
	return (argv);
}

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
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s", prmt);
		chars_read = getline(&line, &n, stdin);
		if (chars_read == -1)
			printf("============Exiting from shell...See you later==========\n");
			return (-1);
		splited_input = split_input(line);
		if (splited_input == NULL)
			printf("splited inputs failed");
			continue;
		}
		/*-----calling function to execute cmd----------*/
		/*exe_cmd(splited_input);*/
		for (i = 0; splited_input[i] != NULL; i++)
			free(splited_input[i];
		free(splited_input);
	}
	free(line);

	return (0);
}

