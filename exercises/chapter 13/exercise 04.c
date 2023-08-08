#include <stdio.h>
static int times_called(void);


void ch13_ex04(void) {
    int i = 0;

    while (i < 10) {
        i = times_called();
        printf("Function times_called() called %d %s.\n", i, i == 1 ? "time" : "times");
    }
}

static int times_called(void) {
    static int count = 0;
    return ++count;
}