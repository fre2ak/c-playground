#define CHARZERO_ABOVEINTZERO 48

typedef unsigned char digit;

typedef struct
{
    digit* number;
    int length;
} bigint;

void newnum(bigint*);
void newnumf(bigint*, char*);
bigint* newnumc(char*);
void numcpy(bigint*, bigint*);
void delnum(bigint*);

void add(bigint*, bigint*, bigint*);

void print(bigint*);
void fprint(bigint*, FILE*);
