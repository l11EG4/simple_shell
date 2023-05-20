#ifndef SHELL_H
#define SHELL_H
/*-----------------------Include_Libraries-----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>


extern char **environ;
/*-------------------------Prototypes--------------------------*/

ssize_t getline(char **line, size_t *n, FILE *file);
char *strtok(char *str, const char *delimiters);
char **split_input(char *line);
size_t _strlen(const char *str);
char *_strcpy(char *des, const char *src);
char *_strcat(char *dstn, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int exe_cmd(char **argv);
char *get_path(char *cmd);
char *get_env(const char *var);
int _print_str(char *str);
int _putchar(char c);
#endif
