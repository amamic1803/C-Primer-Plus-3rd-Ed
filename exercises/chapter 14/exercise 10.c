#include <ctype.h>
#include <math.h>
#include <stdio.h>
static void squares(long long unsigned int n);
static void cubes(long long unsigned int n);
static void primes(long long unsigned int n);
static void fibonacci(long long unsigned int n);
static void perfect(long long unsigned int n);


void ch14_ex10(void) {
    long long unsigned int limit = 1000;
    char choice;
    void (*functions[5])(long long unsigned int) = {squares, cubes, primes, fibonacci, perfect};

    while (1) {
        printf("Limit: %llu\n", limit);
        printf("a) squares\n");
        printf("b) cubes\n");
        printf("c) primes\n");
        printf("d) fibonacci\n");
        printf("e) perfect\n");
        printf("f) change limit\n");
        printf("q) quit\n");
        printf("Enter your choice:\n");

        choice = (char) tolower(getchar());
        if (choice != '\n')
            while (getchar() != '\n');
        putchar('\n');

        switch (choice) {
            case 'a':
                functions[0](limit);
                break;
            case 'b':
                functions[1](limit);
                break;
            case 'c':
                functions[2](limit);
                break;
            case 'd':
                functions[3](limit);
                break;
            case 'e':
                functions[4](limit);
                break;
            case 'f':
                printf("Enter new limit:\n");
                scanf("%llu", &limit);
                while (getchar() != '\n');
                break;
            case 'q':
                goto out;
            default:
                printf("Invalid choice.\n");
                break;
        }
        putchar('\n');
    }
    out:;
}

static void squares(long long unsigned int n) {
    long long unsigned int i = 1;
    long long unsigned int square;

    printf("SQUARES:\n");
    while ((square = i * i) <= n) {
        printf("%llu\n", square);
        i++;
    }
}

static void cubes(long long unsigned int n) {
    long long unsigned int i = 1;
    long long unsigned int cube;

    printf("CUBES:\n");
    while ((cube = i * i * i) <= n) {
        printf("%llu\n", cube);
        i++;
    }
}

static void primes(long long unsigned int n) {
    long long unsigned int i, j;
    int prime;

    printf("PRIMES:\n");
    for (i = 2; i <= n; i++) {
        prime = 1;
        for (j = 2; j <= (long long unsigned int) floorl(sqrtl((long double) i)); j++)
            if (i % j == 0) {
                prime = 0;
                break;
            }
        if (prime)
            printf("%llu\n", i);
    }
}

static void fibonacci(long long unsigned int n) {
    long long unsigned int num1 = 0, num2 = 1, temp;

    printf("FIBONACCI:\n");
    printf("%llu\n", num1);
    if (n > 0)
        printf("%llu\n", num2);

    while ((temp = num1 + num2) <= n) {
        printf("%llu\n", temp);
        num1 = num2;
        num2 = temp;
    }
}

static void perfect(long long unsigned int n) {
    long long unsigned int i, j;
    long long unsigned int sum_divisors;

    printf("PERFECT:\n");

    for (i = 1; i <= n; i++) {
        for (j = 1, sum_divisors = 0; j <= i / 2; j++)
            if (i % j == 0)
                sum_divisors += j;
        if (sum_divisors == i)
            printf("%llu\n", i);
    }
}
