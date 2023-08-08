#include <stdio.h>
#include <stdlib.h>


void ch13_ex06(void) {
    int appearances[10];
    int seed;
    int num;
    int i;

    for (i = 0; i < 10; i++) {
        appearances[i] = 0;
    }

    for (seed = 1; seed <= 10; seed ++) {
        srand(seed);
        for (i = 0; i < 1000; i++) {
            num = rand() % 10 + 1;
            appearances[num - 1]++;
        }
        printf("Seed: %d\n", seed);
        for (i = 0; i < 10; i++) {
            printf("%d: %d\n", i + 1, appearances[i]);
        }
        putchar('\n');
        for (i = 0; i < 10; i++) {
            appearances[i] = 0;
        }
    }
}