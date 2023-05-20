#include "shell.h"

/**
* _strcat - concatenates 2 strings
* @dstn: the destination of the buffer
* @src: the source of the buffer
* Made by Laila and Mega
* Retrun: the pointer to the destionation of the buffer
*/

char *_strcat(char *dstn, char *src)
{
	char *ret = dstn;

	while (*dstn)
		dstn++;
	while (*src)
		*dstn++ = *src++;
	*dstn = *src;
	return (ret);
}
