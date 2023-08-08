#include <stdio.h>
static void cube(double num);


void ch05_ex06(void) {
    double input_num;

    printf("Enter a number:\n");
    scanf("%lf", &input_num);
    cube(input_num);
}

static void cube(double num) {
    printf("The cube of %f is %f.\n", num, num * num * num);
}
