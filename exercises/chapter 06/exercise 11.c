#include <stdio.h>


void ch06_ex11(void) {
    const int LEN = 8;
    int powers[LEN];
    int i;
    int working_val;

    for (i = 0, working_val = 2; i < LEN; i++, working_val *= 2) {
        powers[i] = working_val;
    }

    printf("Values:");
    i = 0;
    do {
        printf(" %d", powers[i++]);
    } while (i < LEN);
    printf("\n");
}
