#include <stdio.h>


void ch06_ex05(void) {
    int low_lim, high_lim;
    int i;

    printf("Enter lower and upper integer limits:\n");
    scanf("%d %d", &low_lim, &high_lim);

    printf("   n     n^2    n^3\n");
    for (i = low_lim; i <= high_lim; i++) {
        printf("%5d %5d %5d\n", i, i * i, i * i * i);
    }
}
