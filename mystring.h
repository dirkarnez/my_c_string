#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _string_
{
     char *c;
     int size;
} stringv, *string;

string str_create();
void str_addinput(string);
void str_print(string);
void str_input(string);
void str_destroy(string);
void str_toupper(string);
void str_tolower(string);
void str_totitle(string);
void str_trim(string);
int str_isnumeric(string);
int str_isalpha(string);
char str_charAt(string, size_t);
int str_indentical(string, string);

#endif // MYSTRING_H_INCLUDED
