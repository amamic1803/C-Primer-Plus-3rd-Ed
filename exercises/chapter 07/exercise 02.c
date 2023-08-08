#include <stdio.h>


void ch07_ex02(void) {
    char ch;
    int same_line;

    same_line = 0;
    printf("Enter text (# to exit):\n");
    while ((ch = (char) getchar()) != '#') {
        if (ch == '\n') {
            continue;
        }
        printf("%c=%d", ch, ch);
        same_line++;
        if (same_line == 8) {
            printf("\n");
            same_line = 0;
        } else {
            printf("  |  ");
        }
    }
}
