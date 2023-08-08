#include <stdio.h>
#define ROWS 3
#define COLS 5
static void display_array(const double ar[][COLS], int rows);
static void mul2_array(double ar[][COLS], int rows);


void ch10_ex09(void) {
    double array[ROWS][COLS] = {
        {4.3, 5.2, 6.1, 7.0, 8.9},
        {1.2, 2.3, 3.4, 4.5, 5.6},
        {9.8, 8.7, 7.6, 6.5, 5.4}
    };
    int i, j;
    printf("Original array:\n");
    display_array(array, ROWS);
    mul2_array(array, ROWS);
    printf("\nMultiplied by 2:\n");
    display_array(array, ROWS);
}

static void display_array(const double ar[][COLS], int rows) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++)
            printf("%.1f ", ar[i][j]);
        putchar('\n');
    }
}

static void mul2_array(double ar[][COLS], int rows) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++)
            ar[i][j] *= 2;
    }
}