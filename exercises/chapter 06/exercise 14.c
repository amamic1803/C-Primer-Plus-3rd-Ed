#include <stdio.h>


void ch06_ex14(void) {
    int years;
    double balance;

    balance = 1000000;
    years = 0;

    while (balance > 0.0) {
        balance *= 1.08;
        balance -= 100000;
        years++;
    }

    printf("It takes Chuckie Lucky %d years to empty his account!", years);
}
