#include <stdio.h>
#define ARRAY_SIZE 10
static void sort(int array[], int limit);


void ch13_ex03(void) {
    int array[ARRAY_SIZE] = { 1, 2, 4, 3, 7, 6, 5, 9, 8, 0 };
    int i;

    puts("Original array:");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    putchar('\n');

    sort(array, ARRAY_SIZE);

    puts("Sorted array:");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    putchar('\n');
}

static void sort(int array[], int limit) {
    int top, search, temp, i;

    for (top = 0; top < limit - 1; top++) {
        i = top;
        for (search = top + 1; search < limit; search++)
            if (array[search] > array[top] && array[search] > array[i]) {
                i = search;
            }
        if (i != top) {
            temp = array[top];
            array[top] = array[i];
            array[i] = temp;
        }
    }
}