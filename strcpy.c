#include "shell.h"

/**
* _strcpy - copies the content of the source string to destination string
* @dest: destination argument
* @src: source arg
*
* by: laila and mega
* Return: copy of string
*/
char *_strcpy(char *dest, const char *src)
{
	char *tmp = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';

	return (tmp);
}
