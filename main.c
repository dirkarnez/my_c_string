#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

int main()
{
    string str = str_create();// declare my string;
    printf("Enter to String 1, data type \"mystring\"\n");
    str_input(str);
    str_print(str);
    printf("\nstring size %d", str_getlen(str));
    printf("\n----------------------------\n");

    printf("~str_addinput is called\n");
    str_addinput(str);
    str_print(str);
    printf("\nstring size %d", str_getlen(str));
    printf("\n----------------------------\n");

    printf("~str_trim is called\n");
    str_trim(str);
    str_print(str);
    printf("<-------\nstring size %d", str_getlen(str));
    printf("\n----------------------------\n");

    printf("~str_toupper is called\n");
    str_toupper(str);
    str_print(str);
    printf("\n----------------------------\n");

    printf("~str_tolower is called\n");
    str_tolower(str);
    str_print(str);
    printf("\n----------------------------\n");

    printf("~str_totitle is called\n");
    str_totitle(str);
    str_print(str);
    printf("\n----------------------------\n");

    printf("~str_isnumeric is called\n");
    int i = str_isnumeric(str);
    if (i == 1 )
    {
        printf("String 1 is numeric, return %d", i);
    }
    else
    {
        printf("String 1 is not numeric, return %d", i);
    }
    printf("\n----------------------------\n");

    printf("str_isalpha is called\n");
    i = str_isalpha(str);
    if (i == 1 )
    {
        printf("String 1 is all alphabets");
    }
    else
    {
        printf("String 1 is not all alphabets, return %d", i);
    }
    printf("\n----------------------------\n");


    printf("~str_charAt is called, want the 5th character in String 1\n");
    printf("%c", str_charAt(str, 4));
    printf("<-------");
    printf("\n----------------------------\n");


    printf("Create a new string for comparision.\nEnter to string 2, data type \"mystring\"\n");
    string strnew = str_create();
    str_input(strnew);
    printf("\nstring 1 = ");
    str_print(str);
    printf("\nstring 2 = ");
    str_print(strnew);
    i = str_indentical(str, strnew);
    if (i == 1 )
    {
        printf("\nString 1 and String 2 HAVE the same content, return %d", i);
    }
    else
    {
        printf("\nString 1 and String 2 DO NOT HAVE the same content, return %d", i);
    }
    printf("\n----------------------------\n");

    printf("~str_destroy is called\n");
    str_destroy(str);
    str_destroy(strnew);
    printf("string 1 = ");
    str_print(str);
    printf("\nstring size %d", str_getlen(str));
    printf("\nstring 2 = ");
    str_print(strnew);
    printf("\nstring size %d", str_getlen(strnew));
    printf("\n----------------------------\n");
    getchar();
    return 0;
}
