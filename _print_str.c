#include "shell.h"

/**
* _print_str - writes a string into the standard output
* @str: string
*
* by: lailita and Megato
* Return: number of characters printed
*/

int _print_str(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
* _print_num - function prints an number integer
* @n: integer
*
* by: by me &him
*/
void _print_num(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10 != 0)
		_print_num(n / 10);

	_putchar('0' + (n % 10));
}
