#include <ctype.h>
#include <stdio.h>


void ch11_ex11(void) {
    char ch;
    int word_flag = 0;
    int words = 0, uppercase = 0, lowercase = 0, punctuation = 0, digits = 0;

    puts("Enter text to analyze (EOF to terminate):");

    while ((ch = (char) getchar()) != EOF) {
        if (isalpha(ch)) {
            if (!word_flag) {
                word_flag = 1;
                words++;
            }
            if (isupper(ch)) {
                uppercase++;
            } else {
                lowercase++;
            }
        } else if (ispunct(ch)) {
            punctuation++;
        } else if (isdigit(ch)) {
            digits++;
        }

        if (word_flag && !isalpha(ch)) {
            word_flag = 0;
        }
    }

    printf("Analysis:\n");
    printf("Words: %d\n", words);
    printf("Uppercase letters: %d\n", uppercase);
    printf("Lowercase letters: %d\n", lowercase);
    printf("Punctuation characters: %d\n", punctuation);
    printf("Digits: %d\n", digits);
}