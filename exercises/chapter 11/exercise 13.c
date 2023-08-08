#include <stdio.h>
#include <stdlib.h>
static double power(double n, int p);


void ch11_ex13(int argc, char **argv) {
    double number;
    int exponent;

    if (argc < 3) {
        printf("Invalid number of arguments.\n");
        exit(EXIT_FAILURE);
    }

    number = strtod(argv[1], NULL);
    exponent = strtol(argv[2], NULL, 10);
    printf("%g ^ %d = %g\n", number, exponent, power(number, exponent));
}

static double power(double n, int p) {
    double num = 1;
    int i;

    if (p == 0) {
        num = 1;
    } else if (p > 0) {
        for (i = 0; i < p; i++) {
            num *= n;
        }
    } else {
        for (i = 0; i < -p; i++) {
            num *= 1 / n;
        }
    }

    return num;
}