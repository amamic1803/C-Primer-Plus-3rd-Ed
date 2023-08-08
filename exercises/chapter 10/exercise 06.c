#include <stdio.h>
#define ARRAY_SIZE 5
static void copy(const int source[], int target[], int size);


void ch10_ex06(void) {
    const int array1[ARRAY_SIZE][ARRAY_SIZE] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
    };
    int array2[ARRAY_SIZE][ARRAY_SIZE];
    int i, j;

    printf("original array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j < ARRAY_SIZE; j++) {
            printf("%d ", array1[i][j]);
        }
        putchar('\n');
    }

    for (i = 0; i < ARRAY_SIZE; i++) {
        copy(array1[i], array2[i], ARRAY_SIZE);
    }

    printf("copied array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j < ARRAY_SIZE; j++) {
            printf("%d ", array2[i][j]);
        }
        putchar('\n');
    }
}

static void copy(const int source[], int target[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        target[i] = source[i];
    }
}