#include "shell.h"

/**
* _strlen - length of string
* @str: argument
* by: laila and mega
*
* Return: length
*/

size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
		len++;

	return (len);
}
