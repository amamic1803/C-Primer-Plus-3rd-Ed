#include <ctype.h>
#include <stdio.h>
#include <string.h>
static void find_args(int argc, char **argv, int *p, int *u, int *l);


void ch11_ex15(int argc, char **argv) {
    int p = 0, u = 0, l = 0;
    char ch;

    find_args(argc, argv, &p, &u, &l);

    if (p + u + l == 0) {
        p = 1;
    } else if (p + u + l > 1) {
        printf("Invalid number of arguments.\n");
        return;
    }

    puts("Enter text (EOF to terminate):");
    while ((ch = (char) getchar()) != EOF) {
        if (p) {
            putchar(ch);
        } else if (u) {
            putchar((char) toupper(ch));
        } else if (l) {
            putchar((char) tolower(ch));
        }
    }
}

static void find_args(int argc, char **argv, int *p, int *u, int *l) {
    int i;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-p") == 0) {
            *p = 1;
        } else if (strcmp(argv[i], "-u") == 0) {
            *u = 1;
        } else if (strcmp(argv[i], "-l") == 0) {
            *l = 1;
        }
    }
}