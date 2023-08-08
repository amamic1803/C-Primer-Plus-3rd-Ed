#include <stdio.h>
#include <time.h>
#define SLEEP_TIME 5
static void sleep(double seconds);


void ch16_ex06(void) {
    printf("Sleeping for %d seconds...\n", SLEEP_TIME);
    sleep((double) SLEEP_TIME);
    printf("Done!\n");
}

static void sleep(double seconds) {
    clock_t start = clock();
    while (((double) (clock() - start) / (double) CLOCKS_PER_SEC) < seconds);
}