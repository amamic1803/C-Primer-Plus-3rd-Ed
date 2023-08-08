#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 256


void ch12_ex05(int argc, char **argv) {
    FILE *fp1, *fp2;
    char line[MAX_LINE_LENGTH + 1];
    int changes = 1;
    int line_len;
    char *newline_pos;
    int second_null = 0;

    if (argc < 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL) {
        printf("Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("Print lines from both files alternatively:\n");
    while (changes) {
        changes = 0;
        if (fgets(line, MAX_LINE_LENGTH, fp1) != NULL) {
            line_len = (int) strlen(line);
            if (line[line_len - 1] != '\n') {
                line[line_len] = '\n';
                line[line_len + 1] = '\0';
            }
            fputs(line, stdout);
            changes = 1;
        }
        if (fgets(line, MAX_LINE_LENGTH, fp2) != NULL) {
            line_len = (int) strlen(line);
            if (line[line_len - 1] != '\n') {
                line[line_len] = '\n';
                line[line_len + 1] = '\0';
            }
            fputs(line, stdout);
            changes = 1;
        }
    }

    rewind(fp1);
    rewind(fp2);

    printf("\nPrint lines from both files side by side:\n");
    changes = 1;
    while (changes) {
        changes = 0;

        if (fgets(line, MAX_LINE_LENGTH, fp1) != NULL) {
            if ((newline_pos = strchr(line, '\n')) != NULL)
                *newline_pos = '\0';
            fputs(line, stdout);
            changes = 1;
        }
        if (fgets(line, MAX_LINE_LENGTH, fp2) != NULL) {
            line_len = (int) strlen(line);
            if (line[line_len - 1] != '\n') {
                line[line_len] = '\n';
                line[line_len + 1] = '\0';
            }
            changes = 1;
            second_null = 0;
        } else {
            second_null = 1;
        }

        if (changes) {
            printf("   |   ");
            fputs(line, stdout);
            if (second_null)
                putchar('\n');
        }
    }

    fclose(fp1);
    fclose(fp2);
}