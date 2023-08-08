#include <stdio.h>
#define ARRAY_SIZE 5
static void copy1(const int source[], int target[], int size);
static void copy2(const int *source, int *target, int size);


void ch10_ex02(void) {
    const int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    int array2[ARRAY_SIZE];
    int array3[ARRAY_SIZE];
    int i;

    printf("original array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");

    copy1(array1, array2, ARRAY_SIZE);
    copy2(array1, array3, ARRAY_SIZE);

    printf("copied array1:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");

    printf("copied array2:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array3[i]);
    }
    printf("\n");
}

static void copy1(const int source[], int target[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        target[i] = source[i];
    }
}

static void copy2(const int *source, int *target, int size) {
    int *limit = source + size;

    while (source < limit) {
        *target = *source;
        target++;
        source++;
    }
}