#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME_LENGTH 256
static void print_word(FILE *fp);


void ch12_ex10(void) {
    FILE *fp;
    char filename[MAX_FILENAME_LENGTH + 1];
    int i;

    printf("Enter a file name: ");
    fflush(stdout);
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    i = (int) strlen(filename) - 1;
    if (filename[i] == '\n')
        filename[i] = '\0';

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    print_word(fp);

    if (fclose(fp) != 0) {
        printf("Can't close %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

static void print_word(FILE *fp) {
    int i;
    int word_flag = 0;

    while (1) {
        i = getc(fp);
        if (i == ' ' || i == '\n' || i == '\t') {
            if (word_flag == 1) {
                putchar('\n');
                ungetc(i, fp);
                break;
            }
        } else {
            word_flag = 1;
            putchar(i);
        }
    }
}