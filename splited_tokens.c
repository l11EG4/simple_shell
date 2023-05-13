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
        int number_tokens = 0;
        int i;
        char *line_copy;
	char **argv;

        /*--------Allocate space for line_copy-----------*/
        line_copy = malloc(sizeof(char) * strlen(line));

        if (line_copy == NULL)
        {
                perror("memory allocation error");
                return (NULL);
        }
        /*-------Copy line into line_copy---------------*/
        strcpy(line_copy, line);
        /*----------Split the input string to an array-----*/
        tokens = strtok(line, delimiters);
        while (tokens != NULL)
        {
                number_tokens++;
                tokens = strtok(NULL, delimiters);
        }
        number_tokens++;
        /*--Allocate space & stor each token in an array of strings(argv)--*/
        argv = malloc(sizeof(char *) * number_tokens);
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
