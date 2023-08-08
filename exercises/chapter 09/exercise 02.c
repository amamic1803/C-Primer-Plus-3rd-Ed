#include <stdio.h>
static void chline(char ch, int i, int j);


void ch09_ex02(void) {
    printf("Command: chline('a', 1, 5)\n");
    chline('a', 1, 5);
    printf("Command: chline('b', 3, 7)\n");
    chline('b', 3, 7);
    printf("Command: chline('c', 5, 9)\n");
    chline('c', 5, 9);
}

static void chline(char ch, int i, int j) {
    int k;
    for (k = 1; k < i; k++)
        putchar(' ');
    for (k = i; k <= j; k++)
        putchar(ch);
    putchar('\n');
}