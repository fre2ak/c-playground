#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bigint.h"

#define MAX_INT_DIGITS 10
#define MAX_LONG_DIGITS 20

int main(int argc, char** argv)
{
    printf("WARNING: Calculating large numbers of iterations can take a long time (> 10 minutes).\n");
    printf("The output file can also grow very large. The output file for 100,000 iterations is ~1GB.\n");
    printf("This program will use ~100%% CPU time during calculation.\n");
    printf("The program does not check for errors while calculating.\n");
    printf("If an error occurs during calculation, the operation of this program is undefined.\n");

    char temp = 'a';

    bigint* a = newnumc("1");
    bigint* b = newnumc("1");
    bigint* c = newnumc("0");

    int size = 0;

    if(argc == 2)
    {
        size = atoi(argv[1]);
    }
    else if(argc == 4)
    {
        a = newnumc(argv[1]);
        b = newnumc(argv[2]);
        size = atoi(argv[3]);
    }
    else
    {
        printf("How many iterations do you want? ");
        scanf("%i", &size);
    }


    char* fname = (char*)malloc(9 + MAX_INT_DIGITS + MAX_LONG_DIGITS + 1);
    sprintf(fname, "fib-%i-%i.txt", size, time(NULL));
    FILE *file = fopen(fname, "w");

    if(size == 1)
    {
        fprint(a, file);
    }
    else if(size >= 2)
    {
        fprint(a, file);
        fprint(b, file);
    }

    size -= 2;

    int i = 0;
    while(i < size)
    {
        add(a, b, c);
        fprint(c, file);

        numcpy(a, b);
        numcpy(b, c);

        i++;
    }

    delnum(a);
    delnum(b);
    delnum(c);

    fflush(file);
    fclose(file);
    free(fname);

    return 0;
}
