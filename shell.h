#ifndef SHELL_H
#define SHELL_H
/*-----------------------Include_Libraries-----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
/*-------------------Define variables for getline & Alias------*/
#define BUFSIZE 1024

extern char **environ;

/*-------------------------Prototypes--------------------------*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_reaad(void);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
int _atoi(char *s);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
void prompt(void);
void _print_num(int n);
/* ssize_t _getline(char **line, size_t *n, FILE *file);*/
char *_strtok(char *str, const char *dlm);
char **split(char *buff);
size_t _strlen(const char *str);
char *_strdup(const char *s);
char *_strcpy(char *des, const char *src);
char *_strcat(char *dstn, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int exe_cmd(char **argv);
char *get_path(char *cmd);
char *get_env(const char *nam);
int _env(void);
int _print_str(char *str);
int _putchar(char c);
void check_input(char **splited_input);
int _echoo(char **arg);
char *_con_cat(char *tmp, char **av, char *tok);
int _PATHstrcmp(const char *s1, const char *s2);
<<<<<<< HEAD
int _proc_fork(char **arg, char *buff, char *fpb);
=======
int _proc_fork(char **arc, char *buff, char *fpb);
>>>>>>> 8b6ba440852c758031a3f094d6d6c7eef6daedda
int _splitPATH(char *str);
char *_pathfbuff(char **arg, char *PATH, char *copy);
int checks(char **arg, char *buff, int exitstat);
/*---------Alias function--*/
int _snprint(char *str, size_t size, const char *format, ...);
char *_strncpy(char *dst, const char *src, size_t n);

#endif
