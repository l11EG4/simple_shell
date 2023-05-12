#ifndef SHELL_H
#define SHELL_H
/*-----------------------Include_Libraries-----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
/*-------------------------Prototypes--------------------------*/

ssize_t getline(char **line, size_t *n, FILE *file);
char *strtok(char *str, const char *delimiters);
/*void exe_cmd(char **argv);*/


#endif
