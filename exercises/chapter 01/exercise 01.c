#include <stdio.h>


void ch01_ex01(void) {
    int val_inch;
    double val_cm;

    printf("Value in inches:\n");
    scanf("%d", &val_inch);
    val_cm = val_inch * 2.54;
    printf("Value in centimeters is %.2f.", val_cm);
}