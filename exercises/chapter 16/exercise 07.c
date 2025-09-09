#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SAMPLE_SIZE 100
static void print_rand(int *arr, int size, int picks);


void ch16_ex07(void) {
    int arr[SAMPLE_SIZE];
    int i;

    srand(time(NULL));

    for (i = 0; i < SAMPLE_SIZE; i++) {
        arr[i] = i;
    }

    print_rand(arr, SAMPLE_SIZE, 10);
    printf("\n");
}

static void print_rand(int *arr, int size, int picks) {
    int *picked;
    int i;
    int curr_size = size;

    if (picks > size) {
        fprintf(stderr, "Error: picks > size\n");
        exit(EXIT_FAILURE);
    }

    if ((picked = (int *) malloc(size * sizeof(int))) == NULL) {
        fprintf(stderr, "Error: allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < size; i++) {
        picked[i] = arr[i];
    }

    while (size - curr_size < picks) {
        i = rand() % curr_size;
        printf("%d ", arr[i]);
        picked[i] = picked[--curr_size];
    }

    free(picked);
}
