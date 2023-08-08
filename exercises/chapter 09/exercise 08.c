#include <stdio.h>
static double power(double a, int b);


void ch09_ex08(void) {
    printf("2 ^ 3 = %.0f\n", power(2.0, 3));
    printf("2 ^ -3 = %.3f\n", power(2.0, -3));
    printf("0 ^ 0 = %.0f\n", power(0.0, 0));
    printf("0 ^ 3 = %.0f\n", power(0.0, 3));
    printf("3 ^ 0 = %.0f\n", power(3.0, 0));
}

static double power(double a, int b) {
    if (a == 0.0) {
        return a;
    } else if (b == 0) {
        return 1;
    } else {
        return b > 0 ? a * power(a, b - 1) : (1 / a) * power(a, b + 1);
    }
}