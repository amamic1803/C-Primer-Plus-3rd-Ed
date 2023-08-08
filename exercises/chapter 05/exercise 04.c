#include <stdio.h>


void ch05_ex04(void) {
    int input_num;
    int sum, count;

    printf("Enter a number:\n");
    scanf("%d", &input_num);

    sum = 0;
    count = input_num;
    while (count > 0) {
        sum += count;
        count--;
    }

    printf("The sum of first %d numbers is %d.", input_num, sum);
}
