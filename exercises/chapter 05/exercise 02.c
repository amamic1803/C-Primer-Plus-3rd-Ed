#include <stdio.h>


void ch05_ex02(void) {
    int input_num;
    int working_num;

    printf("Enter a number:\n");
    scanf("%d", &input_num);
    printf("Numbers:\n");

    working_num = input_num;
    while ((working_num - input_num) <= 10) {
        printf("%d\n", working_num);
        working_num++;
    }
}
