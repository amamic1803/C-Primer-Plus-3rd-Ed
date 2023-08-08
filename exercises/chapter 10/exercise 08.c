#include <stdio.h>
#define ARRAY_SIZE 5
static void sum_arrays(const int *arr1, const int *arr2, int *result_arr, int size);


void ch10_ex08(void) {
    const int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    const int array2[ARRAY_SIZE] = {2, 3, 4, 5, 6};
    int result_array[ARRAY_SIZE];
    int i;

    printf("array 1:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");

    printf("array 2:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");

    sum_arrays(array1, array2, result_array, ARRAY_SIZE);

    printf("summed array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", result_array[i]);
    }
    printf("\n");
}

static void sum_arrays(const int *arr1, const int *arr2, int *result_arr, int size) {
    int i;

    for (i = 0; i < size; i++) {
        result_arr[i] = arr1[i] + arr2[i];
    }
}