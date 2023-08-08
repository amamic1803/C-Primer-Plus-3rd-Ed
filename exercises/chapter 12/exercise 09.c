#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 256


void ch12_ex09(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE_LENGTH + 1];
    int newline;

    if (argc != 3) {
        printf("Usage: %s <string> <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[2], "r")) == NULL) {
        printf("Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        if (strstr(line, argv[1]) != NULL) {
            newline = (int) strlen(line) - 1;
            if (line[newline] != '\n') {
                line[newline + 1] = '\n';
                line[newline + 2] = '\0';
            }
            printf("%s", line);
        }
    }

    if (fclose(fp) != 0) {
        printf("Can't close %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
}