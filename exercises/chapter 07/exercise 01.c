#include <stdio.h>


void ch07_ex01(void) {
    char ch;
    int num_spaces = 0, num_newlines = 0, num_others = 0;

    printf("Enter text (# to exit):\n");

    while ((ch = (char) getchar()) != '#') {
        if (ch == ' ') {
            num_spaces++;
        } else if (ch == '\n') {
            num_newlines++;
        } else {
            num_others++;
        }
    }

    printf("You entered %d spaces, %d newlines and %d other characters.\n", num_spaces, num_newlines, num_others);
}
