#include <stdio.h>
static int on_bits(int num);


void ch15_ex03(void) {
    int input_num;

    printf("Enter an integer (q to quit):\n");
    while (scanf("%d", &input_num) == 1) {
        printf("The number of on bits in %d is %d.\n", input_num, on_bits(input_num));
        printf("Enter an integer (q to quit):\n");
    }
}

static int on_bits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}