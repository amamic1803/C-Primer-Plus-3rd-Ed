#include <stdio.h>
#include <string.h>
#define MAX_WORD_SIZE 100
#define MAX_WORDS 20
static void sort_strings(char **string_ptrs, int num_strings);


void ch13_ex08(void) {
    char words[MAX_WORDS][MAX_WORD_SIZE + 1];
    char *words_ptrs[MAX_WORDS];
    int i, word_count = 0;

    printf("Enter words (to stop, type #):\n");
    for (i = 0; i < MAX_WORDS; i++) {
        scanf("%s", words[i]);
        if (strchr(words[i], '#') != NULL) {
            break;
        }
        word_count++;
    }
    for (i = 0; i < word_count; i++) {
        words_ptrs[i] = &words[i][0];
    }

    sort_strings(words_ptrs, word_count);

    printf("Here are your words (sorted):\n");
    for (i = 0; i < word_count; i++) {
        printf("%s\n", words_ptrs[i]);
    }
}

static void sort_strings(char **string_ptrs, int num_strings) {
    int i, j;
    char *temp;

    for (i = 0; i < num_strings - 1; i++) {
        for (j = i + 1; j < num_strings; j++) {
            if (strcmp(string_ptrs[i], string_ptrs[j]) > 0) {
                temp = string_ptrs[i];
                string_ptrs[i] = string_ptrs[j];
                string_ptrs[j] = temp;
            }
        }
    }
}
