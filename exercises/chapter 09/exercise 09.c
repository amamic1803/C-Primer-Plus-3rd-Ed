#include <stdio.h>
static void to_base(int n, int base);


void ch09_ex09(void) {
    int n, base;
    printf("Enter a number and a base:\n");
    scanf("%d %d", &n, &base);
    if (!(base >= 2 && base <= 10)) {
        printf("Base must be between 2 and 10.\n");
    } else {
        printf("The number %d in base %d is ", n, base);
        to_base(n, base);
        printf(".\n");
    }
}

static void to_base(int n, int base) {
    if (!(base >= 2 && base <= 10)) {
        printf("Base must be between 2 and 10.\n");
    } else if (base == 10) {
        printf("%d", n);
    } else {
        int r;
        r = n % base;
        if (n >= base) {
            to_base(n / base, base);
        }
        putchar('0' + r);
    }
}