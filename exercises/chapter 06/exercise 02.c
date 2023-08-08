#include <stdio.h>


void ch06_ex02(void) {
    int i, j;

    for (i = 1; i <= 5; i++) {
        for (j = 0; j < i; j++) {
            printf("$");
        }
        printf("\n");
    }
}
