#include <stdio.h>


void ch07_ex04(void) {
    int substitutions = 0;
    char ch;

    printf("Enter text (# to stop):\n");
    while ((ch = (char) getchar()) != '#') {
        if (ch == '.') {
            putchar('!');
            substitutions++;
        } else if (ch == '!') {
            printf("!!");
            substitutions++;
        } else {
            putchar(ch);
        }
    }

    printf("%d substitutions were performed.", substitutions);
}
