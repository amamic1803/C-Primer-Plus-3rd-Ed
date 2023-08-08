#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 30
#define MAX_FILENAME 256
static char int_to_char(int n);


void ch12_ex11(void) {
    char filename[MAX_FILENAME];
    char output_filename[MAX_FILENAME];
    int input_ints[ROWS][COLS];
    char input_chars[ROWS][COLS + 1];
    int i, j;
    FILE *fp;

    printf("Enter the name of the file to be processed: ");
    fflush(stdout);
    fgets(filename, MAX_FILENAME, stdin);
    if (filename[strlen(filename) - 1] == '\n')
        filename[strlen(filename) - 1] = '\0';

    printf("Enter the name of the output file: ");
    fflush(stdout);
    fgets(output_filename, MAX_FILENAME, stdin);
    if (output_filename[strlen(output_filename) - 1] == '\n')
        output_filename[strlen(output_filename) - 1] = '\0';

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Can't open %s file.\n", filename);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            fscanf(fp, "%d", &input_ints[i][j]);
            input_chars[i][j] = int_to_char(input_ints[i][j]);
        }
        input_chars[i][COLS] = '\0';
    }

    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file.\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(output_filename, "w")) == NULL) {
        fprintf(stderr, "Can't open %s file.\n", output_filename);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < ROWS; i++) {
        fprintf(stdout, "%s\n", input_chars[i]);
        fprintf(fp, "%s\n", input_chars[i]);
    }

    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file.\n");
        exit(EXIT_FAILURE);
    }
}

static char int_to_char(int n) {
    char c;
    switch (n) {
        case 0:
            c = ' ';
            break;
        case 1:
            c = '.';
            break;
        case 2:
            c = '\'';
            break;
        case 3:
            c = ':';
            break;
        case 4:
            c = '~';
            break;
        case 5:
            c = '*';
            break;
        case 6:
            c = '=';
            break;
        case 7:
            c = '}';
            break;
        case 8:
            c = '%';
            break;
        case 9:
            c = '#';
            break;
        default:
            c = '\0';
            break;
    }
    return c;
}