#include <stdio.h>
static unsigned int get_bit(unsigned int num, unsigned int bit);


void ch15_ex04(void) {
    unsigned int num;
    unsigned int bit;

    printf("Enter a number and a bit position (q to exit):\n");
    while (scanf("%u %u", &num, &bit) == 2) {
        printf("The bit %u of %u is %u\n", bit, num, get_bit(num, bit));
        printf("Enter a number and a bit position (q to exit):\n");
    }
}

static unsigned int get_bit(unsigned int num, unsigned int bit) {
    return (num >> bit) & 1U;
}
