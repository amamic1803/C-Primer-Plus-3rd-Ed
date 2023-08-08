#include <assert.h>
#include <stdio.h>
#define ARR_SIZE 100
static int search_arr(int *arr, int n, int key);


void ch17_ex06(void) {
    int arr[ARR_SIZE];
    int key1 = 88, key2 = 0;
    int index;

    for (index = 1; index <= ARR_SIZE; index++)
        arr[index - 1] = index;

    if (search_arr(arr, ARR_SIZE, key1) == 0)
        printf("The int %d is not found in the array.\n", key1);
    else
        printf("The int %d is found in the array.\n", key1);

    if (search_arr(arr, ARR_SIZE, key2) == 0)
        printf("The int %d is not found in the array.\n", key2);
    else
        printf("The int %d is found in the array.\n", key2);

    for (index = 1; index <= ARR_SIZE; index++)
        assert(search_arr(arr, ARR_SIZE, index) == 1);
}

static int search_arr(int *arr, int n, int key) {
    int i = 0, j = n - 1, mid;

    while (i <= j) {
        mid = (i + j) / 2;
        if (key > arr[mid])
            i = mid + 1;
        else if (key < arr[mid])
            j = mid - 1;
        else
            return 1;
    }

    return 0;
}