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

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
int _atoi(char *s);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
void _print_num(int n);
/* ssize_t _getline(char **line, size_t *n, FILE *file);*/
char *_strtok(char *str, const char *dlm);
char **split_input(char *line);
size_t _strlen(const char *str);
char *_strdup(const char *s);
char *_strcpy(char *des, const char *src);
char *_strcat(char *dstn, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int exe_cmd(char **argv);
char *get_path(char *cmd);
char *get_env(const char *var);
int _print_str(char *str);
int _putchar(char c);
void check_input(char **splited_input);
void env(void);
#endif
