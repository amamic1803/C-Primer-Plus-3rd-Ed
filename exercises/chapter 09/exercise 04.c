#include <stdio.h>
static double harmonic_mean(double x, double y);


void ch09_ex04(void) {
    printf("Harmonic mean of %.0lf and %.0lf is %.2lf.\n", 1.0, 2.0, harmonic_mean(1.0, 2.0));
    printf("Harmonic mean of %.0lf and %.0lf is %.2lf.\n", 3.0, 4.0, harmonic_mean(3.0, 4.0));
}

static double harmonic_mean(double x, double y) {
    return 2 / (1 / x + 1 / y);
}