#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//#define LIMIT 100000 /*size of integers array*/

#define MAX_NUMBER 10000000

int main (int argc, char *argv[]) {

    time_t time = clock();
/*    
    unsigned long long int i, j;
    int * primes; 
    int z = 1;

    primes = malloc(sizeof(int) * LIMIT);

    for (i = 2; i < LIMIT; i++)
        primes[i] = 1;

    for (i = 2; i < LIMIT; i++)
        if (primes[i])
            for (j = i; i * j < LIMIT; j++)
                primes[i * j] = 0;

    for (i = 2; i < LIMIT; i++)
        if (primes[i])
            printf("%dth prime = %d\n", z++, i);
*/
 
    int numberOfPrimes = 0;

    for (int i = MAX_NUMBER - 1; i > 1; i--) {
        int flag = 0;

        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            numberOfPrimes++;
        }
    }
 
    printf("%d\n", numberOfPrimes); 
    printf("%lf\n", ((double)clock() - time) / CLOCKS_PER_SEC);

    return 0;
}
