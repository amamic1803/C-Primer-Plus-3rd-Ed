#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256
#define NAMES 10
static long double extract_average(const char *word);
static void sort(char **strings, int num_strings);


void ch13_ex11(void) {
    FILE *fp;
    char filename[MAX_LINE];
    char names[NAMES][MAX_LINE];
    char *names_ptrs[NAMES];
    int i;

    puts("Enter the name of the file to be read:");
    fgets(filename, MAX_LINE, stdin);
    if (filename[strlen(filename) - 1] == '\n')
        filename[strlen(filename) - 1] = '\0';

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        return;
    }

    for (i = 0; i < NAMES; i++) {
        fgets(names[i], MAX_LINE, fp);
        if (names[i][strlen(names[i]) - 1] == '\n')
            names[i][strlen(names[i]) - 1] = '\0';
        names_ptrs[i] = names[i];
    }

    sort(names_ptrs, NAMES);

    for (i = 0; i < NAMES; i++)
        printf("%-30s|%6.2Lf\n", names_ptrs[i], extract_average(names_ptrs[i]));

    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file\n");
        exit(EXIT_FAILURE);
    }
}

static long double extract_average(const char *word) {
    int num_flag = 0;
    int read_nums = 0;
    int sum = 0;
    int curr_num;
    int i = 0;

    while (word[i++] != ':');
    while (read_nums < 3) {
        if (isdigit(word[i])) {
            if (!num_flag) {
                num_flag = 1;
                curr_num = word[i] - '0';
            } else {
                curr_num = curr_num * 10 + word[i] - '0';
            }
        } else {
            if (num_flag) {
                sum += curr_num;
                read_nums++;
                num_flag = 0;
            }
        }
        i++;
    }

    return ((long double) sum / (long double) 3);
}

static void sort(char **strings, int num_strings) {
    int i, j;
    char *temp;

    for (i = 0; i < num_strings - 1; i++) {
        for (j = i + 1; j < num_strings; j++) {
            if (extract_average(strings[i]) > extract_average(strings[j])) {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}