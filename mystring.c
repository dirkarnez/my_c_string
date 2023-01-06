#include "mystring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string str_create()
{
    string str;
    str = malloc (sizeof(stringv));
    str->c = NULL;
    str->size = 0;
    return str;
}

void str_print(string str)
{
    size_t i;
	for (i = 0; i < str->size; i++)
	{
        printf("%c", str->c[i]);
	}
}

size_t str_getlen(string str)
{
    return str->size;
}

void str_input(string str)
{
    char c;
    size_t i = 0;
    do
	{
		c = getchar();
        i += 1;
        str->c = (char *)realloc(str->c, i * sizeof(str->c));
        str->c[i - 1] = c;
	} while (c != '\n' && c != EOF);
	str->c[i]='\0';
	str->size = i - 1;
}

void str_destroy(string str)
{
    str->size = 0;
    free(str->c);
}

void str_toupper(string str)
{
    size_t i;
	for (i = 0; i < str->size; i++)
	{
        if ((str->c[i] > 96) && (str->c[i] < 123))
        {
            str->c[i] -=32;
        }
	}
}

void str_tolower(string str)
{
    size_t i;
	for (i = 0; i < str->size; i++)
	{
        if ((str->c[i] > 64) && (str->c[i] < 91))
        {
            str->c[i] +=32;
        }
	}
}

void str_totitle(string str)
{
    size_t i = 0;

    while (i < str->size) //97-122
    {
        if ((str->c[i] > 96) && (str->c[i] < 123))
        {
            str->c[i] -=32;
            break;
        }
        i++;
    }

	for (; i < str->size; i++)
	{
        if (str->c[i] == ' ')
		{
            if ((str->c[i+1] > 96) && (str->c[i+1] < 123))
            {
                str->c[i+1] -=32;
            }
		}
	}
}

int str_isnumeric(string str)
{
    size_t i = 0;
    while (i < str->size)
    {
        if ((str->c[i] < 48) || (str->c[i] > 57))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int str_isalpha(string str)
{
    size_t i = 0;
    while (i < str->size)
    {
        if (str->c[i] < 65 || (str->c[i] > 90 && str->c[i] < 97)  || str->c[i] > 122)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void str_addinput(string str)
{
    char c;
    do
	{
		c = getchar();
        str->size += 1;
        str->c = (char *)realloc(str->c, str->size * sizeof(str->c));
        str->c[str->size - 1] = c;
	} while (c != '\n' && c != EOF);
	str->size -= 1;
	str->c[str->size] = '\0';
}

void str_trim(string str)
{
    size_t i;
    size_t start;
    size_t end;
    size_t count;

    string newstr = str_create();

    if (str->size == 0)
    {
        return;
    }

    i = 0;
    count = 0;
    while (i < str->size)
    {
        if (str->c[i] != 32)
        {
            count++;
        }
        i++;
    }

    if (count == 0)
    {
        newstr->c = (char *)malloc(1 * sizeof(newstr->c));
        newstr->c[0] = '\0';
        newstr->size = 1;
    }
    else
    {
        i = 0;
        while (i < str->size)
        {
            if ((str->c[i] != 32))
            {
                start = i;
                break;
            }
            i++;
        }
        i = str->size - 1;
        while (1)
        {
            if (str->c[i] != 32)
            {
                end = i;
                break;
            }
            i--;
        }
        newstr->size = end - start + 2; //1for compliment, 1 for ending
        newstr->c = (char *)malloc(newstr->size * sizeof(newstr->c));

        for (i = 0; i < newstr->size; i++)
        {
             newstr->c[i] = str->c[start + i];
        }
        newstr->c[newstr->size] = '\0';
    }
    str->c = newstr->c;
    str->size = newstr->size - 1;
}

char str_charAt(string str, size_t index)
{
    if (index < str->size && index >= 0)
    {
        return str->c[index];
    }
    else
    {
        return NULL;
    }
}

int str_indentical(string str1, string str2)
{
    if (str1->size != str2->size)
    {
        return 0;
    }

    size_t i = 0;
    while (i < str1->size)
    {
        if (str1->c[i] != str2->c[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

