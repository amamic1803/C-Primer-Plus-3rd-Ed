#include <stdio.h>


void ch05_ex05(void) {
    int input_num;
    int sum, count;

    printf("Enter a number:\n");
    scanf("%d", &input_num);

    sum = 0;
    count = input_num;
    while (count > 0) {
        sum += count * count;
        count--;
    }

    printf("The sum of squares of first %d numbers is %d.", input_num, sum);
}
