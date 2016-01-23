#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char * firstName;
    char * lastName;

    scanf("%ms %ms", &firstName, &lastName);
    printf("%s %s\n", lastName, firstName);

    printf("Size first name: %d, size last name: %d\n", strlen(firstName), strlen(lastName));

    free(firstName);
    free(lastName);

    return 0;
}
