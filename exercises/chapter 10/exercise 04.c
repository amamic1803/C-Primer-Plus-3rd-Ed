#include <stdio.h>
static int max_val_ind(const int *arr, int size);


void ch10_ex04(void) {
    const int arr[5] = {1, 2, 4, 5, 3};
    printf("The index of the largest value in the array [");
    for (int i = 0; i < 5; i++) {
        printf("%d", arr[i]);
        if (i < 4) {
            printf(", ");
        }
    }
    printf("] is %d.\n", max_val_ind(&arr[0], sizeof arr / sizeof arr[0]));
}

static int max_val_ind(const int *arr, int size) {
    int largest = *arr;
    int largest_index = 0;

    for (int i = 1; i < size; i++) {
        if (*(arr + i) > largest) {
            largest = *(arr + i);
            largest_index = i;
        }
    }
    return largest_index;
}