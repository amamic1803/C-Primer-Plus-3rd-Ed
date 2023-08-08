#include <stdio.h>
#include "header 01.h"


void ch16_ex01(void) {
    BOOLEAN a = TRUE;
    BOOLEAN b = FALSE;

    int val1 = 10, val2 = 20;

    if (a)
        printf("a is TRUE\n");
    if (b)
        printf("b is TRUE\n");

    printf("MAX(%d, %d) = %d\n", val1, val2, MAX(val1, val2));
    printf("MIN(%d, %d) = %d\n", val1, val2, MIN(val1, val2));
}