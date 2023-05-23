#ifndef SHELL_H
#define SHELL_H
/*-----------------------Include_Libraries-----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
/*-------------------Define variables for getline & Alias------*/
#define BUFSIZE 1024
#define MAX_ALIAS_CMP 100
#define MAX_VALUE_LEN 100
#define MAX_ALIAS_LEN 100
extern int last_exit_stat;
extern char **environ; /*external variable for execute the cmd*/
/*-----------------------Struct Alias----------------------------*/
/**
* typedef Alias - struct for alias
* @name: alias name
* @value: alias value
*
* Description: Alias store the name and value of alias,
*		The MAX_ALIAS_LEN & MAX_VALUE_LEN constans defines the max
*		length of the name and value .
*
*/
typedef struct
{
	char name[MAX_ALIAS_LEN];
	char value[MAX_VALUE_LEN];
} Alias;

extern Alias als[MAX_ALIAS_CMP];

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
int _echoo(char **arg);
/*---------Alias function-------*/
void _printAliases(Alias *als);
int _printAlias(Alias *als, const char *name);
void _defineAlias(const char *name, const char *value);
void _checkAlias(char *cmd);
int _snprint(char *str, size_t size, const char *format, ...);
char *_strncpy(char *dst, const char *src, size_t n);

#endif
