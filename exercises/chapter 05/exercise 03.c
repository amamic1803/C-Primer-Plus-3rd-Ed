#include <stdio.h>


void ch05_ex03(void) {
    int days;

    printf("Enter a number of days:\n");
    scanf("%d", &days);
    printf("%d days are %d weeks, %d days.", days, days / 7, days % 7);
}
