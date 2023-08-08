#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME 256


void ch12_ex08(void) {
    FILE *fp;
    char filename[MAX_FILENAME];
    int i;

    printf("Enter the name of the text file: ");
    fflush(stdout);
    fgets(filename, MAX_FILENAME, stdin);
    i = (int) strlen(filename) - 1;
    if (filename[i] == '\n')
        filename[i] = '\0';

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Enter the location in the file (non-numeric to quit): ");
    fflush(stdout);
    while (scanf("%d", &i) == 1) {
        fseek(fp, i, SEEK_SET);
        while ((i = getc(fp)) != EOF && i != '\n')
            putchar(i);
        putchar('\n');
        printf("Enter the location in the file (non-numeric to quit): ");
        fflush(stdout);
    }

    if (fclose(fp) != 0) {
        fprintf(stderr, "Can't close %s\n", filename);
        exit(EXIT_FAILURE);
    }
}