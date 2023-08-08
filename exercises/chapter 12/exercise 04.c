#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ch12_ex04(void) {
    FILE *in, *out;
    int ch;
    char name[45];
    int count = 0;

    printf("Enter the name of the file to be processed: ");
    fflush(stdout);
    scanf("%40s", name);

    if ((in = fopen(name, "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", name);
        exit(EXIT_FAILURE);
    }

    strcat(name, ".red");

    if ((out = fopen(name, "w")) == NULL) {
        fprintf(stderr, "Can't create output file.\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(in)) != EOF) {
        if (count++ % 3 == 0) {
            putc(ch, out);
        }
    }
    if (fclose(in) != 0 || fclose(out) != 0) {
        fprintf(stderr, "Error in closing files\n");
    }
}