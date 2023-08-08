#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static unsigned short int parse_binary(char *s);
static void print_binary(unsigned short int n);
static unsigned short int is_binary(char *s);


void ch15_ex02(int argc, char *argv[]) {
    unsigned short int n1, n2;

    if (argc != 3) {
        printf("Usage: %s <binary_number> <binary_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (!is_binary(argv[1]) || !is_binary(argv[2])) {
        printf("Both arguments must be binary numbers.\n");
        exit(EXIT_FAILURE);
    }

    if (strlen(argv[1]) > (sizeof(int) * 8) || strlen(argv[2]) > (sizeof(unsigned short int) * 8)) {
        printf("Both arguments must be %llu bits long or less.\n", (sizeof(unsigned short int) * 8));
        exit(EXIT_FAILURE);
    }

    n1 = parse_binary(argv[1]);
    n2 = parse_binary(argv[2]);

    printf("First binary number: ");
    print_binary(n1);
    putchar('\n');
    printf("Second binary number: ");
    print_binary(n2);
    putchar('\n');

    putchar('\n');
    putchar('~');
    print_binary(n1);
    printf(" == ");
    print_binary(~n1);

    putchar('\n');
    putchar('~');
    print_binary(n2);
    printf(" == ");
    print_binary(~n2);

    putchar('\n');
    print_binary(n1);
    printf(" & ");
    print_binary(n2);
    printf(" == ");
    print_binary(n1 & n2);

    putchar('\n');
    print_binary(n1);
    printf(" | ");
    print_binary(n2);
    printf(" == ");
    print_binary(n1 | n2);

    putchar('\n');
    print_binary(n1);
    printf(" ^ ");
    print_binary(n2);
    printf(" == ");
    print_binary(n1 ^ n2);
    putchar('\n');
}

static unsigned short int parse_binary(char *s) {
    unsigned int n = 0;
    while (*s) {
        n <<= 1;
        if (*s == '1') {
            n |= 1;
        }
        s++;
    }
    return n;
}

static void print_binary(unsigned short int n) {
    unsigned short int power = 0;

    while ((n >> power) > 0) {
        power++;
    }

    for (power--; power > 0; power--) {
        printf("%d", (n >> power) & 1);
    }
    printf("%d", n & 1);
}

static unsigned short int is_binary(char *s) {
    while (*s) {
        if (*s != '0' && *s != '1') {
            return 0;
        }
        s++;
    }
    return 1;
}
