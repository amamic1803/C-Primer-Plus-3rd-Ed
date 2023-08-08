#include <stdio.h>


void ch03_ex04(void) {
    double fp_num;

    printf("Enter floating point number:\n");
    scanf("%lf", &fp_num);
    printf("The input is %f or %e.", fp_num, fp_num);
}