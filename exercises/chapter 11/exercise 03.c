#include <ctype.h>
#include <stdio.h>
#define MAX_WORD_LEN 100
static void load_word(char *word, int max);


void ch11_ex03(void) {
    char word[MAX_WORD_LEN + 1] = {'\0'};

    puts("Enter a line of text:");
    load_word(word, MAX_WORD_LEN);
    printf("The first word in the input is: %s\n", word);
}

static void load_word(char *word, int max) {
    int count = 0;
    int word_flag = 0;
    int end_word_flag = 0;
    char ch;

    while ((ch = (char) getchar()) != '\n' && ch != EOF) {
        if (isalpha(ch)) {
            if (word_flag == 0) {
                word_flag = 1;
            }
            if (!end_word_flag && count < max) {
                word[count++] = ch;
            }
        } else {
            if (word_flag) {
                end_word_flag = 1;
            }
        }
    }
    word[count] = '\0';
}