#include "shell.h"
/**
* _printAliases - prints aliases
* @als: array
* by: L&Z
*/
void _printAliases(Alias *als)
{
	int i, aliascmp = 0;

	for (i = 0; i < aliascmp; i++)
	{
		_print_str(als[i].name);
		_print_str("='");
		_print_str(als[i].value);
		_print_str("'\n");
	}
}

/**
* _printAlias - prints alias
* @als: array
* @name: argument
* by: L&Z
* Return: 0 at success, -1 at failure
*/
int _printAlias(Alias *als, const char *name)
{
	int i, aliascmp = 0;

	for (i = 0; i < aliascmp; i++)
	{
		if (_strncmp(als[i].name, name, MAX_ALIAS_LEN) == 0)
		{
			_print_str(als[i].name);
			_print_str("='");
			_print_str(als[i].value);
			_print_str("'\n");
			return (0);
		}
	}
	return (-1);
}

/**
* _defineAlias - define alias
* @name: argument
* @value: argument
* by: L&Z
*/
void _defineAlias(const char *name, const char *value)
{
	Alias alias;
	int i, aliascmp = 0;

	for (i = 0; i < aliascmp; i++)
	{
		if (_strncmp(als[i].name, name, MAX_ALIAS_LEN) == 0)
		{
			_strncpy(als[i].value, value, MAX_VALUE_LEN);
			return;
		}
	}
	if (aliascmp == MAX_ALIAS_CMP)
	{
		_print_str("Limit exceeded for Alias\n");
		return;
	}

	_strncpy(alias.name, name, MAX_ALIAS_LEN);
	_strncpy(alias.value, value, MAX_VALUE_LEN);
	als[aliascmp++] = alias;
}
/**
* _checkAlias - process the alias command
* @cmd: argument
* by: L&Z
*/
void _checkAlias(char *cmd)
{
	char *nm = _strtok(cmd, " \t\n=");
	char *v = _strtok(NULL, "\n");

	if (nm == NULL)
	{
		_printAliases(als); /*if no arguments, prints all the aliases*/
	}
	else if (v == NULL)
	{
		_printAlias(als, nm); /* if only name provided, prints the alias name*/
	}
	else
	{
		_defineAlias(nm, v);/*if the both are provided, defines or redefines alias*/
	}
}
