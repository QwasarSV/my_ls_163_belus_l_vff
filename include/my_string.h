#ifndef __HEADERFILE_H_
#define __HEADERFILE_H_


#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>





int my_strlen(char *str);
char* my_strcpy(char* str_dest, char* str_src);
char* my_strchr(char* str1, char ch);
char* my_strrchr(char* str1, char ch);
void my_bzero(void *generic_ptr, size_t n);
void my_reverse_string(char* str);
char* my_strstr(char* str, char* substr);
int my_strcmp(char* str1, char* str2);
//need to make specific header


#endif