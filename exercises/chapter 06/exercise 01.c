#include <stdio.h>


void ch06_ex01(void) {
    char letters[26];

    for (int i = 0; i < 26; i++) {
        letters[i] = 'a' + i;
    }

    printf("Letters: ");
    for (int i= 0; i < 26; i++) {
        printf("%c ", letters[i]);
    }
    printf("\n");
}
