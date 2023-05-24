#include "shell.h"

/**
 * get_path - Get the full path of a command
 * @cmd: Command name
 *
 * Return: Full path of the command
 */
char *get_path(char *cmd)
{
    char *path = "/bin/";
    char *full_path = malloc(_strlen(path) + _strlen(cmd) + 1);
    _strcpy(full_path, path);
    _strcat(full_path, cmd);
    return (full_path);
}
