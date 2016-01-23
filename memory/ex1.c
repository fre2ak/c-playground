#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char firstName[100];
    char familyName[100];

    memset(firstName, 0, sizeof(firstName));
    memset(familyName, 0, sizeof(firstName));

    printf("Enter first and family name: ");
    scanf("%s %s", firstName, familyName);

    printf("Family name: %s, First name: %s\n", familyName, firstName);

    return 0;
}
