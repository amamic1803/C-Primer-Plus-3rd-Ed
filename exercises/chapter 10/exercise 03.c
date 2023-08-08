#include <stdio.h>
static int largest_value(const int *arr, int size);


void ch10_ex03(void) {
    const int arr[5] = {1, 2, 4, 5, 3};
    printf("The largest value in the array [");
    for (int i = 0; i < 5; i++) {
        printf("%d", arr[i]);
        if (i < 4) {
            printf(", ");
        }
    }
    printf("] is %d.\n", largest_value(&arr[0], sizeof arr / sizeof arr[0]));
}

static int largest_value(const int *arr, int size) {
    int largest = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > largest) {
            largest = *(arr + i);
        }
    }
    return largest;
}