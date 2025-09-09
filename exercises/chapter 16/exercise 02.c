#include "header 02.h"
#include <stdio.h>


void ch16_ex02(void) {
    int n;
    int m;

    printf("Enter two integers (q to quit):\n");
    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 || m == 0) {
            printf("The harmonic mean of %d and %d is undefined.\n", n, m);
        } else {
            printf("The harmonic mean of %d and %d is %.3lf.\n", n, m, HMEAN((double) n, (double) m));  // NOLINT(clang-analyzer-optin.taint.TaintedDiv)
            printf("Enter two integers (q to quit):\n");
        }
    }
}
