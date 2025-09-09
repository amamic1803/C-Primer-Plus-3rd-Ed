#include <stdio.h>
#define ARRAY_SIZE 5
static void sort_f(float *array, int n);


void ch13_ex02(void) {
    float array[ARRAY_SIZE] = { 5.5F, 3.3F, 2.2F, 4.4F, 1.1F };
    int i;

    puts("Original array:");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%.1f ", array[i]);
    }
    putchar('\n');

    sort_f(array, ARRAY_SIZE);

    puts("Sorted array:");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%.1f ", array[i]);
    }
    putchar('\n');
}

static void sort_f(float *array, int n) {
    int i;
    int j;
    float temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}