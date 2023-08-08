#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ch12_ex06(int argc, char **argv) {
    FILE *fp;
    char pattern;
    char ch;
    int count = 0;
    int i;

    if (argc < 2 || strlen(argv[1]) != 1) {
        printf("Usage: %s <character> <files>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pattern = argv[1][0];

    if (argc == 2) {
        while ((ch = (char) getchar()) != EOF) {
            if (ch == pattern)
                count++;
        }
        printf("The character %c appears %d times in stdin.\n", pattern, count);
    } else {
        for (i = 2; i < argc; i++) {
            if ((fp = fopen(argv[i], "r")) == NULL) {
                printf("Can't open %s\n", argv[i]);
            }
            count = 0;
            while ((ch = (char) getc(fp)) != EOF) {
                if (ch == pattern)
                    count++;
            }
            fclose(fp);
            printf("The character %c appears %d times in %s.\n", pattern, count, argv[i]);
        }
    }
}