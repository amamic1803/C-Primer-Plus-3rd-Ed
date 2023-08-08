#include <stdio.h>
#define ROWS 3
#define COLS 5
static void store_data(double (*ptr)[COLS], int rows);
static void average_sets(const double (*ptr)[COLS], double *save, int rows);
static double average_all(const double (*ptr)[COLS], int rows);
static double largest_all(const double (*ptr)[COLS], int rows);
static void report_results(const double (*ptr)[COLS], int rows, const double *average_sets_val, double average_all_val, double largest_all_val);


void ch10_ex11(void) {
    double data[ROWS][COLS];
    double average_sets_val[ROWS];
    double average_all_val;
    double largest_all_val;

    store_data(data, ROWS);
    average_sets(data, average_sets_val, ROWS);
    average_all_val = average_all(data, ROWS);
    largest_all_val = largest_all(data, ROWS);
    report_results(data, ROWS, average_sets_val, average_all_val, largest_all_val);
}

static void store_data(double (*ptr)[COLS], int rows) {
    int i, j;

    for (i = 1; i <= rows; i++) {
        printf("Enter %d numbers for set %d:\n", COLS, i);
        for (j = 0; j < COLS; j++)
            scanf("%lf", *(ptr + i - 1) + j);
    }
}

static void average_sets(const double (*ptr)[COLS], double *save, int rows) {
    int i, j;
    double sum;

    for (i = 0; i <= rows; i++) {
        sum = 0;
        for (j = 0; j < COLS; j++)
            sum += *(*(ptr + i) + j);
        *(save + i) = sum / COLS;
    }
}

static double average_all(const double (*ptr)[COLS], int rows) {
    int i, j;
    double sum = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++)
            sum += *(*(ptr + i) + j);
    }
    return sum / (rows * COLS);
}

static double largest_all(const double (*ptr)[COLS], int rows) {
    int i, j;
    double largest;

    largest = *(*(ptr + 0) + 0);
    for (i = 0; i <= rows; i++) {
        for (j = 0; j < COLS; j++)
            if (*(*(ptr + i) + j) > largest)
                largest = *(*(ptr + i) + j);
    }

    return largest;
}

static void report_results(const double (*ptr)[COLS], int rows, const double *average_sets_val, double average_all_val, double largest_all_val) {
    int i, j;

    printf("\nEntered data:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++)
            printf("%5.1f ", ptr[i][j]);
        putchar('\n');
    }

    for (i = 0; i < rows; i++) {
        printf("The average of set %d is %.2f.\n", i + 1, *(average_sets_val + i));
    }

    printf("The average of all data is %.2f.\n", average_all_val);
    printf("The largest number in all of data is %.2f.\n", largest_all_val);
}