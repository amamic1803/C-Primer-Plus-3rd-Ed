#include <stdio.h>
static unsigned int on_bits(unsigned int num);


void ch15_ex03(void) {
    unsigned int input_num;

    printf("Enter an integer (q to quit):\n");
    while (scanf("%u", &input_num) == 1) {
        printf("The number of on bits in %d is %u.\n", input_num, on_bits(input_num));
        printf("Enter an integer (q to quit):\n");
    }
}

static unsigned int on_bits(unsigned int num) {
    unsigned int count = 0;
    while (num > 0) {
        count += num & 1U;
        num >>= 1U;
    }
    return count;
}