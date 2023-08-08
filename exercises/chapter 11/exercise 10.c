#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 100
#define MAX_STR_NUM 10
static int load_strings(char **strings, int n);
static void print_strings(char **strings, int entered);
static void gets(char *str, int size);
static int get_first_word_len(char *string);
static void sort_by_ascii(char **strings, int entered);
static void sort_by_length(char **strings, int entered);
static void sort_by_first_word_length(char **strings, int entered);


void ch11_ex10(void) {
    char strings[MAX_STR_NUM][MAX_STR_LEN + 1];
    char *strings_ptrs_original[MAX_STR_NUM];
    char *strings_ptrs[MAX_STR_NUM];
    int i;
    int string_count;
    int input;
    char ch;

    for (i = 0; i < MAX_STR_NUM; ++i) {
        strings_ptrs_original[i] = strings[i];
        strings_ptrs[i] = strings[i];
    }

    string_count = load_strings(strings_ptrs, MAX_STR_NUM);

    printf("******************************************\n");
    printf("1) original list of strings\n");
    printf("2) strings in ASCII collating sequence\n");
    printf("3) strings ordered by length\n");
    printf("4) strings ordered by length of first word\n");
    printf("5) quit\n");
    printf("******************************************\n");
    putchar('>');
    putchar(' ');

    input = 0;
    while ((ch = (char) getchar()) != '\n') {
        if (input == 0 && 1 <= (ch - '0') && (ch - '0') <= 5) {
            input = ch - '0';
        }
    }

    while (1) {
        switch (input) {
            case 1: {
                print_strings(strings_ptrs_original, string_count);
                break;
            }
            case 2: {
                sort_by_ascii(strings_ptrs, string_count);
                print_strings(strings_ptrs, string_count);
                break;
            }
            case 3: {
                sort_by_length(strings_ptrs, string_count);
                print_strings(strings_ptrs, string_count);
                break;
            }
            case 4: {
                sort_by_first_word_length(strings_ptrs, string_count);
                print_strings(strings_ptrs, string_count);
                break;
            }
            case 5: {
                goto end;
            }
            default: {
                printf("Invalid input.\n");
                break;
            }
        }
        printf("******************************************\n");
        printf("1) original list of strings\n");
        printf("2) strings in ASCII collating sequence\n");
        printf("3) strings ordered by length\n");
        printf("4) strings ordered by length of first word\n");
        printf("5) quit\n");
        printf("******************************************\n");
        putchar('>');
        putchar(' ');

        input = 0;
        while ((ch = (char) getchar()) != '\n') {
            if (input == 0 && 1 <= (ch - '0') && (ch - '0') <= 5) {
                input = ch - '0';
            }
        }
    }
    end:;
}

static int load_strings(char **strings, int n_strings) {
    int i;
    puts("Enter strings (EOF to stop):");
    for (i = 0; i < n_strings; i++) {
        gets(strings[i], MAX_STR_LEN + 1);
        if (strchr(strings[i], EOF) != NULL) {
            i++;
            break;
        }
    }
    return i;
}

static void print_strings(char **strings, int entered) {
    int i;
    for (i = 0; i < entered; i++) {
        puts(strings[i]);
    }
}

static void gets(char *str, int size) {
    int i = 0;
    char ch;
    while ((ch = (char) getchar()) != '\n' && i < size - 1) {
        str[i++] = ch;
    }
    str[i] = '\0';
}

static int get_first_word_len(char *string) {
    char word[MAX_STR_LEN + 1];
    int i = 0;
    int count = 0;
    int word_flag = 0;
    int end_word_flag = 0;

    while (string[i] != '\0') {
        if (isalpha(string[i])) {
            if (word_flag == 0) {
                word_flag = 1;
            }
            if (!end_word_flag) {
                word[count++] = string[i];
            }
        } else {
            if (word_flag) {
                end_word_flag = 1;
            }
        }
        i++;
    }
    word[count] = '\0';
    return (int) strlen(word);
}

static void sort_by_ascii(char **strings, int entered) {
    int i, j;
    char *temp;
    for (i = 0; i < entered - 1; i++) {
        for (j = i + 1; j < entered; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

static void sort_by_length(char **strings, int entered) {
    int i, j;
    char *temp;
    for (i = 0; i < entered - 1; i++) {
        for (j = i + 1; j < entered; j++) {
            if (strlen(strings[i]) > strlen(strings[j])) {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

static void sort_by_first_word_length(char **strings, int entered) {
    int word_lens[MAX_STR_NUM];
    int i, j;
    int temp_int;
    char *temp_ch;

    for (i = 0; i < entered; i++) {
        word_lens[i] = get_first_word_len(strings[i]);
    }
    for (i = 0; i < entered - 1; i++) {
        for (j = i + 1; j < entered; j++) {
            if (word_lens[i] > word_lens[j]) {
                temp_int = word_lens[i];
                word_lens[i] = word_lens[j];
                word_lens[j] = temp_int;
                temp_ch = strings[i];
                strings[i] = strings[j];
                strings[j] = temp_ch;
            }
        }
    }
}