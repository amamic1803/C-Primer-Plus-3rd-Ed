#include <stdio.h>
#include <stdlib.h>
#define LIST_SIZE 100
static void sort(int array[], int limit);


void ch13_ex05(void) {
    int array[LIST_SIZE];
    int i;

    for (i = 0; i < LIST_SIZE; i++) {
        array[i] = rand() % 10 + 1;
    }

    puts("Original array:");
    for (i = 0; i < LIST_SIZE; i++) {
        printf("%d ", array[i]);
    }
    putchar('\n');

    sort(array, LIST_SIZE);

    puts("Sorted array:");
    for (i = 0; i < LIST_SIZE; i++) {
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