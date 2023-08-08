#include <stdio.h>
static double min(double x, double y);


void ch09_ex01(void) {
    const double db1 = 1.0;
    const double db2 = 2.0;
    const double db3 = 3.0;
    const double db4 = -4.0;

    printf("Smaller of %.2lf and %.2lf is %.2lf.\n", db1, db2, min(db1, db2));
    printf("Smaller of %.2lf and %.2lf is %.2lf.\n", db3, db4, min(db3, db4));
}

static double min(double x, double y) {
    return x < y ? x : y;
}