#include <stdio.h>
static void sum_diff(int * a, int * b);


void ch09_ex05(void) {
    int a = 5;
    int b = 3;
    printf("a = %d, b = %d\n", a, b);
    sum_diff(&a, &b);
    printf("a (sum) = %d, b (diff) = %d\n", a, b);
}

static void sum_diff(int * a, int * b){
    int temp = *a;
    *a += *b;
    *b = temp - *b;
}