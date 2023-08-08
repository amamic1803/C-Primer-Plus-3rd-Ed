#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256


void ch12_ex07(void) {
    FILE *fp;
    char words[MAX];
    char *new_line;
    int word_index;
    int lines_in_file = 0;
    char ch;
    int num_flag = 1;
    int i;
    int word_flag;
    int word_start;

    if ((fp = fopen("words.txt", "a+")) == NULL) {
        fprintf(stdout, "Can't open \"words.txt\" file.\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = (char) getc(fp)) != EOF)
        if (ch == '\n')
            lines_in_file++;
    word_index = lines_in_file + 1;
    rewind(fp);

    puts("Enter words to add to the file; press the Enter");
    puts("key at the beginning of a line to terminate.");
    while (fgets(words, MAX, stdin) != NULL && words[0] != '\n') {
        if ((new_line = strchr(words, '\n')) != NULL)
            *new_line = '\0';

        i = 0;
        word_flag = 0;
        while (words[i] != '\0') {
            if (isspace(words[i]) || words[i] == '\n') {
                if (word_flag) {
                    word_flag = 0;
                    ch = words[i];
                    words[i] = '\0';
                    fprintf(fp, "%d %s\n", word_index, words + word_start);
                    word_index++;
                    words[i] = ch;
                }
            } else {
                if (!word_flag) {
                    word_flag = 1;
                    word_start = i;
                }
            }
            i++;
        }
        if (word_flag) {
            fprintf(fp, "%d %s\n", word_index, words + word_start);
            word_index++;
        }
    }

    puts("File contents:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
        if (!num_flag) {
            puts(words);
            num_flag = 1;
        } else {
            num_flag = 0;
        }
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
}