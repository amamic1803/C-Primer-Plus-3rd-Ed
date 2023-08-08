#include <ctype.h>
#include <stdio.h>
static int process_character(char ch);


void ch09_ex06(void) {
    char ch;
    int processing_result;

    printf("Enter text (EOF to exit):\n");

    while ((ch = (char) getchar()) != EOF) {
        processing_result = process_character(ch);
        ch != '\n' ? printf("Character \"%c\" is ", ch) : printf("Character \"\\n\" is ");
        if (processing_result == -1) {
            printf("not a letter.\n");
        } else {
            printf("a letter at location %d in the alphabet.\n", processing_result);
        }
    }
}

static int process_character(char ch) {
    int char_id;
    char_id = tolower(ch);
    if (isalpha(ch)) {
        return char_id - 'a' + 1;
    } else {
        return -1;
    }
}