#include <stdio.h>


void ch11_ex12(int argc, char **argv) {
    int i;
    for (i = argc - 1; i > 0; i--) {
        printf("%s", argv[i]);
        if (i > 1) {
            putchar(' ');
        }
    }
}