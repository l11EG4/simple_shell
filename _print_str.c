#include "shell.h"

/**
* _print_str - rites a string into the standard output
* @str: string
*
* by: lailalita and Megato
* Return: number of characters printed
*/

int _print_str(char *str)
{
	int i = 0;
	if (str == NULL)
	{
		writes(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
