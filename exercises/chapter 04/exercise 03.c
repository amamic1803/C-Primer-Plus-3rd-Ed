#include <stdio.h>


void ch04_ex03(void) {
    double input_num;

    printf("Enter a float:\n");
    scanf("%lf", &input_num);

    printf("The input is %2.1f or %1.1e\n", input_num, input_num);
    printf("The input is %+2.3f or %1.3E", input_num, input_num);
}