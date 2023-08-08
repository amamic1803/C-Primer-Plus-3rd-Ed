#include <stdio.h>
static char * string_in(char * str1, char * str2);


void ch11_ex07(void) {
    char *ptr;
    char hamburger[] = "hamburger";
    char burger[] = "burger";
    char bug[] = "bug";

    ptr = string_in(hamburger, burger);
    if (ptr != NULL) {
        printf("\"%s\" is contained in \"%s\" at position %d.\n", burger, hamburger, (int) (ptr - hamburger));
    } else {
        printf("\"%s\" is not contained in \"%s\".\n", burger, hamburger);
    }

    ptr = string_in(hamburger, bug);
    if (ptr != NULL) {
        printf("\"%s\" is contained in \"%s\" at position %d.\n", bug, hamburger, (int) (ptr - hamburger));
    } else {
        printf("\"%s\" is not contained in \"%s\".\n", bug, hamburger);
    }
}

static char * string_in(char * str1, char * str2) {
    char *ptr1, *ptr2;
    int i;

    for (ptr1 = str1; *ptr1 != '\0'; ptr1++) {
        for (i = 0, ptr2 = str2; *ptr2 != '\0' && *(ptr1 + i) == *ptr2; i++, ptr2++);
        if (*ptr2 == '\0') {
            return ptr1;
        }
    }
    return NULL;
}