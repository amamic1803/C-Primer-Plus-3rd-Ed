#include <ctype.h>
#include <stdio.h>


void ch08_ex04(void) {
    int word_flag = 0;
    int word_count = 0;
    int letter_count = 0;
    char ch;

    printf("Enter text (EOF to quit):\n");

    while ((ch = (char) getchar()) != EOF) {
        if (word_flag) {
            if (isspace(ch) || ispunct(ch)) {
                word_flag = 0;
                word_count++;
            } else {
                letter_count++;
            }
        } else {
            if (!isspace(ch) && !ispunct(ch)) {
                word_flag = 1;
                letter_count++;
            }
        }
    }

    printf("Average number of letters per word is %.2lf\n", (double) letter_count / word_count);
}
