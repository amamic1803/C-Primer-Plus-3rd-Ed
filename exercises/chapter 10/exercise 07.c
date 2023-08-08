#include <stdio.h>
static void copy(const int *source, int *target, int size);


void ch10_ex07(void) {
    const int array1[7] = {1, 2, 3, 4, 5, 6, 7};
    int array2[3];
    int i;

    printf("original array:\n");
    for (i = 0; i < 7; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");

    copy(&array1[2], array2, 3);

    printf("copied array:\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");
}

static void copy(const int *source, int *target, int size) {
    int *limit = source + size;

    while (source < limit) {
        *target = *source;
        target++;
        source++;
    }
}