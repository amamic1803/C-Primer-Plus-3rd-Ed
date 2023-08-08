#include <stdio.h>


void ch06_ex13(void) {
    const int original_investment = 100;
    double daphne, deirdre;
    int i;

    daphne = 1.1 * (double) original_investment;
    deirdre = 1.05 * (double) original_investment;
    i = 1;
    while (daphne > deirdre) {
        daphne += 0.1 * (double) original_investment;
        deirdre *= 1.05;
        i++;
    }

    printf("Deirdre's investment exceeds the value of Daphne's investment after %d years.\n"
           "Daphne has $%.0lf, Deirdre has $%.0lf.", i, daphne, deirdre);
}
