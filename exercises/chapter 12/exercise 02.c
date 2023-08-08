#include <stdio.h>
#include <stdlib.h>
static void print_file(FILE *fp);


void ch12_ex02(int argc, char **argv) {
    int i;
    FILE *fp;

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("Can't open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        print_file(fp);
        if (fclose(fp) != 0) {
            printf("Can't close %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }
}

static void print_file(FILE *fp) {
    int ch;

    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    putchar('\n');
}