#include <math.h>
#include <stdio.h>
static double power(double a, int b);


void ch09_ex07(void) {
    printf("2 ^ 3 = %.0f\n", power(2.0, 3));
    printf("2 ^ -3 = %.3f\n", power(2.0, -3));
    printf("0 ^ 0 = %.0f\n", power(0.0, 0));
    printf("0 ^ 3 = %.0f\n", power(0.0, 3));
    printf("3 ^ 0 = %.0f\n", power(3.0, 0));
}

static double power(double a, int b) {
    int i;
    double result = 1;

    if (a == 0.0) {
        return a;
    } else {
        for (i = 0; i < abs(b); i++) {
            result *= a;
        }
        return b > 0 ? result : 1 / result;
    }
}