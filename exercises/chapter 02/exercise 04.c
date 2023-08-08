#include <stdio.h>
static void jolly(void);
static void final(void);


void ch02_ex04(void) {
    jolly();
    jolly();
    jolly();
    final();
}

static void jolly(void) {
    printf("For he's a jolly good fellow!\n");
}

static void final(void) {
    printf("Which nobody can deny!\n");
}
