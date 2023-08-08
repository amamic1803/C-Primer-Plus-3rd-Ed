#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 30
#define MAX_FILENAME 256
static char int_to_char(int n);
static void deglitch(int original[ROWS][COLS], int deglitched[ROWS][COLS]);


void ch12_ex12(void) {
    char filename[MAX_FILENAME];
    char output_filename[MAX_FILENAME];
    int input_ints[ROWS][COLS];
    int input_ints_deglitched[ROWS][COLS];
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
        }
    }

    deglitch(input_ints, input_ints_deglitched);

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            input_chars[i][j] = int_to_char(input_ints_deglitched[i][j]);
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

static void deglitch(int original[ROWS][COLS], int deglitched[ROWS][COLS]) {
    int i, j;

    for (i = 1; i < (ROWS - 1); i++) {
        for (j = 1; j < (COLS - 1); j++) {
            if (abs(original[i][j] - original[i - 1][j]) > 1 &&
                abs(original[i][j] - original[i + 1][j]) > 1 &&
                abs(original[i][j] - original[i][j - 1]) > 1 &&
                abs(original[i][j] - original[i][j + 1]) > 1) {
                deglitched[i][j] = (int) roundf((float) (original[i - 1][j] + original[i + 1][j] +
                                    original[i][j - 1] + original[i][j + 1]) / (float) 4);
            } else {
                deglitched[i][j] = original[i][j];
            }
        }
    }

    for (i = 1; i < (ROWS - 1); i++) {
        if (abs(original[i][0] - original[i - 1][0]) > 1 &&
            abs(original[i][0] - original[i + 1][0]) > 1 &&
            abs(original[i][0] - original[i][1]) > 1) {
            deglitched[i][0] = (int) roundf((float) (original[i - 1][0] + original[i + 1][0] +
                                original[i][1]) / (float) 3);
        } else {
            deglitched[i][0] = original[i][0];
        }
    }

    for (i = 1; i < (ROWS - 1); i++) {
        if (abs(original[i][COLS - 1] - original[i - 1][COLS - 1]) > 1 &&
            abs(original[i][COLS - 1] - original[i + 1][COLS - 1]) > 1 &&
            abs(original[i][COLS - 1] - original[i][COLS - 2]) > 1) {
            deglitched[i][COLS - 1] = (int) roundf((float) (original[i - 1][COLS - 1] + original[i + 1][COLS - 1] +
                                original[i][COLS - 2]) / (float) 3);
        } else {
            deglitched[i][COLS - 1] = original[i][COLS - 1];
        }
    }

    for (j = 1; j < (COLS - 1); j++) {
        if (abs(original[0][j] - original[0][j - 1]) > 1 &&
            abs(original[0][j] - original[0][j + 1]) > 1 &&
            abs(original[0][j] - original[1][j]) > 1) {
            deglitched[0][j] = (int) roundf((float) (original[0][j - 1] + original[0][j + 1] +
                                original[1][j]) / (float) 3);
        } else {
            deglitched[0][j] = original[0][j];
        }
    }

    for (j = 1; j < (COLS - 1); j++) {
        if (abs(original[ROWS - 1][j] - original[ROWS - 1][j - 1]) > 1 &&
            abs(original[ROWS - 1][j] - original[ROWS - 1][j + 1]) > 1 &&
            abs(original[ROWS - 1][j] - original[ROWS - 2][j]) > 1) {
            deglitched[ROWS - 1][j] = (int) roundf((float) (original[ROWS - 1][j - 1] + original[ROWS - 1][j + 1] +
                                original[ROWS - 2][j]) / (float) 3);
        } else {
            deglitched[ROWS - 1][j] = original[ROWS - 1][j];
        }
    }

    if (abs(original[0][0] - original[0][1]) > 1 &&
        abs(original[0][0] - original[1][0]) > 1) {
        deglitched[0][0] = (int) roundf((float) (original[0][1] + original[1][0]) / (float) 2);
    } else {
        deglitched[0][0] = original[0][0];
    }

    if (abs(original[0][COLS - 1] - original[0][COLS - 2]) > 1 &&
        abs(original[0][COLS - 1] - original[1][COLS - 1]) > 1) {
        deglitched[0][COLS - 1] = (int) roundf((float) (original[0][COLS - 2] + original[1][COLS - 1]) / (float) 2);
    } else {
        deglitched[0][COLS - 1] = original[0][COLS - 1];
    }

    if (abs(original[ROWS - 1][0] - original[ROWS - 1][1]) > 1 &&
        abs(original[ROWS - 1][0] - original[ROWS - 2][0]) > 1) {
        deglitched[ROWS - 1][0] = (int) roundf((float) (original[ROWS - 1][1] + original[ROWS - 2][0]) / (float) 2);
    } else {
        deglitched[ROWS - 1][0] = original[ROWS - 1][0];
    }

    if (abs(original[ROWS - 1][COLS - 1] - original[ROWS - 1][COLS - 2]) > 1 &&
        abs(original[ROWS - 1][COLS - 1] - original[ROWS - 2][COLS - 1]) > 1) {
        deglitched[ROWS - 1][COLS - 1] = (int) roundf((float) (original[ROWS - 1][COLS - 2] + original[ROWS - 2][COLS - 1]) / (float) 2);
    } else {
        deglitched[ROWS - 1][COLS - 1] = original[ROWS - 1][COLS - 1];
    }
}
