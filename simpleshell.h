#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
int _putchar(char c);

#endif
