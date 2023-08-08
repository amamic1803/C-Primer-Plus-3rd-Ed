#include <stdio.h>


void ch08_ex01(void) {
    int count = 0;

    printf("Enter text (EOF to quit):\n");
    while (getchar() != EOF) {
        count++;
    }
    printf("There are %d characters in the input.\n", count);
}
