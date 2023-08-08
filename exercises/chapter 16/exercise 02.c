#include <stdio.h>
#include "header 02.h"


void ch16_ex02(void) {
    int n, m;

    printf("Enter two integers (q to quit):\n");
    while (scanf("%d %d", &n, &m) == 2) {
        printf("The harmonic mean of %d and %d is %.3lf.\n", n, m, HMEAN((double) n, (double) m));
        printf("Enter two integers (q to quit):\n");
    }
}