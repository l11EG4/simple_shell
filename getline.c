#include "shell.h"

/**
* bring_line - assigns the line  var for the get_line
* @lineptr: the buffer that store the input string
* @buffer: the string that has been called to the line
* @n: the size of the line
* @j: the size of the buffer
* Made by Laila and Mega
*/
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}

}
/**
* handle_spaces - handles long spaces
* @buffer: argument
* @input: argument
* by: L&Z
* Return: handle long spaces
*/
ssize_t handle_spaces(char *buffer, ssize_t input)
{
	ssize_t n;
	char t;

	while (buffer[input - 1] == ' ')
	{
		n = read(STDIN_FILENO, &t, 1);
		if (n == -1)
			return (-1);
		if (n == 0)
			break;
		if (t != ' ')
		{
			buffer[input]  = t;
			input++;
		}
	}
	return (input);
}
/**
* r_input - read the input stream
* @buffer: buffer
* @input: argument
* @stream: stream
* by: l&z
* Return: number of inputs read
*/
ssize_t r_input(char *buffer, ssize_t input, FILE *stream)
{
	int n;
	char t;

	(void) stream;
	while (t != '\n')
	{
		n = read(STDIN_FILENO, &t, 1);
		if (n == -1 || (n == 0 && input == 0))
			return (-1);
		if (n == 0 && input != 0)
			break;
		if (input >= BUFSIZE)
		{
			buffer = _realloc(buffer, input, input + 1);
			if (buffer == NULL)
				return (-1);
		}
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	return (input);
}

/**
* get_line - read the input from stream
* @lineptr: buffer that stores the input
* @n: the size of lineptr
* @stream: the stream to read from
* Made by Laia and Mega
* Return: num of bytes
*/

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t retval;
	char *buffer;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == NULL)
		return (-1);

	input = r_input(buffer, input, stream);

	if (input == -1)
	{
		free(buffer);
			return (-1);
	}

	input = handle_spaces(buffer, input);
	bring_line(lineptr, n, buffer, input);
	retval = input;
	return (retval);
}
