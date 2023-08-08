#include <stdio.h>


void ch06_ex03(void) {
    int i, j;
    char start_char = 'F';

    for (i = 1; i <= 6; i++) {
        for (j = 0; j < i; j++) {
            printf("%c", start_char - j);
        }
        printf("\n");
    }
}
