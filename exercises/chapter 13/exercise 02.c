#include <stdio.h>
#define ARRAY_SIZE 5
static void sort_f(float *array, int n);


void ch13_ex02(void) {
    float array[ARRAY_SIZE] = { 5.5f, 3.3f, 2.2f, 4.4f, 1.1f };
    int i;

    puts("Original array:");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%.1f ", array[i]);
    putchar('\n');

    sort_f(array, ARRAY_SIZE);

    puts("Sorted array:");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%.1f ", array[i]);
    putchar('\n');
}

static void sort_f(float *array, int n) {
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (array[j] < array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}