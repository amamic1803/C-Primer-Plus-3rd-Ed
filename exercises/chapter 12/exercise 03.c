#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
char temp[BUFSIZE];
static void append(FILE *source, FILE *dest);


void ch12_ex03(int argc, char **argv) {
    FILE *fa, *fs;
    int files = 0;
    int i;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s destination_file source_file1 source_file2 ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fa = fopen(argv[1], "a")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    for (i = 2; i < argc; i++) {
        if (strcmp(argv[1], argv[i]) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[i]);
        else {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", argv[i]);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", argv[1]);
            fclose(fs);
            files++;
            printf("File %s appended.\n", argv[i]);
        }
    }

    printf("Done appending. %d files appended.\n", files);
    fclose(fa);
}

static void append(FILE *source, FILE *dest) {
    size_t bytes;

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}