#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bigint.h"

void newnum(bigint* num)
{
    num->number = (digit*)malloc(1);
    num->number[0] = 0;
    num->length = 1;
}

void newnumf(bigint* num, char* numb)
{
    int numbl = strlen(numb);
    digit* out = (digit*)malloc(numbl);
    for(int i = 0; i < numbl; i++)
    {
        out[i] = numb[i] - CHARZERO_ABOVEINTZERO;
    }
    num->number = out;
    num->length = numbl;
}

bigint* newnumc(char* numb)
{
    bigint* num = (bigint*)malloc(sizeof(bigint));

    int numbl = strlen(numb);
    int numbll = numbl - 1;

    digit* out = (digit*)malloc(numbl);
    for(int i = 0; i < numbl; i++)
    {
        out[i] = numb[numbll - i] - CHARZERO_ABOVEINTZERO;
    }
    num->number = out;
    num->length = numbl;

    return num;
}

void numcpy(bigint* to, bigint* from)
{
    to->number = (digit*)realloc(to->number, from->length);

    int fl = from->length;
    digit* tn = to->number;
    digit* fn = from->number;
    for(int i = 0; i < fl; i++)
    {
        tn[i] = fn[i];
    }

    to->length = from->length;
}

void delnum(bigint* num)
{
    free(num->number);
    free(num);
}

void add(bigint* a, bigint* b, bigint* result)
{
    int al = a->length;
    int bl = b->length;
    int length = al;
    if(bl > al) length = bl;

    int cl = length + 1;

    digit* ac = a->number;
    digit* bc = b->number;

    digit* out = (digit*)malloc(cl);

    int temp = 0, carry = 0;
    for(int i = 0; i < length; i++)
    {
        if(i >= al) temp = bc[i] + carry;
        else if(i >= bl) temp = ac[i] + carry;
        else temp = ac[i] + bc[i] + carry;

        if(temp > 9)
        {
            carry = 1;
            temp -= 10;
        }
        else
        {
            carry = 0;
        }
        out[i] = temp;
    }

    if(carry == 0)
    {
        out = (digit*)realloc(out, length);
        result->length = length;
    }
    else
    {
        out[length] = carry;
        result->length = cl;
    }

    result->number = out;
}

void print(bigint* num)
{
    digit* numc = num->number;
    int numl = num->length;
    int numll = numl - 1;
    char* out = (char*)malloc(numl + 1);
    for(int i = 0; i < numl; i++)
    {
        out[i] = numc[numll - i] + CHARZERO_ABOVEINTZERO;
    }
    out[numl] = '\0';

    puts(out);
    free(out);
}

void fprint(bigint* num, FILE *file)
{
    digit* numc = num->number;
    int numl = num->length;
    int numll = numl - 1;
    char* out = (char*)malloc(numl + 1);
    for(int i = 0; i < numl; i++)
    {
        out[i] = numc[numll - i] + CHARZERO_ABOVEINTZERO;
    }
    out[numl] = '\0';

    fputs(out, file);
    putc('\n', file);
    free(out);
}

