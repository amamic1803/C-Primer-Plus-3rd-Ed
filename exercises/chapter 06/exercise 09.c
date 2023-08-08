#include <stdio.h>


void ch06_ex09(void) {
    const int num_of_ints = 8;
    int integers[num_of_ints];
    int i;

    printf("Enter integers:\n");
    for (i = 0; i < num_of_ints; i++) {
        scanf("%d", &integers[i]);
    }

    printf("Integers:");
    for (i = num_of_ints - 1; i >= 0; i--) {
        printf(" %d", integers[i]);
    }
    printf("\n");
}
