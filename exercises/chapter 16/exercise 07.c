#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SAMPLE_SIZE 100
static void print_rand(int *arr, int size, int picks);


void ch16_ex07(void) {
    int arr[SAMPLE_SIZE];
    int i;

    for (i = 0; i < SAMPLE_SIZE; i++) {
        arr[i] = i;
    }

    print_rand(arr, SAMPLE_SIZE, 10);
    printf("\n");
}

static void print_rand(int *arr, int size, int picks) {
    int *picked;
    int i, j, l;
    int made_picks = 0;

    if (picks > size) {
        fprintf(stderr, "Error: picks > size\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    if ((picked = (int *) malloc(size * sizeof(int))) == NULL) {
        fprintf(stderr, "Error: allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < size; i++) {
        picked[i] = 0;
    }

    while (made_picks < picks) {
        i = rand() % (size - made_picks);
        j = 0;
        l = -1;
        while (l < i) {
            if (picked[j] == 0)
                l++;
            if (l != i)
                j++;
        }
        picked[j] = 1;
        made_picks++;
        printf("%d ", arr[j]);
    }

    free(picked);
}
