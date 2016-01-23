#include <stdio.h>
#include <stdint.h>
#include <gmp.h>

int fib (int n, int prev, int acc) {
    if (n == 0) {
        return acc;
    }
    
    return fib(n - 1, prev, prev + acc);
}

int main (int argc, char *argv[]) {   

    printf("Fibonacci number: %llu\n", 1);

    long Nth;             /* INPUT: Desired Fibonacci number index     */
        long n;               /* Loop counter                              */
            mpz_t cn;             /* Current Fibonacci Number                  */
                mpz_t fp;             /* First  Previous Fibonacci Number          */
                    mpz_t sp;             /* Second Previous Fibonacci Number          */

                        mpz_init( sp );       /* Initialize sp as F  = 0                   */
                            mpz_set_ui(sp, 0);    /*                   0                       */
                                mpz_init( fp );       /* Initialize fp as F  = 1                   */
                                    mpz_set_ui(fp, 1);    /*                   1                       */

                                        mpz_init( cn );       /* Initialize cn to make it ready for use    */

                                            printf("Please enter which value in the Fibonacci sequence you want: ");
                                                scanf("%d",&Nth);
                                                    if (Nth<0)
                                                                printf("ERROR: negative sequence numbers not permitted.\n");
                                                        if (Nth==0 || Nth==1)
                                                                    mpz_set_ui(cn, Nth);

                                                            for (n=2; n<=Nth; ++n)
                                                                    {
                                                                                mpz_add(cn, sp, fp);    /* cn = sp + fp */
                                                                                        mpz_set(sp,fp);         /* sp = fp;     */ 
                                                                                                mpz_set(fp,cn);         /* fp = cn;     */ 
                                                                                                    }

                                                                /* http://gmplib.org/manual/Formatted-Output-Strings.html */
                                                                gmp_printf ("Fibonacci(%d) is %Zd\n", Nth, cn);

                                                                    /* Clean up and reclaim memory. (Not strictly needed in this program.)*/
                                                                    mpz_clear( sp );
                                                                        mpz_clear( fp );
                                                                            mpz_clear( cn );

                                                                                printf("\nFinished.\n");

    return 0;
}

