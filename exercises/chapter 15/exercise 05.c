#include <stdio.h>
static void rotate_l(unsigned int *n, unsigned int b);


void ch15_ex05(void) {
    unsigned int n;
    unsigned int b;

    printf("Enter an unsigned integer and the number of bits to be rotated (q to exit):\n");
    while (scanf("%u %u", &n, &b) == 2) {
        rotate_l(&n, b);
        printf("The result is %u.\n", n);
        printf("Enter an unsigned integer and the number of bits to be rotated (q to exit):\n");
    }
}

static void rotate_l(unsigned int *n, unsigned int b) {
    unsigned int mask = 0;
    unsigned int temp = *n;
    unsigned int length = 0;
    unsigned int i;

    while (temp > 0) {
        temp >>= 1U;
        length++;
    }

    if (length == 0) {
        return;
    }

    if (length < b) {
        b %= length;
    }

    for (i = 0; i < length; i++) {
        if (i < b) {
            mask <<= 1U;
            mask |= 1U;
        } else {
            mask <<= 1U;
        }
    }

    temp = *n;

    temp >>= length - b;
    *n &= ~mask;
    *n <<= b;
    *n |= temp;
}
