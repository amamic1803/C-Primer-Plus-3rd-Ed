#include <stdio.h>
#include <stdlib.h>


void ch12_ex01(int argc, char **argv) {
    FILE *file_src;
    FILE *file_dst;
    size_t bytes_read;
    char buffer[1024];

    if (argc < 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((file_src = fopen(argv[1], "rb")) == NULL) {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((file_dst = fopen(argv[2], "wb")) == NULL) {
        printf("Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = fread(buffer, 1, 1024, file_src)) > 0) {
        fwrite(buffer, 1, bytes_read, file_dst);
    }

    if (fclose(file_src) != 0) {
        printf("Can't close %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (fclose(file_dst) != 0) {
        printf("Can't close %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    puts("Done copying file.");
}