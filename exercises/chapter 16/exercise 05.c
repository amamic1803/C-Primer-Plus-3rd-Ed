#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 255
#define SAVE_FILE "tv_shows.dat"
static void show_data(char *data, int cumulative_size);


void ch16_ex05(void) {
    FILE *fp;
    char temp_str[MAX_STR_LEN];
    char *ptd, *ptd2;
    char str_size;
    int cumulative_size = 0;
    int max;
    int number = 0;
    int i;
    int entered = 0;

    puts("What is the maximum number of string entries?");
    scanf("%d", &max);
    while (getchar() != '\n');
    if ((ptd = (char *) malloc(0)) == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(SAVE_FILE, "r+b")) == NULL) {
        if ((fp = fopen(SAVE_FILE, "wb")) == NULL) {
            fprintf(stderr, "Can't create %s file.\n", SAVE_FILE);
            exit(EXIT_FAILURE);
        }
    }
    while (number < max) {
        if (fread(&str_size, sizeof(char), 1, fp) != 1)
            break;
        cumulative_size += str_size + 1;

        if ((ptd2 = (char *) realloc(ptd, cumulative_size)) == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            free(ptd);
            exit(EXIT_FAILURE);
        }
        ptd = ptd2;

        *(ptd + cumulative_size - str_size - 1) = str_size;

        if (fread(ptd + cumulative_size - str_size, sizeof(char), str_size, fp) != str_size) {
            fprintf(stderr, "Error reading file.\n");
            free(ptd);
            exit(EXIT_FAILURE);
        }

        number++;
    }


    if (number == max)
        puts("The file is full.");
    if (number != 0) {
        printf("Existing %d entries:\n", number);
        show_data(ptd, cumulative_size);
    }

    if (number < max)
        puts("\nEnter the values (empty line to quit):");
    while (number < max) {
        if ((fgets(temp_str, MAX_STR_LEN, stdin)) == NULL || temp_str[0] == '\n')
            break;

        if (temp_str[strlen(temp_str) - 1] == '\n')
            temp_str[strlen(temp_str) - 1] = '\0';
        number++;
        entered = 1;

        cumulative_size += (int) strlen(temp_str) + 1 + 1;
        if ((ptd2 = (char *) realloc(ptd, cumulative_size)) == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            free(ptd);
            exit(EXIT_FAILURE);
        }
        ptd = ptd2;

        ptd[cumulative_size - strlen(temp_str) - 2] = (char) (strlen(temp_str) + 1);
        strcpy(ptd + cumulative_size - strlen(temp_str) - 1, temp_str);
    }

    if (entered) {
        printf("\nHere are your %d entries:\n", number);
        show_data(ptd, cumulative_size);
    }

    rewind(fp);
    fwrite(ptd, sizeof(char), cumulative_size, fp);

    free(ptd);
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file.\n");
        exit(EXIT_FAILURE);
    }
}

static void show_data(char *data, int cumulative_size) {
    char *pos = data + 1;

    while (pos - data < cumulative_size) {
        printf("%s\n", pos);
        pos += strlen(pos) + 2;
    }
}