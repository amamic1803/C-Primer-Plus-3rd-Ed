#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 101
#define SAVE_FILE "tv_shows.dat"


void ch16_ex04(void) {
    FILE *fp;
    char (*ptd)[STRLEN];
    int max;
    int number = 0;
    int i;
    int entered = 0;

    puts("What is the maximum number of string entries?");
    scanf("%d", &max);
    while (getchar() != '\n');
    ptd = (char (*)[STRLEN]) malloc(max * STRLEN * sizeof(char));
    if (ptd == NULL) {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(SAVE_FILE, "r+b")) == NULL) {
        if ((fp = fopen(SAVE_FILE, "wb")) == NULL) {
            fprintf(stderr, "Can't create %s file.\n", SAVE_FILE);
            exit(EXIT_FAILURE);
        }
    }
    while (number < max && fread(&ptd[number], STRLEN * sizeof(char), 1, fp) == 1)
        number++;

    if (number == max)
        puts("The file is full.");
    if (number != 0) {
        printf("Existing %d entries:\n", number);
        for (i = 0; i < number; i++)
            printf("%s\n", ptd[i]);
    }

    if (number < max)
        puts("\nEnter the values (empty line to quit):");
    while (number < max) {
        if ((fgets(ptd[number], STRLEN, stdin)) == NULL || ptd[number][0] == '\n')
            break;

        if (ptd[number][strlen(ptd[number]) - 1] == '\n')
            ptd[number][strlen(ptd[number]) - 1] = '\0';
        number++;
        entered = 1;
    }

    if (entered) {
        printf("\nHere are your %d entries:\n", number);
        for (i = 0; i < number; i++)
            printf("%s\n", ptd[i]);
    }

    rewind(fp);
    fwrite(ptd, STRLEN * sizeof(char), number, fp);

    free(ptd);
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file.\n");
        exit(EXIT_FAILURE);
    }
}