#include <stdio.h>
static int get_bit(int num, int bit);


void ch15_ex04(void) {
    int num, bit;

    printf("Enter a number and a bit position (q to exit):\n");
    while (scanf("%d %d", &num, &bit) == 2) {
        printf("The bit %d of %d is %d\n", bit, num, get_bit(num, bit));
        printf("Enter a number and a bit position (q to exit):\n");
    }
}

static int get_bit(int num, int bit) {
    return (num >> bit) & 1;
}