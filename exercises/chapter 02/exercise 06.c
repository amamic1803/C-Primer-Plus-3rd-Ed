#include <stdio.h>
static void smile(void);


void ch02_ex06(void) {
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
    printf("\n");
}

static void smile(void) {
    printf("Smile!");
}