#include <stdio.h>
static int max_diff(const int *arr, int size);


void ch10_ex05(void) {
    const int arr[5] = {1, 2, 4, 5, 3};
    printf("The difference between largest and smallest value in the array [");
    for (int i = 0; i < 5; i++) {
        printf("%d", arr[i]);
        if (i < 4) {
            printf(", ");
        }
    }
    printf("] is %d.\n", max_diff(&arr[0], sizeof arr / sizeof arr[0]));
}

static int max_diff(const int *arr, int size) {
    int largest = arr[0];
    int smallest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        } else if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return largest - smallest;
}